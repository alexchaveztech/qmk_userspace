#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LYR_BSE = 0,
    LYR_ALT,
    LYR_TAP,
    LYR_NAV,
    LYR_NUM,
    LYR_NUF,
    LYR_SYM,
    LYR_FUN,
    LYR_MED,
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LYR_NAV
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

//Combo to switch to switch BASE (Canary), ALT (Qwerty), TAP Game (Qwerty)
const uint16_t PROGMEM g_q_combo[] = {KC_G, KC_Q, COMBO_END};
const uint16_t PROGMEM g_w_combo[] = {KC_G, KC_W, COMBO_END};
const uint16_t PROGMEM g_l_combo[] = {KC_G, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(g_q_combo, DF(LYR_BSE)),
    COMBO(g_w_combo, DF(LYR_ALT)),
    COMBO(g_l_combo, DF(LYR_TAP)),
};

#define ESC_FUN LT(LYR_FUN, KC_ESC)
#define TAB_NUM LT(LYR_NUM, KC_TAB)
#define SPC_SYM LT(LYR_SYM, KC_SPC)
#define ENT_MED LT(LYR_MED, KC_ENT)
#define ENT_NUF LT(LYR_NUF, KC_ENT)
#define BSP_NAV LT(LYR_NAV, KC_BSPC)
#define _L_PTR(KC) LT(LYR_NAV, KC)

// Define clipboard behavior. Current = Windows //
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

/** Row alias. */
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
       KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,    KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT, \
       KC_C,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_A, \
       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    KC_X,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_FUN, SPC_SYM, TAB_NUM, ENT_MED, BSP_NAV
#define LAYOUT_LYR_TAP                                                                        \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_BTN1, DRGSCRL, KC_BTN2, KC_BTN3, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      KC_LCTL, KC_LALT,  KC_SPC, ENT_NUF, BSP_NAV
#define LAYOUT_LYR_NAV                                                                        \
    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS, _______________BOOT_LOADER_R_______________, \
    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, CW_TOGG, KC_WFWD, KC_BTN1, DRGSCRL, KC_BTN2, KC_WBAK, \
      U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO, ______________HOME_ROW_GACS_R______________, \
                       KC_ESC,  KC_APP,  KC_TAB, XXXXXXX, _______
#define LAYOUT_LYR_NUM                                                                        \
    _______________BOOT_LOADER_L_______________, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, \
    ________________MOUSE_DPI_L________________,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, \
    ______________HOME_ROW_GACS_L______________, KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, \
                      XXXXXXX, _______, XXXXXXX, KC_MINS,    KC_0
#define LAYOUT_LYR_NUF                                                                        \
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, _______________BOOT_LOADER_R_______________, \
    KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL, ________________MOUSE_DPI_R________________, \
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, ______________HOME_ROW_GACS_R______________, \
                         KC_J,    KC_K,    KC_L, _______, XXXXXXX
#define LAYOUT_LYR_SYM                                                                        \
    _______________BOOT_LOADER_L_______________, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, \
    KC_WBAK, KC_BTN2, DRGSCRL, KC_BTN1, KC_WFWD, KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, \
    ______________HOME_ROW_GACS_L______________, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, \
                      XXXXXXX, XXXXXXX, _______, KC_UNDS, KC_RPRN
#define LAYOUT_LYR_FUN                                                                        \
    _______________BOOT_LOADER_L_______________, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12, \
    ________________MOUSE_DPI_L________________, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11, \
    ______________HOME_ROW_GACS_L______________, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, \
                      _______, XXXXXXX, XXXXXXX,  KC_ENT, KC_DEL
#define LAYOUT_LYR_MED                                                                        \
    _______________BOOT_LOADER_L_______________, _______________BOOT_LOADER_R_______________, \
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, ________________MOUSE_DPI_R________________, \
    RGB_VAI, RGB_VAD, RGB_MOD,RGB_RMOD, RGB_TOG, ______________HOME_ROW_GACS_R______________, \
                      KC_MUTE, KC_MPLY, KC_MSTP, _______, XXXXXXX

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

#define _POINTER_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      _L_PTR(L10),        L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,  _L_PTR(R19), \
             L20,         L21,         L22,         L23,         L24,  \
             R25,         R26,         R27,         R28,         R29, \
      __VA_ARGS__
#define POINTER_MOD(...) _POINTER_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BSE] = LAYOUT_wrapper(POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LYR_BSE))),
  [LYR_ALT] = LAYOUT_wrapper(POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LYR_ALT))),
  [LYR_TAP] = LAYOUT_wrapper(LAYOUT_LYR_TAP),
  [LYR_NAV] = LAYOUT_wrapper(LAYOUT_LYR_NAV),
  [LYR_NUM] = LAYOUT_wrapper(LAYOUT_LYR_NUM),
  [LYR_NUF] = LAYOUT_wrapper(LAYOUT_LYR_NUF),
  [LYR_SYM] = LAYOUT_wrapper(LAYOUT_LYR_SYM),
  [LYR_FUN] = LAYOUT_wrapper(LAYOUT_LYR_FUN),
  [LYR_MED] = LAYOUT_wrapper(LAYOUT_LYR_MED),
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LYR_NAV);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LYR_NAV);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
