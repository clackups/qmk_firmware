/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

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

#pragma once

#include "quantum.h"

enum custom_keycodes {
    RF_DFU = QK_KB_0,
    LNK_USB,
    LNK_RF,
    LNK_BLE1,
    LNK_BLE2,
    LNK_BLE3,

    MAC_VOICE, // F5
    MAC_DND,
    TASK,      // KC_CALC
    SEARCH,    // KC_LCTL + KC_F
    PRT_SCR,   // PrintScreen
    PRT_AREA,  // PrintScreen

    SIDE_VAI,
    SIDE_VAD,
    SIDE_MOD,
    SIDE_HUI,
    SIDE_SPI,
    SIDE_SPD,
    SIDE_1,

    DEV_RESET,
    SLEEP_MODE,
    BAT_SHOW,
    BAT_NUM,
    RGB_TEST,
    NUMLOCK_INS,
    NUMLOCK_IND,
    SLEEP_NOW,
    GAME_MODE,
    CAPS_WORD,
    WIN_LOCK,

    DEBOUNCE_I,
    DEBOUNCE_D,
    DEBOUNCE_T,

    SLEEP_I,
    SLEEP_D,

    SOCD_TOG
};
