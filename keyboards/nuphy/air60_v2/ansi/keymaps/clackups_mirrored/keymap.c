/*
Copyright 2023 @ Nuphy <https://nuphy.com/>
Copyright 2024 clackups

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "ansi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer 0 Mac
[0] = LAYOUT_60_ansi(
        QK_GESC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_BSPC,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           LT(11,KC_T),    KC_Y,           LT(11,KC_U),    KC_I,           KC_O,           KC_P,           KC_LBRC,        KC_RBRC,        KC_BSLS,
        KC_CAPS,        KC_A,           KC_S,           KC_D,           LT(1,KC_F),     KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                        KC_ENT,
        OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        OSM(MOD_RSFT),  KC_UP,          KC_DEL,
        OSM(MOD_LCTL),  OSM(MOD_LALT),  KC_LGUI,                                                        LT(7,KC_SPC),                                   KC_RGUI,        MO(1),          KC_LEFT,        KC_DOWN,        KC_RGHT),

// layer 1 Mac fn
[1] = LAYOUT_60_ansi(
        KC_GRV,         KC_BRID,        KC_BRIU,        TASK,           SEARCH,         MAC_VOICE,      MAC_DND,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_VOLD,        KC_VOLU,        XXXXXXX,
        XXXXXXX,        LNK_BLE1,       LNK_BLE2,       LNK_BLE3,       LNK_RF,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        DEV_RESET,      SLEEP_MODE,     BAT_SHOW,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        MO(2),          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        MO(6),          RGB_SPD,        RGB_SPI,        XXXXXXX,        MO(2),          RGB_VAI,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        RGB_MOD,        RGB_VAD,        RGB_HUI),

// layer 2 Mac Fn+shift
[2] = LAYOUT_60_ansi(
        XXXXXXX,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        RGB_TEST,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX),

// layer 3 Win
[3] = LAYOUT_60_ansi(
        QK_GESC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_BSPC,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           LT(11,KC_T),    KC_Y,           LT(11,KC_U),    KC_I,           KC_O,           KC_P,           KC_LBRC,        KC_RBRC,        KC_BSLS,
        KC_CAPS,        KC_A,           KC_S,           KC_D,           LT(4,KC_F),     KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                        KC_ENT,
        OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        OSM(MOD_RSFT),  KC_UP,          KC_DEL,
        OSM(MOD_LCTL),  KC_LGUI,        OSM(MOD_LALT),                                                  LT(9,KC_SPC),                                   OSM(MOD_RALT),  MO(4),          KC_LEFT,        KC_DOWN,        KC_RGHT),

// layer 4 win fn
[4] = LAYOUT_60_ansi(
        KC_GRV,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         XXXXXXX,
        XXXXXXX,        LNK_BLE1,       LNK_BLE2,       LNK_BLE3,       LNK_RF,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        DEV_RESET,      SLEEP_MODE,     BAT_SHOW,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        MO(5),          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        MO(6),          RGB_SPD,        RGB_SPI,        XXXXXXX,        MO(5),          RGB_VAI,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        RGB_MOD,        RGB_VAD,        RGB_HUI),

// layer 5 win fn+shift
[5] = LAYOUT_60_ansi(
        XXXXXXX,        KC_BRID,        KC_BRIU,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_VOLD,        KC_VOLU,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        RGB_TEST,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX),

// layer 6 function
[6] = LAYOUT_60_ansi(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        SIDE_SPD,       SIDE_SPI,       XXXXXXX,        XXXXXXX,        SIDE_VAI,       XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        SIDE_MOD,       SIDE_VAD,       SIDE_HUI),

// layer 7 Mac Mirrored
[7] = LAYOUT_60_ansi(
        XXXXXXX,        KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           XXXXXXX,        DF(8),           QK_GESC,
        DF(8),          KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,           KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           XXXXXXX,        XXXXXXX,         KC_NUBS,
        KC_ENT,         KC_SCLN,        KC_L,           KC_K,           KC_J,           KC_H,           KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           XXXXXXX,                         XXXXXXX,
        XXXXXXX,        KC_SLSH,        KC_DOT,         KC_COMM,        KC_M,           KC_N,           KC_B,           KC_V,           KC_C,           KC_X,           KC_Z,           XXXXXXX,        XXXXXXX,         XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX),

// layer 8 Mac cursor movement
[8] = LAYOUT_60_ansi(
        LALT(LCTL(KC_DEL)),  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,             XXXXXXX,        KC_UP,          XXXXXXX,        KC_PGUP,        KC_BTN1,        KC_MS_U,        KC_BTN2,        KC_WH_U,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,             KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_PGDN,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_WH_D,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        XXXXXXX,             XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_L,        XXXXXXX,        KC_WH_R,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_UP,          XXXXXXX,
        XXXXXXX,             XXXXXXX,        XXXXXXX,                                                        DF(0),                                          XXXXXXX,        XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RGHT),

// layer 9 Win Mirrored
[9] = LAYOUT_60_ansi(
        XXXXXXX,        KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           XXXXXXX,        DF(10),          QK_GESC,
        DF(10),         KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,           KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           XXXXXXX,        XXXXXXX,         KC_NUBS,
        KC_ENT,         KC_SCLN,        KC_L,           KC_K,           KC_J,           KC_H,           KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           XXXXXXX,                         XXXXXXX,
        XXXXXXX,        KC_SLSH,        KC_DOT,         KC_COMM,        KC_M,           KC_N,           KC_B,           KC_V,           KC_C,           KC_X,           KC_Z,           XXXXXXX,        XXXXXXX,         XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX),

// layer 10 Win cursor movement
[10] = LAYOUT_60_ansi(
        LALT(LCTL(KC_DEL)),  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,             XXXXXXX,        KC_UP,          XXXXXXX,        KC_PGUP,        KC_BTN1,        KC_MS_U,        KC_BTN2,        KC_WH_U,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,             KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_PGDN,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_WH_D,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,
        XXXXXXX,             XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_L,        XXXXXXX,        KC_WH_R,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_UP,          XXXXXXX,
        XXXXXXX,             XXXXXXX,        XXXXXXX,                                                        DF(3),                                          XXXXXXX,        XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RGHT),

// layer 11 Win+Mac punctuation for left hand, ins-del-home-end-pgupdn
[11] = LAYOUT_60_ansi(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_BSLS,        KC_RBRC,        KC_LBRC,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_QUOT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        KC_TAB,
        XXXXXXX,        KC_NUBS,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_INS,         KC_HOME,        KC_PGUP,
        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        KC_DEL,         KC_END,         KC_PGDN)
};





const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    {0, A_16,   B_16,   C_16},      // "Esc"
    {0, A_2,    B_2,    C_2},       // "!1"
    {0, A_3,    B_3,    C_3},       // "@2"
    {0, A_4,    B_4,    C_4},       // "#3"
    {0, A_5,    B_5,    C_5},       // "$4"
    {0, A_6,    B_6,    C_6},       // "%5"
    {0, A_7,    B_7,    C_7},       // "^6"
    {0, A_8,    B_8,    C_8},       // "&7"
    {0, A_9,    B_9,    C_9},       // "*8"
    {0, A_10,   B_10,   C_10},      // "(9"
    {0, A_11,   B_11,   C_11},      // ")0"
    {1, D_1,    E_1,    F_1},       // "_-"
    {1, D_2,    E_2,    F_2},       // "+="
    {1, D_3,    E_3,    F_3},       // "Backsp"
    {0, D_1,    E_1,    F_1},       // "Tab"
    {0, D_2,    E_2,    F_2},       // "Q"
    {0, D_3,    E_3,    F_3},       // "W"
    {0, D_4,    E_4,    F_4},       // "E"
    {0, D_5,    E_5,    F_5},       // "R"
    {0, D_6,    E_6,    F_6},       // "T"
    {0, D_7,    E_7,    F_7},       // "Y"
    {0, D_8,    E_8,    F_8},       // "U"
    {0, D_9,    E_9,    F_9},       // "I"
    {0, D_10,   E_10,   F_10},      // "O"
    {0, D_11,   E_11,   F_11},      // "P"
    {1, G_1,    H_1,    I_1},       // "{["
    {1, G_2,    H_2,    I_2},       // "}]"
    {1, G_3,    H_3,    I_3},       // "|\\"
    {0, G_1,    H_1,    I_1},       // "Caps"
    {0, G_2,    H_2,    I_2},       // "A"
    {0, G_3,    H_3,    I_3},       // "S"
    {0, G_4,    H_4,    I_4},       // "D"
    {0, G_5,    H_5,    I_5},       // "F"
    {0, G_6,    H_6,    I_6},       // "G"
    {0, G_7,    H_7,    I_7},       // "H"
    {0, G_8,    H_8,    I_8},       // "J"
    {0, G_9,    H_9,    I_9},       // "K"
    {0, G_10,   H_10,   I_10},      // "L"
    {0, G_11,   H_11,   I_11},      // ":"
    {1, G_16,   H_16,   I_16},      // "\""
    {1, G_14,   H_14,   I_14},      // "Enter"
    {0, J_1,    K_1,    L_1},       // "Shift"
    {0, J_3,    K_3,    L_3},       // "Z"
    {0, J_4,    K_4,    L_4},       // "X"
    {0, J_5,    K_5,    L_5},       // "C"
    {0, J_6,    K_6,    L_6},       // "V"
    {0, J_7,    K_7,    L_7},       // "B"
    {0, J_8,    K_8,    L_8},       // "N"
    {0, J_9,    K_9,    L_9},       // "M"
    {0, J_10,   K_10,   L_10},      // "<,"
    {0, J_11,   K_11,   L_11},      // ">."
    {1, J_1,    K_1,    L_1},       // "?/"
    {1, J_3,    K_3,    L_3},       // "Shift"
    {1, J_4,    K_4,    L_4},       // "↑"
    {1, G_4,    H_4,    I_4},       // "Del"
    {0, J_16,   K_16,   L_16},      // "Ctrl"
    {0, J_15,   K_15,   L_15},      // "Opt"
    {0, J_14,   K_14,   L_14},      // "Cmd"
    {0, J_13,   K_13,   L_13},      // "Space"
    {0, J_12,   K_12,   L_12},      // "Cmd"
    {1, J_16,   K_16,   L_16},      // "Fn"
    {1, J_13,   K_13,   L_13},      // "←"
    {1, J_12,   K_12,   L_12},      // "↓"
    {1, J_11,   K_11,   L_11},      // "→"

    {1, A_5,    B_5,    C_5},       // logo left
    {1, A_4,    B_4,    C_4},       //
    {1, A_3,    B_3,    C_3},       //
    {1, A_2,    B_2,    C_2},       //
    {1, A_1,    B_1,    C_1},       //

    {1, A_6,    B_6,    C_6},       // logo right
    {1, A_7,    B_7,    C_7},       //
    {1, A_8,    B_8,    C_8},       //
    {1, A_9,    B_9,    C_9},       //
    {1, A_10,   B_10,   C_10}       //
};
