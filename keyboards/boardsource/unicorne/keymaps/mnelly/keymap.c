#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            uint8_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});

            if (index >= led_min && index < led_max && index != NO_LED) {
                if (keycode < KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_OFF);
                } else {
                    rgb_matrix_set_color(index, RGB_BLUE);

                    if (layer == 3){
                        if (keycode == KC_W || keycode == KC_A || keycode == KC_S || keycode == KC_D) {
                            rgb_matrix_set_color(index, RGB_PINK);
                        }
                    } else {
                            if (keycode == KC_F || keycode == KC_J) {
                                rgb_matrix_set_color(index, RGB_PINK);
                            }
                        }


                    if (keycode > KC_Z ) {
                        rgb_matrix_set_color(index, RGB_GREEN);
                    }

                    if (keycode > KC_F12) {
                        rgb_matrix_set_color(index, RGB_PURPLE);
                    }
                }
            }
        }
    }
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT), KC_LSFT, LALT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RALT_T(KC_SLSH), RSFT_T(KC_EQL), KC_LGUI, LT(1,KC_BSPC), LT(2,KC_TAB), LT(2,KC_ENT), LT(1,KC_SPC), KC_PSCR),
	[1] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_split_3x6_3(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, TG(3), KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
	[3] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_T, KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_SPC, KC_ESC, KC_NO, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
