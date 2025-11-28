#pragma once
#include <Arduino.h>

// Simple debounced button handler.
// Usage: call wasPressed() each loop; returns true exactly once per press.
class ButtonHandler {
public:
  explicit ButtonHandler(uint8_t pin, unsigned long debounceMs = 50)
    : pin_(pin), lastStableState_(HIGH), lastReading_(HIGH), lastChangeMs_(0), debounceMs_(debounceMs) {
    pinMode(pin_, INPUT_PULLUP);
  }

  bool wasPressed() {
    int reading = digitalRead(pin_);

    if (reading != lastReading_) { // any edge -> reset timer
      lastChangeMs_ = millis();
      lastReading_ = reading;
    }

    // Has the reading been stable long enough to consider it real?
    if ((millis() - lastChangeMs_) >= debounceMs_ && reading != lastStableState_) {
      lastStableState_ = reading;
      if (reading == LOW) { // active-low press
        return true;
      }
    }
    return false;
  }

private:
  uint8_t pin_;
  int lastStableState_;
  int lastReading_;
  unsigned long lastChangeMs_;
  unsigned long debounceMs_;
};
