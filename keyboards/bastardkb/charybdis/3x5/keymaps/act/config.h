/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

/* Establish handedness to swap to left use MASTER_RIGHT */
// #define MASTER_LEFT
#define MASTER_RIGHT


#ifdef VIA_ENABLE
/* VIA configuration. */
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

/* Charybdis-specific features. */

/** Auto pointer layer when moving the trackball. Off after 1 second. Trigger sense 8
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
*/

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
