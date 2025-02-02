/*
Asymetric per-key algorithm. After pressing a key, it immediately changes state,
with no further inputs accepted until DEBOUNCE milliseconds have occurred. After
releasing a key, that state is pushed after no changes occur for DEBOUNCE milliseconds.
*/

#include "debounce.h"
#include "timer.h"
#include <stdlib.h>
#include "user_kb.h"

#ifdef PROTOCOL_CHIBIOS
#    if CH_CFG_USE_MEMCORE == FALSE
#        error ChibiOS is configured without a memory allocator. Your keyboard may have set `#define CH_CFG_USE_MEMCORE FALSE`, which is incompatible with this debounce algorithm.
#    endif
#endif

#define ROW_SHIFTER ((matrix_row_t)1)
#define DEBOUNCE_ELAPSED 0

typedef struct {
    bool    pressed : 1;
    uint8_t time : 7;
} debounce_counter_t;

static debounce_counter_t *debounce_counters;
static fast_timer_t        last_time;
static bool                counters_need_update;
static bool                matrix_need_update;
static bool                cooked_changed;

static void update_debounce_counters_and_transfer_if_expired(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, uint8_t elapsed_time);
static void update_debounce_counters(uint8_t num_rows, uint8_t elapsed_time);
static void transfer_matrix_values(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows);

void early_user_debouce_init(void) {
    if (user_config.init_layer < 100) {
        user_config.debounce_type = 1;
        user_config.debounce_ms = DEBOUNCE;
    }
}

// we use num_rows rather than MATRIX_ROWS to support split keyboards
void debounce_init(uint8_t num_rows) {
    uint8_t max_counters = num_rows * MATRIX_COLS;
    early_user_debouce_init();

    debounce_counters = malloc(max_counters * sizeof(debounce_counter_t));

    for (uint8_t i = 0; i < max_counters; i++) {
        debounce_counters[i].time = DEBOUNCE_ELAPSED;
    }
}

void debounce_free(void) {
    free(debounce_counters);
    debounce_counters = NULL;
}

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    bool updated_last = false;
    cooked_changed    = false;

    if (counters_need_update) {
        fast_timer_t now          = timer_read_fast();
        fast_timer_t elapsed_time = TIMER_DIFF_FAST(now, last_time);

        last_time    = now;
        updated_last = true;
        if (elapsed_time > UINT8_MAX) {
            elapsed_time = UINT8_MAX;
        }

        if (elapsed_time > 0) {
            if (user_config.debounce_type == 2) {
                update_debounce_counters(num_rows, elapsed_time);
            } else {
                update_debounce_counters_and_transfer_if_expired(raw, cooked, num_rows, elapsed_time);
            }
        }
    }

    if (changed || matrix_need_update) {
        if (!updated_last) {
            last_time = timer_read_fast();
        }

        transfer_matrix_values(raw, cooked, num_rows);
    }

    return cooked_changed;
}

// If the current time is > debounce counter, set the counter to enable input.
static void update_debounce_counters(uint8_t num_rows, uint8_t elapsed_time) {
    counters_need_update                 = false;
    matrix_need_update                   = false;
    debounce_counter_t *debounce_pointer = debounce_counters;
    for (uint8_t row = 0; row < num_rows; row++) {
        if (debounce_pointer->time != DEBOUNCE_ELAPSED) {
            if (debounce_pointer->time <= elapsed_time) {
                debounce_pointer->time  = DEBOUNCE_ELAPSED;
                matrix_need_update = true;
            } else {
                debounce_pointer->time -= elapsed_time;
                counters_need_update = true;
            }
        }
        debounce_pointer++;
    }
}

static void update_debounce_counters_and_transfer_if_expired(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, uint8_t elapsed_time) {
    debounce_counter_t *debounce_pointer = debounce_counters;

    counters_need_update = false;
    matrix_need_update   = false;

    for (uint8_t row = 0; row < num_rows; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            matrix_row_t col_mask = (ROW_SHIFTER << col);

            if (debounce_pointer->time != DEBOUNCE_ELAPSED) {
                if (debounce_pointer->time <= elapsed_time) {
                    debounce_pointer->time = DEBOUNCE_ELAPSED;

                    if (debounce_pointer->pressed && user_config.debounce_type) {
                        // key-down: eager
                        matrix_need_update = true;
                    } else {
                        // key-up: defer
                        matrix_row_t cooked_next = (cooked[row] & ~col_mask) | (raw[row] & col_mask);
                        cooked_changed |= cooked_next ^ cooked[row];
                        cooked[row] = cooked_next;
                    }
                } else {
                    debounce_pointer->time -= elapsed_time;
                    counters_need_update = true;
                }
            }
            debounce_pointer++;
        }
    }
}

static void transfer_matrix_values(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows) {
    debounce_counter_t *debounce_pointer = debounce_counters;
    matrix_need_update = false;

    for (uint8_t row = 0; row < num_rows; row++) {
        if (user_config.debounce_type == 2) {
            matrix_row_t existing_row = cooked[row];
            matrix_row_t raw_row      = raw[row];

            // determine new value basd on debounce pointer + raw value
            if (existing_row != raw_row) {
                if (debounce_pointer->time == DEBOUNCE_ELAPSED) {
                    debounce_pointer->time = user_config.debounce_ms;
                    cooked_changed |= cooked[row] ^ raw_row;
                    cooked[row]          = raw_row;
                    counters_need_update = true;
                }
            }
            debounce_pointer++;
            continue;
        }

        matrix_row_t delta = raw[row] ^ cooked[row];
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            matrix_row_t col_mask = (ROW_SHIFTER << col);

            if (delta & col_mask) {
                if (debounce_pointer->time == DEBOUNCE_ELAPSED) {
                    debounce_pointer->pressed = (raw[row] & col_mask);
                    debounce_pointer->time    = user_config.debounce_ms;
                    counters_need_update      = true;

                    if (debounce_pointer->pressed && user_config.debounce_type) {
                        // key-down: eager
                        cooked[row] ^= col_mask;
                        cooked_changed = true;
                    }
                }
            } else if (debounce_pointer->time != DEBOUNCE_ELAPSED) {
                if (user_config.debounce_type == 0) {
                    debounce_pointer->time = DEBOUNCE_ELAPSED;
                } else if (!debounce_pointer->pressed) {
                    // key-up: defer
                    debounce_pointer->time = DEBOUNCE_ELAPSED;
                }
            }
            debounce_pointer++;
        }
    }
}
