/**
 * config.h
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4D58   // MX
#define PRODUCT_ID      0x8712   // matrix 1.2 og
#define DEVICE_VER      0x0001
#define MANUFACTURER    matrix
#define PRODUCT         M12OG
#define DESCRIPTION     Matrix 8XV1.2 OG version

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, F0, B7, C7, D3, B0, D1 }
#define MATRIX_COL_PINS { F1, F4, F5, F6, F7, B6, B5, B4, D7, D0, D2, D6, D4, D5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN B3
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS

#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#endif


#define UNICODE_SELECTED_MODES UC_WINC


#define BACKLIGHT_DRIVER = no;
#define BACKLIGHT_PIN B2
#define BACKLIGHT_LEVELS 6
