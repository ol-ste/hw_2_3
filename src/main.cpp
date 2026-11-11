
#include "config.h"
#include <Arduino.h>

uint32_t red_led_last_changed    = 0;
uint32_t green_led_last_changed  = 0;
uint32_t yellow_led_last_changed = 0;

void setup() {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
}

void loop() {
    const uint32_t mills = millis();

    if (mills - red_led_last_changed >= RED_LED_BLINK_INTERVAL) {
        red_led_last_changed = mills;
        digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
    }

    if (mills - green_led_last_changed >= GREEN_LED_BLINK_INTERVAL) {
        green_led_last_changed = mills;
        digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
    }

    if (mills - yellow_led_last_changed >= YELLOW_LED_BLINK_INTERVAL) {
        yellow_led_last_changed = mills;
        digitalWrite(YELLOW_LED_PIN, !digitalRead(YELLOW_LED_PIN));
    }
}
