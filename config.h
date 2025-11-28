#pragma once
#include <FastLED.h>

// LED settings
#define NUM_LEDS   14
#define DATA_PIN   4      // D2 (GPIO4) ESP8266
#define LED_TYPE   WS2812B
#define COLOR_ORDER GRB

// Button
#define BUTTON_PIN 14     // D5 (GPIO14)

// Brightness levels
#define INTENSITY1  80    // adjust to taste
#define INTENSITY2  200

// Default LED color
#define BASE_COLOR CRGB(180,160,140)   // warm white
