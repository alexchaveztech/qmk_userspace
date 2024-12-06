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

#ifdef VIA_ENABLE
#    define DYNAMIC_KEYMAP_LAYER_COUNT 9
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/** Configure the global tapping term (default: 200ms) & combo term
 *  disable double tap repeat in favor of efficient home row mod */

#define QUICK_TAP_TERM 0
#define COMBO_TERM 50
#ifndef TAPPING_TERM
#    define TAPPING_TERM 130
#endif // TAPPING_TERM

/** Dilemma-specific features. */
// disable tracbad scroll gestures as it causes unresponsive tracpad
#undef POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#ifdef POINTING_DEVICE_ENABLE
// Flip horizontal direction for drag-scroll.
#    define DILEMMA_DRAGSCROLL_REVERSE_X
// #define DILEMMA_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE
