// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

// clang-format off
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL,
    KC_LAYER
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShaft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Space \  |BackSP |RAISE| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_ENT, KC_BSPC, RAISE, KC_RGUI),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |  END |      |      |                    | HOME |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(KC_GRV, KC_F2, KC_F3, KC_F4, KC_END, KC_F5, KC_HOME, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_PSCR, KC_TRNS),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|RGB_TOG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, BL_INC, BL_ON, BL_TOGG, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_OFF, BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE

/* Smart Backspace Delete */

bool            shift_held = false;
static uint16_t held_shift = 0;

/* KEYBOARD SPACESHIP START */

/* advanced settings */
#   define ANIM_FRAME_DURATION      100  // how long each frame lasts in ms
#   define DUCK_ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#   define MIN_SPACESHIP_DIM        4
#   define MAX_SPACESHIP_DIM        10
#   define LEFT_SPACESHIP_DIM       0
#   define RIGHT_SPACESHIP_DIM      2
#   define MAX_BULLETS              10

/* Frames array length */
#   define ALIEN_FRAMES_LEN         4
#   define SPACESHIP_FRAMES_LEN     5
#   define DUCK_FRAMES_LEN          2

/* List of bullets */
int bullets[MAX_BULLETS] = {[0 ... MAX_BULLETS - 1] = -1};

/* Spaceship position */
int y_spaceship = MAX_SPACESHIP_DIM;
int x_spaceship = (LEFT_SPACESHIP_DIM + RIGHT_SPACESHIP_DIM) / 2;

/* timers */
uint32_t anim_timer = 0;
uint32_t logo_anim_timer = 0;

/* current frame */
uint8_t current_duck_frame = 0;
uint8_t spaceship_current_frame = 0;
uint8_t alien_current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;
bool isExploded = false;

/* Animated rubber duck 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM duck[2][200] = {
        /* 'duck1', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x30, 0x18, 0x08, 0x08, 0x88, 0x18, 0x30, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xF0, 0xFC, 0x0C, 0x04, 0x8C, 0x48, 0x28, 0x2B, 0x2E, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1F, 0xF5, 0x47, 0x42, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x10, 0x12, 0x10, 0x02, 0x12, 0x02, 0x00, 0x00, 0x03, 0x26, 0x24, 0x25, 0x25, 0x25, 0x25, 0x05, 0x25, 0x04, 0x04, 0x04, 0x24, 0x26, 0x03, 0x21, 0x08, 0x01, 0x09, 0x09, 0x09, 0x09, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

        /* 'duck 2', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x30, 0x18, 0x08, 0x08, 0x88, 0x18, 0x30, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xF0, 0xFC, 0x0C, 0x24, 0x6C, 0xE8, 0xA8, 0xAB, 0x2E, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1F, 0xF5, 0x47, 0x42, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x10, 0x00, 0x00, 0x10, 0x12, 0x10, 0x02, 0x12, 0x03, 0x06, 0x04, 0x04, 0x24, 0x24, 0x25, 0x25, 0x25, 0x24, 0x04, 0x24, 0x04, 0x06, 0x03, 0x21, 0x20, 0x00, 0x21, 0x28, 0x21, 0x29, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
    };

    /* animation timer */
    if (timer_elapsed32(logo_anim_timer) > DUCK_ANIM_FRAME_DURATION) {
        logo_anim_timer = timer_read32();

        /* switch logo frame */
        current_duck_frame = (current_duck_frame + 1) % DUCK_FRAMES_LEN;
        oled_write_raw_P(duck[abs(1 - current_duck_frame)], sizeof(duck[abs(1 - current_duck_frame)]));
    }

     oled_set_cursor(0, 4);
     oled_write("Rubbe", false);

     oled_set_cursor(0, 5);
     oled_write(" Duck", false);
}

/* Print rubber duck */
static void print_rubber_duck(void) {
    render_logo();

    /* wpm counter */
    char wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + current_wpm % 10;
    wpm_str[1] = '0' + (current_wpm /= 10) % 10;
    wpm_str[0] = '0' + current_wpm / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void render_bullets(void) {

    for (int i = MIN_SPACESHIP_DIM; i < y_spaceship; i++) {
        oled_set_cursor(x_spaceship, i);
        oled_write("     ", false);
    }

    for (int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i] == 2) {
            bullets[i] = -1;
        }

        if(bullets[i] != -1) {
            oled_set_cursor(x_spaceship, bullets[i]);
            oled_write(" |   ", false);
            bullets[i]--;
        }
    }
    
}

/* Function to calculate explosion */
static bool calculate_explosion(void) {
    /* If it's exploding, don't need to check anymore */
    if (isExploded) {
        return true;
    }

    /* Go through all of bullets */
    for (int i = 0; i < MAX_BULLETS; i++) {

        /* If any bullets, explosion will be triggered */
        if(bullets[i] > 0 && bullets[i] < 5) {

            /* Set current frame into 0 as first frame of explosion */
            alien_current_frame = 0;
            return true;
        }
    }

    return false;
}

static void render_space(void) {
    static const char PROGMEM alien_frames[ALIEN_FRAMES_LEN][200] = {
        /* 'alien 0', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0x1E, 0x1E, 0x1E, 0x1E, 0x1F, 0x1F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x1E, 0x1E, 0x1E, 0x1E, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x01, 0xE1, 0xE1, 0x19, 0x19, 0x07, 0x07, 0x06, 0x06, 0xFE, 0xFE, 0x3E, 0x3E, 0xFF, 0xFF, 0x38, 0x38, 0xFF, 0xFF, 0x3E, 0x3E, 0xFE, 0xFE, 0x06, 0x06, 0x07, 0x07, 0x19, 0x19, 0xE1, 0xE1, 0x01, 0x00, 0x01, 0x01, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x01, 0x01, 0x00, },
        /* 'alien 1', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0x1E, 0x1E, 0x1E, 0x1E, 0x1F, 0x1F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x1E, 0x1E, 0x1E, 0x1E, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x01, 0xE1, 0xE1, 0x19, 0x19, 0x07, 0x07, 0x06, 0x06, 0xFE, 0xFE, 0x3E, 0x3E, 0xFF, 0xFF, 0x38, 0x38, 0xFF, 0xFF, 0x3E, 0x3E, 0xFE, 0xFE, 0x06, 0x06, 0x07, 0x07, 0x19, 0x19, 0xE1, 0xE1, 0x01, 0x00, 0x01, 0x01, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x01, 0x01, 0x00, },
        /* 'alien 2', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0x06, 0x06, 0x06, 0x06, 0x1F, 0x1F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x06, 0x06, 0x06, 0x06, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x01, 0x01, 0x01, 0xE1, 0xE1, 0x1F, 0x1F, 0x06, 0x06, 0xFE, 0xFE, 0x3E, 0x3E, 0xFF, 0xFF, 0x38, 0x38, 0xFF, 0xFF, 0x3E, 0x3E, 0xFE, 0xFE, 0x06, 0x06, 0x1F, 0x1F, 0xE1, 0xE1, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x00, },
        /* 'alien 3', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0x06, 0x06, 0x06, 0x06, 0x1F, 0x1F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0x1F, 0x1F, 0x06, 0x06, 0x06, 0x06, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x01, 0x01, 0x01, 0xE1, 0xE1, 0x1F, 0x1F, 0x06, 0x06, 0xFE, 0xFE, 0x3E, 0x3E, 0xFF, 0xFF, 0x38, 0x38, 0xFF, 0xFF, 0x3E, 0x3E, 0xFE, 0xFE, 0x06, 0x06, 0x1F, 0x1F, 0xE1, 0xE1, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x00, }};

    static const char PROGMEM exploded_alien_frames[ALIEN_FRAMES_LEN][200] = {
        /* 'exploded alien 0', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'exploded alien 1', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0xB8, 0xF0, 0xF8, 0x38, 0x38, 0x30, 0xF8, 0xF0, 0x58, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x30, 0x30, 0x0D, 0x07, 0x0F, 0x0E, 0x06, 0xCE, 0xCF, 0x07, 0x0F, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'exploded alien 2', 32x22px */
        { 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x40, 0xC0, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x40, 0xC0, 0xC0, 0xC0, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x23, 0x01, 0x03, 0xBB, 0xFE, 0xFE, 0xDE, 0x0E, 0x1E, 0x1C, 0x1E, 0x1E, 0x4E, 0xFE, 0x7E, 0xB7, 0x03, 0x03, 0x01, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x40, 0xC0, 0xC0, 0xF7, 0x3F, 0x3F, 0x2E, 0x1C, 0x38, 0x3C, 0x1C, 0x38, 0x3D, 0x3F, 0x3F, 0x77, 0xE0, 0xC0, 0x60, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x03, 0x03, 0x00, 0x18, 0x18, 0x01, 0x01, 0x01, 0x01, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, },
        /* 'exploded alien 3', 32x22px */
        { 0x00, 0x00, 0x00, 0x38, 0x78, 0x78, 0xE0, 0xC0, 0xC0, 0xCC, 0x8C, 0x00, 0xC0, 0xC0, 0xC0, 0x9C, 0xDC, 0xDC, 0xC0, 0xC3, 0x03, 0xC3, 0xC0, 0xC0, 0xF8, 0x78, 0x78, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x20, 0x00, 0x00, 0x74, 0xFF, 0xFF, 0xEF, 0xB7, 0x07, 0x01, 0x03, 0x07, 0x00, 0x05, 0x07, 0x03, 0x03, 0x07, 0x4F, 0xEF, 0xBE, 0x9E, 0x00, 0x06, 0x06, 0x00, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x18, 0x38, 0x30, 0x00, 0x25, 0xAF, 0xFF, 0xFD, 0xBC, 0xF0, 0xE0, 0xC0, 0xF0, 0xF0, 0xF0, 0xE0, 0xF0, 0xF0, 0xC0, 0xF6, 0xFF, 0xFF, 0xCD, 0x00, 0x04, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x02, 0x03, 0x03, 0x09, 0x03, 0xC3, 0xC1, 0xC0, 0x00, 0x03, 0x03, 0x03, 0x61, 0x63, 0x01, 0x08, 0x03, 0x03, 0x03, 0x0E, 0x0E, 0x06, 0x00, 0x60, 0x60, 0x00, }
    };

    /* alien animation */
    void animate_alien(void) {
        oled_set_cursor(0, 0);                                  
        if(isExploded) {
            /* draw explosion */
            oled_write_raw_P(exploded_alien_frames[alien_current_frame], sizeof(exploded_alien_frames[alien_current_frame]));
            
            /* If explosion finished, turn off explosion state to show alien */
            if(alien_current_frame == ALIEN_FRAMES_LEN - 1) {
                isExploded = false;
            }
        }
        else {
            /* draw alien */
            oled_write_raw_P(alien_frames[alien_current_frame], sizeof(alien_frames[alien_current_frame]));
        }
    }

    static const char PROGMEM spaceship_frames[SPACESHIP_FRAMES_LEN][144] = {
        /* 'spaceship 0', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xB8, 0xB8, 0xBA, 0x83, 0xBA, 0xB8, 0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xCC, 0x3E, 0xCF, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xCF, 0x3E, 0xCC, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x01, 0x09, 0x2D, 0x1D, 0x2D, 0x09, 0x01, 0x00, 0x00, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'spaceship 1', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xB8, 0xB8, 0xBA, 0x83, 0xBA, 0xB8, 0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x0C, 0x3E, 0x0F, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0x0F, 0x3E, 0x0C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x07, 0x00, 0x00, 0x01, 0x19, 0x0D, 0x2D, 0x0D, 0x19, 0x01, 0x00, 0x00, 0x07, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'spaceship 2', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xB8, 0xB8, 0xBA, 0x83, 0xBA, 0xB8, 0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x4C, 0x3E, 0xCF, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xCF, 0x3E, 0x4C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x1C, 0x00, 0x00, 0x01, 0x29, 0x1D, 0x0D, 0x1D, 0x29, 0x01, 0x00, 0x00, 0x1C, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'spaceship 3', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xB8, 0xB8, 0xBA, 0x83, 0xBA, 0xB8, 0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xCC, 0x3E, 0xCF, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xCF, 0x3E, 0xCC, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x33, 0x00, 0x00, 0x01, 0x09, 0x2D, 0x1D, 0x2D, 0x09, 0x01, 0x00, 0x00, 0x33, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
        /* 'spaceship 4', 32x22px */
        { 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xB8, 0xB8, 0xBA, 0x83, 0xBA, 0xB8, 0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xCC, 0x3E, 0xCF, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xCF, 0x3E, 0xCC, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x01, 0x29, 0x2D, 0x1D, 0x2D, 0x29, 0x01, 0x00, 0x00, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    };

    /* spaceship animation */
    void animate_spaceship(void) {
        oled_set_cursor(x_spaceship, y_spaceship);
        oled_write_raw_P(spaceship_frames[spaceship_current_frame], sizeof(spaceship_frames[spaceship_current_frame]));
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();

        // Calculate explosion of alien
        isExploded = calculate_explosion();

        /* switch frame */
        alien_current_frame = (alien_current_frame + 1) % ALIEN_FRAMES_LEN;
        spaceship_current_frame = (spaceship_current_frame + 1) % SPACESHIP_FRAMES_LEN;

        animate_alien();
        animate_spaceship();
    }
}

/* Function print spaceship oled*/
static void print_spaceship(void) {
    /* Render bullets */
    render_bullets();

    /*Render space*/
    render_space();

    /* Print current layer */
    oled_set_cursor(0, 14);
    oled_write("LAYER", false);

    oled_set_cursor(0, 15);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* Get current WPM */
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* Print oled screen */
    if (is_keyboard_master()) {
        print_spaceship();
    } else {
        print_rubber_duck();
    }
    return false;
}

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

        /* Smart Backspace Delete */
        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;

        case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;

        /* LAYER */
        case KC_LAYER:
            if (record->event.pressed) {
                if (shift_held) {
                } else {
                    layer_on(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        /* KEYBOARD SPACESHIP STATUS START */
        case KC_W:
        case KC_K:
        case KC_UP:
            if (record->event.pressed) {
                if(y_spaceship > MIN_SPACESHIP_DIM) {
                    y_spaceship--;
                }
            }
            break;
        case KC_S:
        case KC_J:
        case KC_DOWN:
            if (record->event.pressed) {
                if(y_spaceship < MAX_SPACESHIP_DIM) {
                    y_spaceship++;
                }
            }
            break;
        case KC_A:
        case KC_H:
        case KC_LEFT:
            if (record->event.pressed) {
                if(x_spaceship > LEFT_SPACESHIP_DIM) { 
                    x_spaceship--;
                }
            }
            break;
        case KC_D:
        case KC_L:
        case KC_RGHT:
            if (record->event.pressed) {
                if(x_spaceship < RIGHT_SPACESHIP_DIM) {
                    x_spaceship++;
                }
            }
            break;

        /* Fire when pressing space*/
        case KC_SPC:
            if (record->event.pressed) {
                for (int i = 0; i < MAX_BULLETS; i++) {
                    if(bullets[i] == -1) {
                        bullets[i] = y_spaceship - 1;
                        break;
                    }
                }
            }
            break;
        /* KEYBOARD SPACESHIP STATUS END */
    }
    return true;
}
/* KEYBOARD SPACESHIP END */