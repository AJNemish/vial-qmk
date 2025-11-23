#include QMK_KEYBOARD_H

enum layers {
  PRESET0, // Red
  PRESET1, // Green
  PRESET2, // Blue
  PRESET3  // Yellow
};

enum custom_keycodes {
  CYCLE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PRESET0] = LAYOUT_4x4(
    CYCLE, KC_F2,  KC_F3,  KC_F4,
    KC_F5, KC_F6,  KC_F7,  KC_F8,
    KC_F9, KC_F10, KC_F11, KC_F12,
    _______, KC_MUTE, KC_MPLY, TO(PRESET0)
  ),

  [PRESET1] = LAYOUT_4x4(
    CYCLE, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),

  [PRESET2] = LAYOUT_4x4(
    CYCLE, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),

  [PRESET3] = LAYOUT_4x4(
    CYCLE, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;
  if (keycode == CYCLE) {
    uint8_t current = get_highest_layer(layer_state);
    uint8_t next = (current + 1) % 4;
    layer_move(next);
    return false;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (index) {
    case 0:
      tap_code(clockwise ? KC_VOLU : KC_VOLD);
      break;
    case 1:
      tap_code(clockwise ? KC_MNXT : KC_MPRV);
      break;
    case 2:
      tap_code(clockwise ? KC_PGDN : KC_PGUP);
      break;
  }
  return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
  switch (get_highest_layer(state)) {
    case PRESET0: rgblight_setrgb(255, 0, 0); break;
    case PRESET1: rgblight_setrgb(0, 255, 0); break;
    case PRESET2: rgblight_setrgb(0, 0, 255); break;
    case PRESET3: rgblight_setrgb(255, 255, 0); break;
  }
#endif
  return state;
}
