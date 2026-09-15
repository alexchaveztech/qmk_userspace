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
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LYR_BSE = 0,
    LYR_ALT,
    LYR_EXT,
    LYR_FUN,
    LYR_SYM,
    LYR_NUM,
    LYR_MED,
    LYR_NAV,
};
// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LYR_SYM

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

//Combo to switch to switch BASE (Canary), ALT Gallium, replaced GAM Game (Qwerty Modified)
const uint16_t PROGMEM lyr_base_combo[] = {KC_G, KC_L, COMBO_END};
const uint16_t PROGMEM lyr_alt_combo[] = {KC_G, KC_R, COMBO_END};
combo_t key_combos[] = {
    COMBO(lyr_base_combo, DF(LYR_BSE)),
    COMBO(lyr_alt_combo, DF(LYR_ALT)),
};

#define ESC_FUN LT(LYR_FUN, KC_ESC)
#define TAB_NUM LT(LYR_NUM, KC_TAB)
#define SPC_SYM LT(LYR_SYM, KC_SPC)
#define ENT_MED LT(LYR_MED, KC_ENT)
#define ENT_NUF LT(LYR_NUF, KC_ENT)
#define BSP_NAV LT(LYR_NAV, KC_BSPC)

// Define clipboard behavior. Current = Windows
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define DPI_RMOD KC_NO
#    define S_D_MOD KC_NO
#    define S_D_RMOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
// Define row alias for ease of reference
#define _______________BOOT_LOADER_L_______________ XXXXXXX, XXXXXXX,  QK_RBT,  EE_CLR, QK_BOOT
#define _______________BOOT_LOADER_R_______________ QK_BOOT,  EE_CLR,  QK_RBT, XXXXXXX, XXXXXXX
#define ________________MOUSE_DPI_L________________ DPI_RMOD,DPI_MOD,S_D_RMOD, S_D_MOD, XXXXXXX
#define ________________MOUSE_DPI_R________________ XXXXXXX, S_D_MOD,S_D_RMOD, DPI_MOD,DPI_RMOD
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_RGUI

#define LAYOUT_LYR_BSE                                                                        \
       KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,    KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT, \
       KC_C,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_A, \
       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    KC_X,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_FUN, SPC_SYM, TAB_NUM, ENT_MED, BSP_NAV
#define LAYOUT_LYR_ALT                                                                        \
       KC_B,    KC_L,    KC_D,    KC_C,    KC_V,    KC_J,    KC_Y,    KC_O,    KC_U, KC_QUOT, \
       KC_N,    KC_R,    KC_T,    KC_S,    KC_G,    KC_P,    KC_H,    KC_A,    KC_E,    KC_I, \
       KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,    KC_K,    KC_F, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_FUN, SPC_SYM, TAB_NUM, ENT_MED, BSP_NAV
/**
#defineefine LAYOUT_LYR_GAM                                                                        \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      KC_LCTL, KC_LALT, KC_LSFT, ENT_EXT, BSP_NAV
*/
#define LAYOUT_LYR_EXT                                                                        \
       KC_1,   KC_F7,   KC_F8,   KC_F9,    KC_4, _______________BOOT_LOADER_R_______________, \
       KC_2,   KC_F4,   KC_F5,   KC_F6,    KC_5, ________________MOUSE_DPI_R________________, \
       KC_3,   KC_F1,   KC_F2,   KC_F3,    KC_6, ______________HOME_ROW_GACS_R______________, \
                       KC_ESC,  KC_SPC,  KC_TAB, _______, XXXXXXX
#define LAYOUT_LYR_FUN                                                                        \
    _______________BOOT_LOADER_L_______________, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12, \
    ________________MOUSE_DPI_L________________, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11, \
    ______________HOME_ROW_GACS_L______________, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, \
                      _______, XXXXXXX, XXXXXXX,  KC_ENT, KC_DEL
#define LAYOUT_LYR_SYM                                                                        \
    _______________BOOT_LOADER_L_______________, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, \
    KC_WBAK, MS_BTN2, DRGSCRL, MS_BTN1, KC_WFWD, KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, \
    ______________HOME_ROW_GACS_L______________, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, \
                      XXXXXXX, _______, XXXXXXX, KC_UNDS, KC_RPRN
#define LAYOUT_LYR_NUM                                                                        \
    _______________BOOT_LOADER_L_______________, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, \
    ________________MOUSE_DPI_L________________,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, \
    ______________HOME_ROW_GACS_L______________, KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, \
                      XXXXXXX, XXXXXXX, _______,  KC_MINS,    KC_0
#define LAYOUT_LYR_MED                                                                        \
    _______________BOOT_LOADER_L_______________, _______________BOOT_LOADER_R_______________, \
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, ________________MOUSE_DPI_R________________, \
    RM_VALU, RM_VALD, RM_NEXT,RM_PREV, RM_TOGG, ______________HOME_ROW_GACS_R______________, \
                      KC_MUTE, KC_MPLY, KC_MSTP, _______, XXXXXXX
#define LAYOUT_LYR_NAV                                                                        \
    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, _______________BOOT_LOADER_R_______________, \
    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS, KC_WFWD, MS_BTN1, DRGSCRL, MS_BTN2, KC_WBAK, \
      U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO, ______________HOME_ROW_GACS_R______________, \
                       KC_ESC,  KC_APP,  KC_TAB, XXXXXXX, _______

#define _HOME_ROW_MOD_GACS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
      LGUI_T(L20), LALT_T(L21), LCTL_T(L22), LSFT_T(L23),        L24,  \
             R25,  RSFT_T(R26), RCTL_T(R27), LALT_T(R28), RGUI_T(R29), \
      __VA_ARGS__
#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BSE] = LAYOUT_wrapper(HOME_ROW_MOD_GACS(LAYOUT_LYR_BSE)),
  [LYR_ALT] = LAYOUT_wrapper(HOME_ROW_MOD_GACS(LAYOUT_LYR_ALT)),
  [LYR_EXT] = LAYOUT_wrapper(LAYOUT_LYR_EXT),
  [LYR_FUN] = LAYOUT_wrapper(LAYOUT_LYR_FUN),
  [LYR_SYM] = LAYOUT_wrapper(LAYOUT_LYR_SYM),
  [LYR_NUM] = LAYOUT_wrapper(LAYOUT_LYR_NUM),
  [LYR_MED] = LAYOUT_wrapper(LAYOUT_LYR_MED),
  [LYR_NAV] = LAYOUT_wrapper(LAYOUT_LYR_NAV),
};
// clang-format on

