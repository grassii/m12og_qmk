/**
 * keymap.c
 */

#include QMK_KEYBOARD_H

// BASE BACKLIGHT LEVEL, 0 RECOMMENDED BECAUSE OTHERWISE IT FLICKERS WHICH LOOKS ANNOYING
int base = 0;

// LIGHT UP SCROLL LOCK ON KEYPRESS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

if (record->event.pressed) {

    backlight_level(base+1);}

    else {
            backlight_level(base);
        }

    return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0]=LAYOUT_tkl_ansi(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,   KC_PSCR, KC_SLCK, KC_PAUS,

		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,  KC_BSPC,   KC_INS, KC_HOME, KC_PGUP,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL, KC_END, KC_PGDN,
		KC_LCTL,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,     KC_ENT,
		KC_LSFT,     KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,      KC_RSFT,            KC_UP,
		KC_LGUI, KC_LGUI, KC_LALT,                 KC_SPC,                    KC_CAPS, MO(1), MO(1),  KC_LEFT, KC_DOWN, KC_RGHT),

	[1]=LAYOUT_tkl_ansi(
		RESET,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,

		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MUTE, _______, _______,
		_______, BL_INC, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______,          KC_MPLY, _______, _______,
		_______,   BL_DEC, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,       _______,
		_______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,                   KC_VOLU,
		_______, _______, _______,                           RGB_TOG,                                      _______, _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT),
};


// FADE-IN LIGHT ANIMATION WHEN PLUGGING IN USB, VERY HACKY BUT IT WORKS

void keyboard_post_init_user(void)
{
m12og_caps_led_off();

backlight_level(6);
_delay_ms(15);

backlight_decrease();
_delay_ms(30);
backlight_decrease();
_delay_ms(30);
backlight_decrease();
_delay_ms(40);
backlight_decrease();
_delay_ms(60);
backlight_decrease();
_delay_ms(90);
backlight_decrease();
_delay_ms(220);
backlight_level(base);

}


// DETECT LAYER CHANGE, ADJUST LED BRIGHTNESS WHEN FN ACTIVE

layer_state_t layer_state_set_user(layer_state_t state) {
     if (layer_state_cmp(state, 0)) {
        m12og_caps_led_off();
    }

     else if (layer_state_cmp(state, 1)) {
        m12og_caps_led_on();
       backlight_level(base+2);
    }


 else {

        m12og_caps_led_on();
    }

	return state;
}

