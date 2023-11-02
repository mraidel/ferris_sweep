#include QMK_KEYBOARD_H
#include "keymap_german.h"


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
void housekeeping_task_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            // Default layer
            rgblight_setrgb_at(RGB_BLACK, 0);
            rgblight_setrgb_at(RGB_BLACK, 1);
            break;
        case 1:
            rgblight_setrgb_at(RGB_YELLOW, 0);
            rgblight_setrgb_at(RGB_YELLOW, 1);
            break;
        case 2:
            rgblight_setrgb_at(RGB_RED, 0);
            rgblight_setrgb_at(RGB_RED, 1);
            break;
        case 3:
            rgblight_setrgb_at(RGB_ORANGE, 0);
            rgblight_setrgb_at(RGB_ORANGE, 1);
            break;
        case 4:
            rgblight_setrgb_at(RGB_PURPLE, 0);
            rgblight_setrgb_at(RGB_PURPLE, 1);
            break;
        case 7:
            rgblight_setrgb_at(RGB_GREEN, 0);
            rgblight_setrgb_at(RGB_GREEN, 1);
            break;
        case 5:
            rgblight_setrgb_at(RGB_BLUE, 0);
            rgblight_setrgb_at(RGB_BLUE, 1);
            break;
        case 6:
            rgblight_setrgb_at(RGB_AZURE, 0);
            rgblight_setrgb_at(RGB_AZURE, 1);
            break;
    }
}

enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

enum {
    TD_7_SLSH,
    TD_8_ASTR,
    TD_9_MINS,
    TD_6_PLUS,
    TD_3_EQL,
    TD_2_COMM,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_7_SLSH] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, DE_SLSH),
    [TD_8_ASTR] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, DE_ASTR),
    [TD_9_MINS] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, DE_MINS),
    [TD_6_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, DE_PLUS),
    [TD_3_EQL] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, DE_EQL),
    [TD_2_COMM] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, DE_COMM),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

  switch (keycode) {
        case TD(TD_7_SLSH):
        case TD(TD_8_ASTR):
        case TD(TD_9_MINS):
        case TD(TD_6_PLUS):
        case TD(TD_3_EQL):
        case TD(TD_2_COMM):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    case LALT_T(DE_EQL):
    if (record->tap.count && record->event.pressed) {
      tap_code16(DE_EQL);
      return false;
    }
    break;
    case LT(11, DE_SCLN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(DE_SCLN);
      return false;
    }
    break;
  }
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      //SEND_STRING(SS_RALT(SS_TAP(X_NONUS_BSLASH)) SS_DELAY(100) SS_RALT(SS_TAP(X_NONUS_BSLASH)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_0)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_9)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
        tap_code16(DE_RABK);
        wait_ms(100);
        tap_code(KC_LEFT);
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_2)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_7)) SS_DELAY(100) SS_LSFT(SS_TAP(X_7)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_P));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_A)));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_N));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_0));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_1));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_2));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_3));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_4));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_5));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_6));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_7));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_8));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_9));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_G)) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F3)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_PGUP));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100)  SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT("2") SS_DELAY(100) "]");
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_LSFT(SS_TAP(X_1)));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_W)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_M)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_RIGHT));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
        tap_code16(DE_GRV);
        wait_ms(100);
        tap_code(KC_LEFT);
    }
    break;

    }
  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case DE_LPRN: return ST_MACRO_1;
        case DE_LCBR: return ST_MACRO_2;
        case DE_LBRC: return ST_MACRO_3;
        case DE_LABK: return ST_MACRO_4;
        case DE_DQUO: return ST_MACRO_5;
        case DE_GRV: return ST_MACRO_37;
        case LT(5, KC_U): return LCTL(KC_R);
    }

    return KC_TRNS;  // Defer to default definitions.
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
            KC_Q,         LT(7,KC_W),   LT(5, KC_F),  LT(6,KC_P),  KC_B,            KC_J,   LT(6,KC_L),  LT(5, KC_U),    LT(7, DE_Y),  DE_UNDS,
            LALT_T(KC_A), LCTL_T(KC_R), LSFT_T(KC_S), LT(4,KC_T),  LT(11, KC_G),     KC_M,   LT(4,KC_N),  LSFT_T(KC_E),   LCTL_T(KC_I), LALT_T(KC_O),
            LT(12, DE_Z), LGUI_T(KC_X), KC_C,         LT(2, KC_D), KC_V,            KC_K,   LT(2, KC_H), KC_COMM,        KC_DOT,       KC_AMPR,
                                                      OSL(1),      OSM(MOD_LSFT),   KC_SPC, KC_BSPC),
	[1] = LAYOUT_split_3x5_2(
            DE_SS,          DE_UDIA,         DE_ODIA, DE_ADIA, DE_TILD,            QK_ALT_REPEAT_KEY,    KC_TAB,    DE_LPRN, DE_LCBR, DE_LBRC,
            LALT_T(DE_EQL), LCTL_T(DE_HASH), DE_PERC, DE_COLN, LT(11, DE_SCLN),    QK_REPEAT_KEY,    KC_ESCAPE, DE_LABK, DE_DQUO, DE_QUES,
            DE_ASTR,        DE_PIPE,         DE_AMPR, DE_AT,   DE_BSLS,            KC_NO,    DE_EURO,   DE_CIRC, DE_ACUT, DE_MINS,
                                                      KC_NO,   KC_NO,              KC_ENTER, KC_DELETE),
	[2] = LAYOUT_split_3x5_2(
            KC_NO, LSFT(DE_UDIA), LSFT(DE_ODIA), LSFT(DE_ADIA), KC_NO,   QK_ALT_REPEAT_KEY, LSFT(KC_TAB), DE_RPRN, DE_RCBR, DE_RBRC,
            KC_NO, KC_NO,         KC_NO,         KC_NO,         MO(11),   QK_REPEAT_KEY, KC_NO,        DE_RABK, DE_QUOT, DE_EXLM,
            KC_NO, KC_NO,         KC_NO,         KC_NO,         KC_NO,   KC_NO, KC_NO,        DE_DLR,  DE_GRV,  DE_PLUS,
                                                 KC_NO,         KC_NO,   LSFT(KC_ENTER),      KC_DELETE),
	[4] = LAYOUT_split_3x5_2(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME,             KC_PGUP,     KC_PGDN,       KC_END,
            KC_NO,   KC_LCTL, KC_LSFT, KC_NO,   MO(11),  KC_NO,   KC_LEFT,             KC_UP,       KC_DOWN,       KC_RIGHT,
            KC_TRNS, KC_NO,   KC_NO,   KC_LGUI, KC_TAB,  KC_TRNS, LGUI(LSFT(KC_LEFT)), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(LSFT(KC_RIGHT)),
                                       KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
	[5] = LAYOUT_split_3x5_2(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   LSFT(KC_G),  TD(TD_7_SLSH), TD(TD_8_ASTR), TD(TD_9_MINS), DE_COLN,
            KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, MO(11),    ST_MACRO_20, KC_4,          KC_5,          TD(TD_6_PLUS), DE_DOT,
            KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,       KC_1,          TD(TD_2_COMM), TD(TD_3_EQL),  KC_COMM,
                                       KC_TRNS, KC_TRNS,   KC_0,        KC_TRNS
            ),
	[6] = LAYOUT_split_3x5_2(
            KC_NO,       LSFT(DE_UDIA), LSFT(DE_ODIA), LSFT(DE_ADIA), KC_NO,         ST_MACRO_26 , ST_MACRO_27, ST_MACRO_28, ST_MACRO_29, KC_NO,
            ST_MACRO_21, ST_MACRO_22,   ST_MACRO_23,   ST_MACRO_24,   MO(11),         KC_NO,        ST_MACRO_30, ST_MACRO_31, ST_MACRO_32, ST_MACRO_33,
            ST_MACRO_25, LALT(KC_F4),   KC_F5,         KC_F11,        LGUI(KC_D),    KC_NO,        ST_MACRO_34, ST_MACRO_35, ST_MACRO_36, KC_PRINT_SCREEN,
                                                       KC_NO,         KC_NO,         KC_ENTER,     KC_DELETE),
	[7] = LAYOUT_split_3x5_2(
            KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO,      KC_NO, KC_MS_BTN1,   KC_MS_BTN3,  KC_MS_BTN2,    KC_NO,
            KC_C,               KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     MO(11),    KC_NO, KC_MS_LEFT,   KC_MS_UP,    KC_MS_DOWN,    KC_MS_RIGHT,
            KC_J,               KC_LEFT,         KC_RIGHT,               KC_L,               KC_F,      KC_NO, KC_MS_ACCEL0, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_NO,
                                                                     KC_MS_ACCEL2,        KC_NO,      KC_NO, KC_NO
            ),

	[11] = LAYOUT_split_3x5_2(
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        TO(7),        KC_NO,        KC_NO, KC_NO,
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        TO(4),        TO(5),        TO(6), KC_NO,
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        TO(1),        TO(2),        KC_NO, KC_NO,
            KC_NO, KC_NO, TO(0),       KC_NO),

	[12] = LAYOUT_split_3x5_2(
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_WAKE,
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO,
            KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO, QK_BOOT,
            KC_NO, KC_NO, KC_NO,       KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
