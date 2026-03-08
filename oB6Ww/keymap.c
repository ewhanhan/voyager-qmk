#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(6, KC_L)
#define DUAL_FUNC_1 LT(5, KC_T)
#define DUAL_FUNC_2 LT(10, KC_R)
#define DUAL_FUNC_3 LT(6, KC_4)
#define DUAL_FUNC_4 LT(5, KC_G)
#define DUAL_FUNC_5 LT(14, KC_3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    DUAL_FUNC_0,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           DUAL_FUNC_1,    
    ALL_T(KC_TAB),  MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RCTL, KC_SCLN),DUAL_FUNC_2,    
    KC_MEH,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           DUAL_FUNC_3,    DUAL_FUNC_4,    DUAL_FUNC_5,    KC_ESCAPE,      
                                                    LT(1, KC_ENTER),LT(2, KC_ESCAPE),                                LT(2, KC_BSPC), LT(1, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_TRANSPARENT, 
    KC_TILD,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_TRANSPARENT, 
    KC_EQUAL,       KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255}, {139,255,255} },

    [1] = { {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204}, {92,218,204} },

    [2] = { {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199}, {206,221,199} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_GRAVE);
        } else {
          unregister_code16(KC_GRAVE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TILD);
        } else {
          unregister_code16(KC_TILD);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_BSLS);
        } else {
          unregister_code16(KC_BSLS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PIPE);
        } else {
          unregister_code16(KC_PIPE);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUOTE);
        } else {
          unregister_code16(KC_QUOTE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DQUO);
        } else {
          unregister_code16(KC_DQUO);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SLASH);
        } else {
          unregister_code16(KC_SLASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
