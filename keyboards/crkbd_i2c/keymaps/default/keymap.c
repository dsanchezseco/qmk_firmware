/* Copyright 2019 dsanchezseco
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
#include "split_util.h"

enum crkbd_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER = MO(_LOWER),
  RAISE = MO(_RAISE),
  ESC_CTL = MT(MOD_LCTL, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( \
  //,-----------------------------------------------.          ,-----------------------------------------------.
     KC_TAB, KC_QUOT,KC_COMM, KC_DOT, KC_P,   KC_Y,              KC_F,   KC_G,   KC_C,   KC_R,   KC_L,  KC_SLSH,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     ESC_CTL, KC_A,   KC_O,   KC_E,   KC_U,   KC_I,              KC_D,   KC_H,   KC_T,   KC_N,   KC_S, KC_MINUS,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     KC_LSFT,KC_SCLN, KC_Q,   KC_J,   KC_K,   KC_X,              KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,KC_SFTENT,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
                                KC_LGUI, LOWER, KC_SPC,    KC_BSPC, RAISE,KC_RALT \
                             //`-----------------------'  `----------------------'
  ),


  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------.          ,-----------------------------------------------.
     KC_TILD,KC_EXLM, KC_AT, KC_HASH, KC_DLR,KC_PERC,           KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RIGHT,KC_RPRN,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,           _______,KC_LEFT,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,KC_DOWN, KC_UP, _______,           _______,_______,_______,KC_HOME, KC_END,_______,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
                                _______,_______,_______,   KC_DEL,_______,_______ \
                             //`-----------------------'  `----------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------.          ,-----------------------------------------------.
     KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,  KC_5,              KC_6,    KC_7,  KC_8,    KC_9,KC_RIGHT,  KC_0, \
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,           _______,KC_LEFT, KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,KC_DOWN, KC_UP, _______,           _______,_______,_______,KC_PGUP,KC_PGDN,_______,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
                                _______,_______,_______,   KC_DEL ,_______,_______ \
                             //`-----------------------'  `----------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------.          ,-----------------------------------------------.
     _______,_______,_______,_______,_______,_______,          _______,_______,_______,_______,KC_RIGHT,_______,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,           _______,KC_LEFT,_______,_______,_______,_______,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
     _______,KC_PSCR,_______,KC_DOWN, KC_UP, _______,           _______,_______,_______,_______,_______,_______,\
  //|-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------|
                                _______,_______,_______,   KC_DEL ,_______,_______ \
                             //`-----------------------'  `----------------------'
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!isLeftHand)
    return OLED_ROTATION_180;  // flips the display 270 to see it from my side
  return rotation;
}

//const char *read_logo(void);
void oled_task_user(void){
    switch (biton32(layer_state)){
        case _DVORAK:
            oled_write_ln_P(PSTR("DVRK"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
  // now print logo
  // oled_write(read_logo(), false);
}
#endif
