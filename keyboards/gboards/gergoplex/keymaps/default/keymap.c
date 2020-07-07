/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define NUMB 2  // numbers/motion

/* Combomap
 *
 * +-----+-----+-----+------+-----+      ,-----+-----+-----+-----+--------+
 * |    ESC    |     |      |     |      |    BSPC   DEL  '/'   '\'       |
 * |-----+-----+-----+------+-----|      |-----+-----+-----+-----+--------|
 * |     |     |     |      |     |      |     <     :     >     |        |
 * |-----+-----+-----+------------+      |-----+-----+-----+-----+--------|
 * |     |    M-x Spc `     |     |      |     "     '     _     |        |
 * `-----+-----+-----+------+-----+      +-----+-----+-----+-----+--------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,-----------------------------.       ,--------------------------------.
     * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
     * |-----+-----+-----+-----+------|      |--------------------------------|
     * |SHFT/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | SHFT/; |
     * |-----+-----+-----+-----+------+		   |--------------------------------|
     * |CTRL/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | CTRL/? |
     * `------+-----+-----+------+----'		   `--------------------------------'
     *  .-------------------------.           .-----------------.
     *  |ESC/ALT|TAB/META|SPC(SYM)|           |SPC(NUM)|ENT|BSPC|
     *  '-------------------------'           '-----------------'
     */
    [BASE] = LAYOUT_gergoplex(KC_Q,               KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P, 
                              MT(MOD_LSFT, KC_A), KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, MT(MOD_RSFT, KC_SCLN),
                              MT(MOD_LCTL, KC_Z), KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RCTL, KC_SLSH),

                              MT(MOD_LALT, KC_ESC), MT(MOD_LGUI, KC_TAB), LT(SYMB, KC_SPC),  // Left
                              LT(NUMB, KC_SPC),     KC_ENT,               KC_BSPC            // Right
                              ),

    /* Keymap 1: Symbols layer
     * +------------------------------+      +--------------------------------+
     * |  !   |  @  |  {  |  }  |  |  |      |  `  |  ~  |  \  |     |   "    |
     * |-----+-----+-----+-----+------|      |--------------------------------|
     * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |   '    |
     * |-----+-----+-----+-----+------+		   |--------------------------------|
     * |  %   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |   _    |
     * `------+-----+-----+------+----+		   +--------------------------------+
     *  				.-----------------.           .------------------.
     *  				|MMB |  ;  	|	 = 	|						|  =  |  ;  |  DEL |
     *  				'-----------------'           '------------------'
     */
    [SYMB] = LAYOUT_gergoplex(KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,    KC_GRV,  KC_TILD, KC_BSLS, KC_TRNS, KC_DQT,
                              KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,    KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT, 
                              KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,    KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_UNDS, 

                                                CMB_TOG, KC_SCLN, KC_EQL,     KC_EQL,  KC_SCLN, KC_DEL),
    /* Keymap 2: Pad/Function layer
     * ,-----------------------------.       ,--------------------------------.
     * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7   |  8  |  9  |   0   |
     * |-----+-----+-----+-----+------|      |--------------------------------|
     * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN  | UP  | RGT | VOLUP |
     * |-----+-----+-----+-----+------+		   |--------------------------------|
     * |CTL/F6| F7  | F8  | F9  | F10 |      | PGDN|C(DWN)|C(UP)| PGUP| VOLDN |
     * `------+-----+-----+------+----'		   `--------------------------------'
     *  				.-----------------.           .-----------------.
     *  				| F11 | F12|	  	|						|     | ALT | END |
     *  				'-----------------'           '-----------------'
     */
    [NUMB] = LAYOUT_gergoplex(KC_1,  KC_2,  KC_3,   KC_4,   KC_5,     KC_6,    KC_7,       KC_8,     KC_9,    KC_0,
                              KC_F1, KC_F2, KC_F3,  KC_F4,  KC_F5,    KC_LEFT, KC_DOWN,    KC_UP,    KC_RGHT, KC_VOLU,
                              MT(MOD_LCTL, KC_F6), KC_F7, KC_F8,  KC_F9,  KC_F10,   KC_PGDN, C(KC_DOWN), C(KC_UP), KC_PGUP, KC_VOLD, 

                                            KC_F11, KC_F12, KC_TRNS,  KC_TRNS, KC_LALT,    KC_END)};
