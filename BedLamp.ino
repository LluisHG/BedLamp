// Bed Lamp sketch: cycles through OFF, low, high brightness on each button press.
// Refactored to reduce unnecessary LED updates and improve button handling.

#include <FastLED.h>
#include "config.h"
#include "ButtonHandler.h"

enum LampState : uint8_t { OFF = 0, LEVEL1 = 1, LEVEL2 = 2 };

CRGB leds[NUM_LEDS];
ButtonHandler button(BUTTON_PIN); // uses INPUT_PULLUP internally

LampState state = OFF;
LampState previousAppliedState = static_cast<LampState>(255); // impossible initial value forces first apply

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  diagnosticChase();
}

void loop() {
  if (button.wasPressed()) {
    state = static_cast<LampState>((state + 1) % 3);
    Serial.printf("State changed to %u\n", state);
  }

  // Apply only if changed since last application
  if (state != previousAppliedState) {
    applyState(state);
    previousAppliedState = state;
  }
  // Small pause to avoid busy loop; button debounce handles stability
  delay(2);
}

// Light each LED in sequence to verify wiring and count. If only the first
// lights, check data arrow direction, solder joints, power distribution, and
// that data is on the DIN end.
void diagnosticChase() {
  FastLED.setBrightness(180);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(120);
    leds[i] = CRGB::Black; // turn off again for clarity
  }
  // Finally turn all on to confirm power delivery across strip
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(800);
  FastLED.clear();
  FastLED.show();
}

void applyState(LampState s) {
  switch (s) {
    case OFF:
      FastLED.setBrightness(0);
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      break;
    case LEVEL1:
      FastLED.setBrightness(INTENSITY2);
      // First 6 LEDs on, rest off
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for (int i = 0; i < 6 && i < NUM_LEDS; ++i) {
        leds[i] = BASE_COLOR;
      }
      break;
    case LEVEL2:
      FastLED.setBrightness(INTENSITY2);
      fill_solid(leds, NUM_LEDS, BASE_COLOR);
      break;
  }
  FastLED.show();
}
