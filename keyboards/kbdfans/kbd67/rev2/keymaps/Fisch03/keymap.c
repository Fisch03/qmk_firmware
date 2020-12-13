/* Copyright 2018 'mechmerlin'
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
#include KEYMAP_GERMAN_H

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  ß| ´ |Backsp |Pscr|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  Ü| +|      |Ins |
   * |-----------------------------------------------------┐Enter|----|
   * |Caps    |  A|  S|  D|  F|  G|  H|  J|  K|  L| Ö| Ä| #|     |Del |
   * |----------------------------------------------------------------|
   * |Shift| <|  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  -|Alt Gr| Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          | fn|App|    |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_65_iso(
  KC_ESC,       DE_1,    DE_2,   DE_3,   DE_4,   DE_5,   DE_6,   DE_7,   DE_8,    DE_9,    DE_0,    DE_SS,  DE_ACUT,  KC_BSPC, KC_PSCR, \
  KC_TAB,       DE_Q,    DE_W,   DE_E,   DE_R,   DE_T,   DE_Z,   DE_U,   DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,          KC_INS,  \
  KC_CAPS,      DE_A,    DE_S,   DE_D,   DE_F,   DE_G,   DE_H,   DE_J,   DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH  KC_ENT,  KC_DEL,  \
  KC_LSFT,DE_LABK,DE_Y,  DE_X,   DE_C,   DE_V,   DE_B,   DE_N,   DE_M,   DE_COMM, DE_DOT,  DE_MINS,  KC_RALT,      KC_UP,      KC_END,  \
  KC_LCTL,  KC_LGUI, KC_LALT,                KC_SPC,                  LT(1, KC_LEAD),   KC_APP,  KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * | ^ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * |     |   |VOL+|PLY|   |   |   |   |   |   |   |  |  |      |    |
   * |-----------------------------------------------------┐     |----|
   * |        |PRV|VOL-|NXT|   |   |   |   |   |  |  |  |  |     |    |
   * |----------------------------------------------------------------|
   * |     |  |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[1] = LAYOUT_65_iso(
  DE_CIRC,     KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, _______, _______,  \
  _______,    _______, KC_VOLU, KC_MPLY,_______,_______,_______,_______,_______,_______,_______,_______,_______,              _______,  \
  _______,    KC_MPRV, KC_VOLD, KC_MNXT,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,    _______,  \
  _______,    _______, _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,    _______,  \
  _______,    _______, _______,               _______,                          _______,_______, _______ ,_______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(DE_1) {
      rgblight_mode(STATIC_LIGHT);
    }
    SEQ_ONE_KEY(DE_2) {
      rgblight_mode(BREATHING);
    }
    SEQ_ONE_KEY(DE_3) {
      rgblight_mode(RAINBOW_MOOD);
    }
    SEQ_ONE_KEY(DE_4) {
      rgblight_mode(RAINBOW_SWIRL);
    }
    SEQ_ONE_KEY(DE_5) {
      rgblight_mode(SNAKE);
    }
    SEQ_ONE_KEY(DE_6) {
      rgblight_mode(KNIGHT);
    }
    SEQ_ONE_KEY(DE_7) {
      rgblight_mode(CHRISTMAS);
    }
    SEQ_ONE_KEY(DE_8) {
      rgblight_mode(STATIC_GRADIENT);
    }
    SEQ_ONE_KEY(DE_9) {
      rgblight_mode(ALTERNATING);
    }
    SEQ_ONE_KEY(DE_0) {
      rgblight_mode(TWINKLE);
    }

    SEQ_ONE_KEY(DE_V) {
      SS_TAB(VLK_TOG);
    }
  }
}

void led_set_user(uint8_t usb_led) {

}
