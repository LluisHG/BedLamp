#include <Arduino.h>

// Pin definitions
const int BUTTON_PIN = 2;    // Push button connected to pin 2
const int LED_PIN = 13;      // LED/Lamp connected to pin 13

// Variables
bool lampState = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void loop() {
    bool reading = digitalRead(BUTTON_PIN);

    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        static bool buttonState = HIGH;
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == LOW) {
                lampState = !lampState;
                digitalWrite(LED_PIN, lampState ? HIGH : LOW);
            }
        }
    }

    lastButtonState = reading;
}
