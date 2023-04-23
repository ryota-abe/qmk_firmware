/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

//#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define ONESHOT_TAP_TOGGLE 2

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef MOUSEKEY_ENABLE
    /* #define MOUSEKEY_DELAY 10 */
    /* #define MOUSEKEY_INTERVAL 20 */
    /* #define MOUSEKEY_MOVE_DELTA 8 */
    /* #define MOUSEKEY_MAX_SPEED 10 */
    /* #define MOUSEKEY_TIME_TO_MAX 30 */
    /* #define MOUSEKEY_WHEEL_INTERVAL 80 */
    /* #define MOUSEKEY_WHEEL_MAX_SPEED 8 */
    /* #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 */

    /* #define MK_COMBINED */
    /* #define MOUSEKEY_DELAY 0 */
    /* #define MOUSEKEY_INTERVAL 16 */
    /* #define MOUSEKEY_MOVE_DELTA 4 */
    /* #define MOUSEKEY_MAX_SPEED 3 */
    /* #define MOUSEKEY_TIME_TO_MAX 20 */
    /* #define MOUSEKEY_WHEEL_DELAY 0 */
    /* #define MOUSEKEY_WHEEL_INTERVAL 80 */
    /* #define MOUSEKEY_WHEEL_MAX_SPEED 160 */
    /* #define MOUSEKEY_WHEEL_TIME_TO_MAX 80 */

    #define MK_KINETIC_SPEED
    #define MOUSEKEY_DELAY 5
    #define MOUSEKEY_INTERVAL 10
    #define MOUSEKEY_MOVE_DELTA 16
    #define MOUSEKEY_INITIAL_SPEED 200
    #define MOUSEKEY_BASE_SPEED 2000
    #define MOUSEKEY_DECELERATED_SPEED 100
    #define MOUSEKEY_ACCELERATED_SPEED 3000
    #define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 4
    #define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
    #define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
    #define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 4

    /* #define MOUSEKEY_INERTIA */
    /* #define MOUSEKEY_DELAY 150 */
    /* #define MOUSEKEY_INTERVAL 16 */
    /* #define MOUSEKEY_MAX_SPEED 32 */
    /* #define MOUSEKEY_TIME_TO_MAX 32 */
    /* #define MOUSEKEY_FRICTION 24 */
    /* #define MOUSEKEY_MOVE_DELTA 1 */
    /* #define MOUSEKEY_WHEEL_INTERVAL 80 */
    /* #define MOUSEKEY_WHEEL_MAX_SPEED 8 */
    /* #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 */
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
