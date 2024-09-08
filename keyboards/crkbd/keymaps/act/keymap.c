#include QMK_KEYBOARD_H

// Layer declaration
  enum layer_names {

    LYR_BSE = 0,
    LYR_ALT,
    LYR_TAP,
    LYR_MED,
    LYR_NAV,
    LYR_NUM,
    LYR_NUF,
    LYR_SYM,
    LYR_FUN,
    LYR_MSE,
};

//Combo to switch to switch BASE (Canary), ALT (ColemakDH), TAP Game (Qwerty)
const uint16_t PROGMEM g_q_combo[] = {KC_G, KC_Q, COMBO_END};
const uint16_t PROGMEM g_w_combo[] = {KC_G, KC_W, COMBO_END};
const uint16_t PROGMEM g_l_combo[] = {KC_G, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(g_q_combo, DF(LYR_BSE)),
    COMBO(g_w_combo, DF(LYR_ALT)),
    COMBO(g_l_combo, DF(LYR_TAP)),
};

#define ESC_MED LT(LYR_MED, KC_ESC)
#define TAB_NUM LT(LYR_NUM, KC_TAB)
#define SPC_NAV LT(LYR_NAV, KC_SPC)
#define ENT_SYM LT(LYR_SYM, KC_ENT)
#define ENT_NUF LT(LYR_NUF, KC_ENT)
#define BSP_FUN LT(LYR_FUN, KC_BSPC)

// Define clipboard behavior. Current = Windows //
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

/** Row alias. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI

#define LAYOUT_LYR_BSE                                                                        \
       KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,    KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT, \
       KC_C,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_A, \
       KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    KC_X,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_MED, SPC_NAV, TAB_NUM, ENT_SYM, BSP_FUN, KC_DEL

#define LAYOUT_LYR_ALT                                                                        \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_MED, SPC_NAV, TAB_NUM, ENT_SYM, BSP_FUN, KC_DEL

#define LAYOUT_LYR_TAP                                                                        \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_BTN1, XXXXXXX, KC_BTN2, KC_BTN3, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      KC_LCTL, KC_LALT,  KC_SPC, ENT_NUF, BSP_FUN, KC_DEL

#define LAYOUT_LYR_MED                                                                        \
    _______________DEAD_HALF_ROW_______________, QK_BOOT,  EE_CLR,  QK_RBT, XXXXXXX, XXXXXXX, \
    KC_WBAK, KC_BTN2, XXXXXXX, KC_BTN1, KC_WFWD, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
    ______________HOME_ROW_GACS_L______________, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, \
                      _______, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, XXXXXXX

#define LAYOUT_LYR_NAV                                                                         \
    _______________DEAD_HALF_ROW_______________,  KC_INS, KC_HOME, KC_PGDN, KC_PGUP,   KC_END, \
    KC_WBAK, KC_BTN2, XXXXXXX, KC_BTN1, KC_WFWD, CW_TOGG, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, \
    ______________HOME_ROW_GACS_L______________,   U_RDO,   U_PST,   U_CPY,   U_CUT,    U_UND, \
                      XXXXXXX, _______, XXXXXXX,  KC_ENT,  KC_DEL, XXXXXXX

#define LAYOUT_LYR_NUM                                                                        \
    _______________DEAD_HALF_ROW_______________, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, \
    _______________DEAD_HALF_ROW_______________,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, \
    ______________HOME_ROW_GACS_L______________, KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, \
                      XXXXXXX, XXXXXXX, _______, KC_MINS,    KC_0, KC_DOT

#define LAYOUT_LYR_NUF                                                                        \
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, _______________DEAD_HALF_ROW_______________, \
     KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, _______________DEAD_HALF_ROW_______________, \
    KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, ______________HOME_ROW_GACS_R______________, \
                         KC_J,    KC_K,    KC_L,_______, XXXXXXX, XXXXXXX

#define LAYOUT_LYR_SYM                                                                        \
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______________DEAD_HALF_ROW_______________, \
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, _______________DEAD_HALF_ROW_______________, \
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, ______________HOME_ROW_GACS_R______________, \
                      KC_UNDS, KC_LPRN, KC_RPRN, _______, XXXXXXX, XXXXXXX


#define LAYOUT_LYR_FUN                                                                        \
    KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_PSCR, _______________DEAD_HALF_ROW_______________, \
    KC_F11,   KC_F5,   KC_F5,   KC_F6,  KC_SCRL, _______________DEAD_HALF_ROW_______________, \
    KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_PAUS, ______________HOME_ROW_GACS_R______________, \
                      KC_ESC,  KC_APP,   KC_TAB,  XXXXXXX, _______, XXXXXXX

#define LAYOUT_LYR_MSE                                                                        \
    _______________DEAD_HALF_ROW_______________, QK_BOOT,  EE_CLR,  QK_RBT, _______, _______, \
    KC_WBAK, KC_BTN2, XXXXXXX, KC_BTN1, KC_WFWD, XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX, \
    ______________HOME_ROW_GACS_L______________, ______________HOME_ROW_GACS_R______________, \
                      _______, _______, _______, KC_BTN3, KC_BTN1, XXXXXXX

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

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BSE] = LAYOUT_wrapper(HOME_ROW_MOD_GACS(LAYOUT_LYR_BSE)),
  [LYR_ALT] = LAYOUT_wrapper(HOME_ROW_MOD_GACS(LAYOUT_LYR_ALT)),
  [LYR_TAP] = LAYOUT_wrapper(LAYOUT_LYR_TAP),
  [LYR_MED] = LAYOUT_wrapper(LAYOUT_LYR_MED),
  [LYR_NAV] = LAYOUT_wrapper(LAYOUT_LYR_NAV),
  [LYR_NUM] = LAYOUT_wrapper(LAYOUT_LYR_NUM),
  [LYR_NUF] = LAYOUT_wrapper(LAYOUT_LYR_NUF),
  [LYR_SYM] = LAYOUT_wrapper(LAYOUT_LYR_SYM),
  [LYR_FUN] = LAYOUT_wrapper(LAYOUT_LYR_FUN),
  [LYR_MSE] = LAYOUT_wrapper(LAYOUT_LYR_MSE),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
	// Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case LYR_BSE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case LYR_ALT:
            oled_write_ln_P(PSTR("Alternate"), false);
            break;
        case LYR_TAP:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case LYR_NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case LYR_NAV:
            oled_write_ln_P(PSTR("Navigate"), false);
            break;
        case LYR_SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case LYR_NUF:
            oled_write_ln_P(PSTR("NumFun"), false);
            break;
        case LYR_FUN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case LYR_MSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    //break;
	}
    	// Host Keyboard LED Status
	led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE


