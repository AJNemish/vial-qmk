#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Columns 5-8 on Pro Micro footprint => GPIO5-GPIO8
#define MATRIX_COL_PINS { GP5, GP6, GP7, GP8 }

// Row0 = pin9 => GPIO9
// Row1-Row3 assumed routed to CI/CO/21 footprint pads => GPIO20/23/21
#define MATRIX_ROW_PINS { GP9, GP20, GP23, GP21 }

#define DIODE_DIRECTION COL2ROW

// Encoders (replace GPxx if your footprint pins map differently)
#define ENCODERS_PAD_A { GP13, GP15, GP17 }
#define ENCODERS_PAD_B { GP14, GP16, GP18 }
#define ENCODERS_PAD_RESOLUTION 4

// Your external WS2812 DIN from A3 => GPIO29
#define RGBLIGHT_LED_COUNT 1
#define RGB_DI_PIN GP29

// ---- Vial
#define VIAL_KEYBOARD_UID {0x12,0x34,0x56,0x78,0x9A,0xBC,0xDE,0xF0}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
