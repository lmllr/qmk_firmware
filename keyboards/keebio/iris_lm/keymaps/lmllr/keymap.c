// ISO-CH Layer for keebio iris lm rev k
// Controller: STM32G431
// Helpfull links:
//   - https://docs.keeb.io/iris-lm-build-guide
//   - https://docs.qmk.fm/newbs_flashing#flash-your-keyboard-from-the-command-line
//   - https://config.qmk.fm/#/keebio/iris_lm/k1/LAYOUT
//   - https://jhelvy.shinyapps.io/qmkjsonconverter/

#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"
#include "sendstring_swiss_de.h"

// Name the layers
enum custom_layers {
    _QWERTZ,
    _BACKETS,
    _MEDIA,
    _GAMING
};

// Disable autoshift on the media and gaming layers
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    // disable autoshift for select layers
    case _MEDIA:
    case _GAMING:
      autoshift_disable();
      break;
    //  for any other layers, enable autoshift
    default:
      autoshift_enable();
      break;
    }
  return state;
}

// Keymap proper
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTZ] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, CH_1,    CH_2,    CH_3,    CH_4,    CH_5,                               CH_6,    CH_7,    CH_8,    CH_9,    CH_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,                               CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    CH_UDIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, CH_A,    CH_S,    CH_D,    CH_F,    CH_G,                               CH_H,    CH_J,    CH_K,    CH_L,    CH_ODIA, CH_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM(MOD_LSFT), CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,    KC_HOME,          KC_END,  CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS, OSM(MOD_RSFT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, MO(1),   KC_SPC,                    KC_ENT,  MO(2),   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_BACKETS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     CH_DEG,  CH_PLUS, CH_DQUO, CH_ASTR, CH_CCED, CH_PERC,                            CH_AMPR, CH_SLSH, CH_LPRN, CH_RPRN, CH_EQL,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CH_SECT,  _______, _______, KC_UP,  QK_BOOT, _______,                            CH_ASTR, CH_LCBR, CH_RCBR, CH_LABK, CH_AMPR, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                            CH_EQL,  CH_LPRN, CH_RPRN, CH_QUOT, CH_DIAE, CH_CIRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, EE_CLR,  _______, _______, _______, _______, KC_PGUP,          KC_PGDN, CH_PLUS, CH_LBRC, CH_RBRC, CH_AMPR, CH_DLR,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    KC_ENT,  TO(3),   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MEDIA] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RM_TOGG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  QK_BOOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, TO(3),   _______,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  CH_1,    CH_2,    CH_3,    CH_4,    CH_5,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, CH_A,    CH_S,    CH_D,    CH_F,    CH_G,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┼───────────┐           ┌───────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, CH_Z,    CH_X,    CH_C,    CH_V,    CH_B,    S(KC_F12),              KC_PENT,    CH_ADIA, CH_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, TO(0),
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───────┘           └─┬─────────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      CH_Y,    KC_RSFT, KC_SPC,                        RCTL_T(CH_M), KC_PGUP, KC_PGDN
                                  // └────────┴────────┴────────┘                     └─────────────┴────────┴────────┘
  )

};
