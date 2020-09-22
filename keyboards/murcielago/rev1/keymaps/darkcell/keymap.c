#include QMK_KEYBOARD_H

enum layers {
    BASE,
    _NAV,
    _SYM,
    _FN
};

// Custom definitions for shorter keycodes
#define PRE_WRD LCTL(KC_LEFT)  // jump to next word
#define NXT_WRD LCTL(KC_RGHT)  // jump to previous word
#define NXT_WDL LCTL(KC_DEL)   // delete next word
#define PRE_WDL LCTL(KC_BSPC)  // delete previous word
#define MO_NAV MO(_NAV) // NAV layer access
#define MO_SYM MO(_SYM) // SYM layer access
#define OSL_FN OSL(_FN) // FN layer access
#define CTL_ESC LCTL_T(KC_ESC) // Tap Escape, hold CTRL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Layer Template
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//               └────────┴────────┴────────┴────────┴────────┘             └────────┴────────┴────────┴────────┴────────┘


  [BASE] = LAYOUT(
// QWERTY Default Layer
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OSL_FN,       KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
//  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                  KC_LGUI, KC_LALT, MO_SYM,  KC_SPC,  KC_ENT,                KC_BSPC,  KC_SPC, MO_NAV,  KC_RALT, KC_RGUI
//               └────────┴────────┴────────┴────────┴────────┘             └────────┴────────┴────────┴────────┴────────┘

  ),

  [_NAV] = LAYOUT(
// NAV - navigation layer
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, PRE_WRD, KC_UP,   NXT_WRD, XXXXXXX, KC_PGUP,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,                        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , KC_PGDN,
//  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,      _______, XXXXXXX, PRE_WDL, KC_INS,  NXT_WDL, XXXXXXX, _______,
//  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                  _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______
//               └────────┴────────┴────────┴────────┴────────┘             └────────┴────────┴────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
// SYM - symbols and numpad layer
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS,                        XXXXXXX, KC_LPRN, KC_LPRN, XXXXXXX, XXXXXXX, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,                        XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSLS, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PENT,                        XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
//  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                  _______, KC_P0,   _______, _______, _______,               _______, _______, _______, _______, _______
//               └────────┴────────┴────────┴────────┴────────┘             └────────┴────────┴────────┴────────┴────────┘
  ),

  // FN - one-shot access to F-keys with modifiers

  [_FN] = LAYOUT(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
    S(KC_F12),S(KC_F1),S(KC_F2),S(KC_F3),S(KC_F4),S(KC_F5),                       S(KC_F6),S(KC_F7),S(KC_F8),S(KC_F9),S(KC_F10),S(KC_F11),
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    C(KC_F12),C(KC_F1),C(KC_F2),C(KC_F3),C(KC_F4),C(KC_F5),                       C(KC_F6),C(KC_F7),C(KC_F8),C(KC_F9),C(KC_F10),C(KC_F11),
//  ├────────┼────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    A(KC_F12),A(KC_F1),A(KC_F2),A(KC_F3),A(KC_F4),A(KC_F5),                       A(KC_F6),A(KC_F7),A(KC_F8),A(KC_F9),A(KC_F10),A(KC_F11),
//  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘    └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                  _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______
//               └────────┴────────┴────────┴────────┴────────┘             └────────┴────────┴────────┴────────┴────────┘
  )
};
