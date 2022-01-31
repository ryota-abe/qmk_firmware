/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "keymap_jp.h"

#define MO1_ESC LT(1, KC_ESC)
#define MO2_ENT LT(2, KC_ENT)
#define MO3_ARR LT(3, ARROW)
#define PREVTAB C(KC_PGUP)
#define NEXTTAB C(KC_PGDN)

enum my_keycodes {
    ZEN_HAN = SAFE_RANGE,
    NEXTTSK,
    PREVTSK,
    ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO3_ARR,  KC_SPC, KC_LCTL,    KC_LSFT, MO2_ENT, MO1_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_VOLU, XXXXXXX, KC_MS_U, KC_BTN2, KC_WH_U,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, DM_PLY1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_BTN1, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_PLUS,  KC_EQL, KC_LBRC, KC_RBRC, KC_PIPE,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_COMM,  KC_DOT, KC_LCBR, KC_RCBR, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,C(KC_SPC),_______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, PREVTAB, PREVTSK, NEXTTSK, NEXTTAB,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  KC_DEL, XXXXXXX,  KC_INS,KC_LANG2,                     KC_LANG1, ZEN_HAN, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

void oled_render_layer_state(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("BASE "), layer_state_is(0));
    oled_write_P(PSTR("LOWER"), layer_state_is(1));
    oled_write_P(PSTR("RAISE"), layer_state_is(2));
    oled_write_P(PSTR("ADJST"), layer_state_is(3));
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("Mods "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("-----"), false);
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
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d  k%4x%c    ",
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
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
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

bool shift_physically_pressing;

void change_keycode_to(uint16_t keycode, bool pressed) {
    bool shift_needed = keycode & QK_LSFT;
    bool add_shift = shift_needed && !(shift_physically_pressing);
    bool del_shift = !shift_needed && (shift_physically_pressing);

    if (pressed) {
        if (add_shift) { register_code(KC_LSFT); }
        if (del_shift) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
        }
        register_code(keycode);
        unregister_code(keycode);
        if (add_shift) { unregister_code(KC_LSFT); }
        if (del_shift) {
            if (shift_physically_pressing) { register_code(KC_LSFT); }
        }
    }
}

bool jp_to_us(uint16_t keycode, bool pressed) {
    bool mod_shift = (get_mods() & MOD_MASK_SHIFT) || (get_oneshot_mods() & MOD_MASK_SHIFT);
    switch (keycode | (mod_shift ? QK_LSFT : 0)) {
        case KC_AT:   change_keycode_to(JP_AT,   pressed); return true;
        case KC_CIRC: change_keycode_to(JP_CIRC, pressed); return true;
        case KC_AMPR: change_keycode_to(JP_AMPR, pressed); return true;
        case KC_ASTR: change_keycode_to(JP_ASTR, pressed); return true;
        case KC_LPRN: change_keycode_to(JP_LPRN, pressed); return true;
        case KC_RPRN: change_keycode_to(JP_RPRN, pressed); return true;
        case KC_PIPE: change_keycode_to(JP_PIPE, pressed); return true;
        case KC_PLUS: change_keycode_to(JP_PLUS, pressed); return true;
        case KC_EQL:  change_keycode_to(JP_EQL,  pressed); return true;
        case KC_LBRC: change_keycode_to(JP_LBRC, pressed); return true;
        case KC_RBRC: change_keycode_to(JP_RBRC, pressed); return true;
        case KC_LCBR: change_keycode_to(JP_LCBR, pressed); return true;
        case KC_RCBR: change_keycode_to(JP_RCBR, pressed); return true;
        case KC_BSLS: change_keycode_to(JP_BSLS, pressed); return true;
        case KC_UNDS: change_keycode_to(JP_UNDS, pressed); return true;
        case KC_COLN: change_keycode_to(JP_COLN, pressed); return true;
        case KC_SCLN: change_keycode_to(JP_SCLN, pressed); return true;
        case KC_QUOT: change_keycode_to(JP_QUOT, pressed); return true;
        case KC_DQUO: change_keycode_to(JP_DQUO, pressed); return true;
        case KC_GRV:  change_keycode_to(JP_GRV,  pressed); return true;
        case KC_TILD: change_keycode_to(JP_TILD, pressed); return true;
        case ZEN_HAN: change_keycode_to(JP_ZKHK, pressed); return true;
    }
    return false;
}

bool process_task_switching(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NEXTTSK:
            if (record->event.pressed) {
                register_mods(MOD_MASK_ALT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return true;
        case PREVTSK:
            if (record->event.pressed) {
                register_mods(MOD_MASK_ALT);
                register_mods(MOD_MASK_SHIFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_mods(MOD_MASK_SHIFT);
            }
            return true;
        case MO3_ARR:
            if (!record->event.pressed) {
                unregister_mods(MOD_MASK_ALT);
                unregister_mods(MOD_MASK_SHIFT);
            }
            break;
    }
    return false;
}

uint16_t last_pressed_keycode;
uint16_t last_pressed_time;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_pressed_keycode = keycode;
        last_pressed_time = record->event.time;
        set_keylog(keycode, record);
    }

    if (jp_to_us(keycode, record->event.pressed)) {
        return false;
    }

    if (process_task_switching(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_LSFT:
            shift_physically_pressing = record->event.pressed;
            break;
        case MO3_ARR:
            if (record->event.pressed) {
                layer_on(3);
            } else {
                if (last_pressed_keycode == MO3_ARR && timer_elapsed(last_pressed_time) < TAPPING_TERM) {
                    jp_to_us(KC_EQL, true);
                    jp_to_us(KC_EQL, false);
                    SEND_STRING(">");
                }
                layer_off(3);
            }
            return false;
    }

    return true;
}
