/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Establish maximum number of layers and state tfor more efficient use of memory size */
#define LAYER_STATE_8BIT
#define MAX_LAYER 9
#define COMBO_COUNT 1

/* Disabled features for efficient use of memory size */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Establish handedness to swap to left use MASTER_RIGHT */
// #define MASTER_LEFT
#define MASTER_RIGHT

#define USE_SERIAL_PD2

/* Establish timing for combo and tapping specifically affecting homerow mod */
#define COMBO_TERM 20
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD

/* Establish moure keys addeleration */
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8

/* RGB Configuration */
#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"


