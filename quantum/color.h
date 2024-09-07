/* Copyright 2017 Jason Williams
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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "util.h"

// clang-format off

// RGB Colors
#define RGB_OFF         0x00, 0x00, 0x00
#define RGB_PINK        0xAA, 0x00, 0x66
#define RGB_CORAL       0xAA, 0x66, 0xAA
#define RGB_GREEN       0x00, 0xAA, 0x66
#define RGB_BLUE        0x00, 0x66, 0xAA
#define RGB_PURPLE      0x66, 0x00, 0xAA

// clang-format on
#define WS2812_BYTE_ORDER_RGB 0
#define WS2812_BYTE_ORDER_GRB 1
#define WS2812_BYTE_ORDER_BGR 2

#ifndef WS2812_BYTE_ORDER
#    define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
#endif

typedef struct PACKED rgb_led_t {
#if (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_GRB)
    uint8_t g;
    uint8_t r;
    uint8_t b;
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_RGB)
    uint8_t r;
    uint8_t g;
    uint8_t b;
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_BGR)
    uint8_t b;
    uint8_t g;
    uint8_t r;
#endif
#ifdef WS2812_RGBW
    uint8_t w;
#endif
} rgb_led_t;

typedef rgb_led_t RGB;

typedef struct PACKED HSV {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} HSV;

RGB hsv_to_rgb(HSV hsv);
RGB hsv_to_rgb_nocie(HSV hsv);
#ifdef WS2812_RGBW
void convert_rgb_to_rgbw(rgb_led_t *led);
#endif
