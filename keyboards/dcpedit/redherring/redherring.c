// Copyright 2023 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#define LOGO_SIZE 1024

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM oled_logo[LOGO_SIZE] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x30, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xc3, 0x06, 0x18, 0xe1, 0x03, 0x0c, 0xb0, 0x60, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x80, 0x78, 0x00, 0x00, 0x00, 0xe0, 0x1c, 
        0x00, 0x00, 0xc0, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xe0, 0x00, 0x00, 0x04, 0x78, 0x80, 0x00, 
        0x00, 0x38, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 

        0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0xff, 0x1f, 0x3f, 0xfe, 0x3e, 0x7f, 0xfe, 0x7c, 0x7f, 0x7c, 
        0x3c, 0x20, 0x20, 0xe0, 0x7c, 0x43, 0x40, 0xc0, 0xf8, 0x87, 0x80, 0x80, 0xe0, 0x1e, 0x01, 0x00, 
        0xc0, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1e, 0xe0, 0x00, 0x00, 0x07, 0x78, 
        0x80, 0x80, 0x83, 0xbf, 0xff, 0xff, 0xe3, 0xc1, 0xc1, 0xc1, 0xc1, 0xf7, 0xfe, 0xfe, 0xfc, 0x78, 
        0x00, 0x00, 0x10, 0x90, 0x88, 0x4c, 0x64, 0x22, 0x12, 0x11, 0x08, 0x0c, 0x07, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x3c, 0x03, 0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x01, 0xc1, 0x3d, 
        0x07, 0x02, 0x02, 0xf2, 0x0e, 0x02, 0x02, 0x06, 0x7e, 0xc2, 0x02, 0x03, 0x1f, 0xe1, 0x01, 0x01, 
        0x07, 0x78, 0x80, 0x00, 0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x03, 0x00, 0x00, 
        0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x20, 0x1e, 0x01, 0x00, 0xc0, 0x7c, 0x07, 0x00, 
        0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x7c, 0xc0, 0x00, 0x01, 0x1e, 0xe0, 
        0x00, 0x00, 0x07, 0x38, 0x00, 0x00, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x38, 0xfe, 0xc7, 0x83, 0xff, 0xff, 0x01, 0x81, 0x03, 0x0f, 0xfe, 0xf0, 0x00, 0xff, 0xff, 0x01, 
        0x01, 0x61, 0xff, 0x9f, 0x01, 0xfe, 0xef, 0x83, 0xff, 0xff, 0x01, 0x01, 0x03, 0x07, 0xfe, 0xf8, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x19, 0xff, 0xff, 0x3b, 0x79, 0xf8, 0xcf, 0x07, 0x01, 0x00, 0xf1, 0xff, 0x0e, 
        0x0e, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x01, 0x01, 0xff, 0xff, 0x03, 0x01, 0x00, 0x80, 0xff, 0x7f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x30, 0xf0, 0xf0, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0x00, 0xf0, 0xf0, 0x30, 0x30, 0x30, 0xb0, 0xf0, 
        0x70, 0x90, 0xc0, 0xe2, 0xf3, 0xf3, 0x70, 0x30, 0x31, 0x63, 0xe3, 0xc2, 0x00, 0x83, 0xc3, 0xe3, 
        0xf3, 0xf3, 0x73, 0x33, 0x33, 0x60, 0xe0, 0x82, 0x03, 0xf3, 0xf3, 0x13, 0x63, 0xf3, 0xb1, 0xf0, 
        0xe0, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0xe0, 0xc0, 

        0x00, 0xff, 0xff, 0x30, 0x30, 0x30, 0xff, 0xff, 0x80, 0x1f, 0x7f, 0xe0, 0xc0, 0xc0, 0x9f, 0x1f, 
        0x00, 0x07, 0x1f, 0x38, 0xff, 0xff, 0x60, 0x60, 0x10, 0x80, 0xff, 0xff, 0x00, 0x0f, 0x1f, 0x38, 
        0xff, 0xff, 0x60, 0x60, 0x00, 0x80, 0xff, 0x7f, 0x00, 0xff, 0xff, 0x00, 0x00, 0x01, 0x03, 0xff, 
        0xff, 0x1c, 0x78, 0xe0, 0xc0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x04, 0xe6, 0xe7, 0x63, 
        0x60, 0x7f, 0x7f, 0x00, 0x02, 0x46, 0x7f, 0x7f, 0x00, 0x7c, 0x7f, 0x63, 0x61, 0x61, 0x60, 0x60, 
        0x60, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x47, 0x07, 0x0f, 0x3f, 0x79, 0x60, 0x40, 0x00, 0x00, 0x00, 
        0x7f, 0x7f, 0x47, 0x07, 0x0f, 0x3f, 0x71, 0x40, 0x00, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x7f, 
        0x7f, 0x40, 0x00, 0x00, 0x47, 0x7f, 0x7f, 0x00, 0x1f, 0x3f, 0x70, 0x60, 0x60, 0x7f, 0x7f, 0x40, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(oled_logo, LOGO_SIZE);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    render_logo();
    return true;
}
#endif