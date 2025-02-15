/*
Copyright 2022 Rocco Meli <@RMeli>

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

#define OLED_TIMEOUT 0
#define SPLIT_WPM_ENABLE
#define MASTER_LEFT // Left side is the master
#define SPLIT_LED_STATE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Configure RGB Matrix
#    define RGB_MATRIX_KEYPRESSES // enable keypress effects
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_SAT
#    define RGB_MATRIX_DEFAULT_HUE 10
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
// Enable RGB Matrix effects
#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
#   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_BAND_SAT
#   define ENABLE_RGB_MATRIX_BAND_VAL
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_COLOR
#   define ENABLE_RGB_MATRIX_SPLASH	
#   define ENABLE_RGB_MATRIX_MULTISPLASH	
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS	
// #   define ENABLE_RGB_MATRIX_RAINDROPS
// #   define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #   define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#endif
