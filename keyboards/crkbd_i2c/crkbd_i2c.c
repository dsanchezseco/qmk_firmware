/* Copyright 2019 dsanchezseco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "crkbd_i2c.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/
#ifdef RGB_MATRIX_ENABLE

  // Logical Layout
  // Columns
  // Left
  // 0  1  2  3  4  5
  //                   ROWS
  // 25 24 19 18 11 10   0
  //    03    02    01
  // 26 23 20 17 12 09   1
  //    04    05    06
  // 27 22 21 16 13 08   2
  //
  //          15 14 07   3
  //
  // Right
  // 0  1  2  3  4  5
  //                    ROWS
  // 25 24 19 18 11 10   4
  //    03    02    01
  // 26 23 20 17 12 09   5
  //    04    05    06
  // 27 22 21 16 13 08   6
  //
  //          15 14 07   7
  //
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 25 24 19 18 11 10       10 11 18 19 24 25  0
  //    03    02    01       01    02    03
  // 26 23 20 17 12 09       09 12 17 20 23 26  1
  //    04                               04
  // 27 22 21 16 13 08       08 13 16 21 22 27  2
  //          05    06       06    05
  //           15 14 07     07 14 15              3

led_config_t g_led_config = { {
    {  51,  50,  45,  44,  37,  36, NO_LED },
    {  52,  49,  46,  43,  38,  35, NO_LED },
    {  53,  48,  47,  42,  39,  34, NO_LED },
    { NO_LED, NO_LED, NO_LED,  41,  40,  33, NO_LED },
    {  24,  23,  18,  17,  10,   9, NO_LED },
    {  25,  22,  19,  16,  11,   8, NO_LED },
    {  26,  21,  20,  15,  12,   7, NO_LED },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6, NO_LED }
}, {
    { 139,  16 }, { 174,  13 }, { 208,  20 }, { 208,  38 }, { 174,  48 }, { 139,  52 }, { 129,  63 },
    { 139,  39 }, { 139,  21 }, { 139,   4 }, { 156,   2 }, { 156,  19 }, { 156,  37 }, { 144,  58 },
    { 164,  55 }, { 174,  35 }, { 174,  13 }, { 174,   0 }, { 191,   3 }, { 191,  20 }, { 191,  37 },
    { 208,  42 }, { 208,  24 }, { 208,   7 }, { 224,   7 }, { 224,  24 }, { 224,  41 }, {  85,  16 },
    {  50,  13 }, {  16,  20 }, {  16,  38 }, {  50,  48 }, {  85,  52 }, {  95,  63 }, {  85,  39 },
    {  85,  21 }, {  85,   4 }, {  68,   2 }, {  68,  19 }, {  68,  37 }, {  80,  58 }, {  60,  55 },
    {  50,  35 }, {  50,  13 }, {  50,   0 }, {  33,   3 }, {  33,  20 }, {  33,  37 }, {  16,  42 },
    {  16,  24 }, {  16,   7 }, {   0,   7 }, {   0,  24 }, {   0,  41 }
}, {
    2, 2, 2, 2, 2, 2, 1,
    4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 2,
    2, 2, 2, 2, 2, 1, 4,
    4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 1
} };
#endif
