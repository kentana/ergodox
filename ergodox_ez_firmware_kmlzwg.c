#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(TG(1),KC_1,KC_2,KC_3,KC_4,KC_5,ALL_T(KC_NO),KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,TO(1),KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MINUS,TG(2),OSL(1),MO(1),ALT_T(KC_LEFT),GUI_T(KC_RIGHT),ALT_T(KC_APPLICATION),KC_LGUI,KC_LALT,KC_SPACE,KC_BSPACE,KC_LANG2,MEH_T(KC_NO),KC_6,KC_7,KC_8,KC_9,KC_0,KC_GRAVE,TO(2),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_EQUAL,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,GUI_T(KC_UP),ALT_T(KC_DOWN),KC_LBRACKET,KC_RBRACKET,MO(1),KC_LGUI,CTL_T(KC_ESCAPE),KC_LALT,KC_LANG1,KC_LCTL,KC_ENTER),

  [1] = KEYMAP(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_END,KC_TRANSPARENT,KC_TAB,TO(0),KC_TRANSPARENT,TO(0),LGUI(KC_F),LGUI(KC_X),KC_PGDOWN,KC_HOME,KC_TRANSPARENT,KC_TRANSPARENT,KC_DELETE,KC_DELETE,KC_TRANSPARENT,KC_PGUP,KC_TRANSPARENT,LT(2,KC_NO),KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_LEFT),LGUI(KC_RIGHT),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,TO(2),LGUI(KC_C),LGUI(KC_Z),TO(0),TO(0),LGUI(KC_V),KC_F12,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,LALT(KC_SPACE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LSFT(KC_TAB),KC_TAB,LGUI(KC_F),KC_TRANSPARENT,LGUI(KC_UP),LGUI(KC_DOWN),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [2] = KEYMAP(RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_Q),LGUI(KC_W),KC_TRANSPARENT,LGUI(KC_R),LGUI(KC_T),TO(1),KC_TRANSPARENT,LGUI(KC_A),KC_MS_LEFT,KC_MS_UP,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,LGUI(KC_Z),LGUI(KC_W),LGUI(KC_C),LGUI(KC_V),KC_TRANSPARENT,KC_MS_BTN3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),KC_TRANSPARENT,LCTL(KC_DOWN),KC_TRANSPARENT,KC_MS_BTN1,LCTL(KC_LEFT),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(0),KC_MS_WH_RIGHT,KC_MS_WH_UP,KC_MS_WH_DOWN,KC_MS_WH_LEFT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN3,TO(0),TO(1),LGUI(KC_C),LGUI(KC_V),KC_TRANSPARENT,KC_TRANSPARENT,KC_LGUI,KC_TRANSPARENT,LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_UP),KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_RIGHT),KC_MS_BTN2),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
