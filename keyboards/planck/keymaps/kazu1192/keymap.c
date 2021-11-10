/* Copyright 2015-2021 Jack Humbert
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
#include "print.h"

enum planck_layers {
  _QWERTY,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  FOO = SAFE_RANGE,
  BAR
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE TG(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    MOUSE,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |WB BAK|WB REF|WB SCH|WB FWD|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WBAK, KC_WREF, KC_WSCH, KC_WFWD
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Vol- | Bri- | Bri+ | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_BRID, KC_BRIU, KC_VOLU
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug |      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,   RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    EEP_RST, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW,
    _______, _______, _______, AU_ON,   AU_OFF,  MU_ON,   MU_OFF,    MU_MOD,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

/* MOUSE_MODE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |MOUSEU|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MOUSEL|MOUSED|MOUSER|      |      |      |MOBTN1|MOBTN2|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOBTN2|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   MOBTN1    |      |MOWHEL|MOWHED|MOWHEU|MOWHER|
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______,    _______, KC_MS_U, _______, _______, _______,    _______,    _______,    _______,    _______, _______, _______,
    _______,    KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,    _______,    KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______,
    KC_MS_BTN2, _______, _______, _______, _______, _______,    _______,    _______,    _______,    _______, _______, _______,
    _______,    _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN1, _______,    KC_WH_L,    KC_WH_D, KC_WH_U, KC_WH_R
)

};

// LED layers
#ifdef RGBLIGHT_ENABLE
#define HSV_DEFLT    0,    0,  128
#define HSV_MOUSE   43,  255,  128
#define HSV_LOWER  150,  128,  128
#define HSV_RAISE   14,  225,  128

  const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS({ 0, 9, HSV_DEFLT });
  const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS({ 0, 9, HSV_MOUSE });
  const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({ 0, 9, HSV_LOWER });
  const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({ 0, 9, HSV_RAISE });
  const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      { 5, 4, HSV_LOWER },
      { 1, 4, HSV_RAISE }
  );

  const rgblight_segment_t* PROGMEM const my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
      my_default_layer,
      my_mouse_layer,
      my_lower_layer,
      my_raise_layer,
      my_adjust_layer
  );
#endif

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float plank_song[][2]      = SONG(PLANCK_SOUND);
  float ode_to_joy_song[][2] = SONG(ODE_TO_JOY);
  float rock_a_bye_baby[][2] = SONG(ROCK_A_BYE_BABY);
#endif

// 他の全てのものが初期化された後で実行
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_layers = my_rgb_layers;
#endif
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
  rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
#endif
  return state;
}

// レイヤーが切り替えられるたびに実行
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#ifdef RGBLIGHT_ENABLE
  rgblight_set_layer_state(1, layer_state_cmp(state, _MOUSE));
  rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
#endif

  return state;
}

// キーが押されるたびに実行
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(rock_a_bye_baby);
#endif
      }
      return false; // このキー以降のイベントをスキップ
    case BAR:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(plover_gb_song);
#endif
      }
      return false; // このキー以降のイベントをスキップ
  }
  return true; // 他の全てのキーコードを通常通りに処理します
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
