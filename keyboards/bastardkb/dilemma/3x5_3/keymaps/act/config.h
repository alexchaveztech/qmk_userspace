/**
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

/* Establish maximum number of layers and state for more efficient use of memory size */
#define LAYER_STATE_8BIT
#define COMBO_COUNT 1

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

/* Establish handedness to swap to left use MASTER_RIGHT */
// #define MASTER_LEFT
#define MASTER_RIGHT

#ifdef VIA_ENABLE
/* Via configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 10
#endif // VIA_ENABLE

/**
 * Configure the global tapping term (default: 200ms).
 * If you have a lot of accidental mod activations, crank up the tapping term.
 */
#define COMBO_TERM 50
#ifndef TAPPING_TERM
#    define TAPPING_TERM 110
#endif // TAPPING_TERM

/* Disable unused features. */
#define NO_ACTION_ONESHOT

// disable trackpad taps
// #define CIRQUE_PINNACLE_TAPPING_TERM 0
#undef POINTING_DEVICE_GESTURES_SCROLL_ENABLE
/**
 * Enable rapid switch from tap to hold.  Disable auto-repeat when pressing key
 * twice, except for one-shot keys.
 */

/*
 * Tap-or-Hold decision modes.
 *
 * Note that the following flags behave differently when combined (ie. when 2 or
 * more are enabled).
 *
 * See bit.ly/tap-or-hold for a visual explanation of the following tap-or-hold
 * decision modes.
 */

/**
 * Faster tap-hold trigger.
 *
 * Without `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ ae
 * With `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ Mod+e
 */
// #define PERMISSIVE_HOLD

/** Dilemma-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Flip horizontal direction for drag-scroll.
#    define DILEMMA_DRAGSCROLL_REVERSE_X
// #define DILEMMA_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE
