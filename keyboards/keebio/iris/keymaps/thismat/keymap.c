#include <stdint.h>
#include "keycodes.h"
#include "quantum.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _SYM,
    _NAV,
    _FN,
    _GAMING,
    _MOUSE,
};

// Custom keycodes
enum custom_keycodes {
    SAFE   = SAFE_RANGE,
    PLS_EQ,
    MIN_EQ,
};

// Tabs
#define NXT_TAB LCTL(KC_TAB)
#define PRV_TAB RCS(KC_TAB)

// Hold layer changes
#define MO_FN MO(_FN)
#define MO_NAV MO(_NAV)
#define MO_SYM MO(_SYM)

// Toggles
#define TG_GAME TG(_GAMING)
#define TG_MOUS TG(_MOUSE)
#define TG_NAV TG(_NAV)

// Selections
#define SELW_L RCS(KC_LEFT)
#define SELW_R RCS(KC_RIGHT)

// Mod-Taps
#define RHT_CTL MT(MOD_LCTL, KC_RIGHT)
#define DN_CTL  MT(MOD_LCTL, KC_DOWN)

// Spacebar / Layers
#define SPC_NAV LT(MO_NAV, KC_SPACE)
#define SPC_SYM LT(MO_SYM, KC_SPACE)

// Page Up/Down Combos
#define AS_PGUP RSA(KC_PGUP)
#define AS_PGDN RSA(KC_PGDN)

// Combos!

// Single Key Combos
const uint16_t PROGMEM enter_combo[]   = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM home_combo[]    = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM end_combo[]     = {KC_K, KC_L, COMBO_END};

// Layer Combos
const uint16_t PROGMEM toggle_gaming[] = {KC_9, KC_0, COMBO_END};

combo_t key_combos[] = {
    // Single Key KC_ENDCombos
    COMBO(enter_combo, KC_ENT),
    COMBO(home_combo,  KC_HOME),
    COMBO(end_combo,   KC_END),

    // Layer Combos
    COMBO(toggle_gaming, TG_GAME),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO_NAV,           MO_NAV,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           KC_LGUI, KC_LALT, SPC_SYM,                   KC_SPC, KC_ENT,  MO_FN
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_SYM] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                            AS_PGUP, AS_PGDN, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,  PRV_TAB, NXT_TAB, XXXXXXX, XXXXXXX, KC_MPLY,                            PLS_EQ,  MIN_EQ, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LCTL, XXXXXXX, KC_LSFT, XXXXXXX, KC_LCTL, KC_VOLU,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_HOME,          KC_END,  KC_PLUS, KC_EQL,  _______, _______, KC_BSLS, KC_RSFT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           XXXXXXX, _______, KC_SPC,                    KC_SPC,  _______, TG_MOUS
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_NAV] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,  XXXXXXX, KC_LGUI, KC_UP,   XXXXXXX, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, RHT_CTL, XXXXXXX,                            KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, XXXXXXX, KC_LCTL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, SELW_L,  XXXXXXX, XXXXXXX, SELW_R,  XXXXXXX, KC_RSFT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           XXXXXXX, _______, KC_SPC,                    KC_SPC , XXXXXXX, XXXXXXX
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_FN] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_PSCR, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, SGUI(KC_S),KC_DEL,_______, _______,                            _______, _______, _______, SGUI(KC_L), _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           _______, _______, _______,                   _______, _______, _______
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_GAMING] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______, MO_SYM,           _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           KC_LCTL, _______, KC_SPC,                    KC_SPC, _______, _______
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_MOUSE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, KC_WH_U, KC_WH_D,                            _______, _______, KC_MS_U, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, KC_BTN1, KC_BTN2,                            _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            QK_BOOT, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           _______, _______, _______,                   _______, _______, TG_MOUS
                                       // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};

/*
 * RGB Underglow Indexes
 * Left Half:  28, 29, 30, 31, 32, 33
 * Right Half: 62, 63, 64, 65, 66, 67
 */

// RGB Indexes for the bottom halves of the Iris
uint8_t rgb_matrix_bottom_indexes[]     = {
    // Left Half
    28, 29, 30, 31, 32, 33, 34,

    // Right Half
    62, 63, 64, 65, 66, 67, 68
};

void set_bottom_rgbs(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < sizeof(rgb_matrix_bottom_indexes); i++) {
        rgb_matrix_set_color(rgb_matrix_bottom_indexes[i], red, green, blue);
    }
}

bool rgb_matrix_indicators_kb(void) {
    switch (get_highest_layer(layer_state)) {
        case (_GAMING):
            set_bottom_rgbs(0, 128, 155);
            break;
        case (_SYM):
            set_bottom_rgbs(255, 208, 0);
            break;
        case (_NAV):
            set_bottom_rgbs(255, 199, 52);
            break;
        case (_FN):
            set_bottom_rgbs(100, 255, 100);
            break;
        case (_MOUSE):
            set_bottom_rgbs(255, 0, 166);
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
    rgb_matrix_set_speed(30);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLS_EQ:
            if (record->event.pressed) {
                SEND_STRING("+=");
            }

            break;
        case MIN_EQ:
            if (record->event.pressed) {
                SEND_STRING("-=");
            }

            break;
    }

    return true;
}
