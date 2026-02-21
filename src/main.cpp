#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded RGB LED Control (Digital + PWM)
 * @author Piyush-2909singh
 * @date 2026-02-21
 *
 * @details
 * Controls RGB LED using digital ON/OFF
 * and analog PWM brightness control.
 */

// Hardware Definitions
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

/**
 * @brief System initialization for RGB pins and serial communicati
 */
void setup() {
    Serial.begin(9600);

    // Configure RGB pins as OUTPUT
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.println("System: RGB Control Active (Digital & PWM Mode)");
}

/**
 * @brief Main execution loop demonstrating color cycling and mixing.
 */
void loop() {
    // -------- DIGITAL MODE --------
    // Simple ON/OFF for Red
    digitalWrite(RED_PIN, HIGH);
    Serial.println("Mode: Digital - Red ON");
    delay(500);

    digitalWrite(RED_PIN, LOW);
    Serial.println("Mode: Digital - Red OFF");
    delay(500);

    // -------- ANALOG (PWM) MODE --------
    // Mixing colors (0-255 range)
    Serial.println("Mode: PWM - Color Mixing");

    // Example: Create a soft Purple (Red + Blue)
    analogWrite(RED_PIN, 150);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 200);
    delay(1000);

    // Example: Create a soft Teal (Green + Blue)
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 180);
    analogWrite(BLUE_PIN, 180);
    delay(1000);

    // Reset all for next loop
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
}