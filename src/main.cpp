#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

// Define pins numbers for LCD connections
#define RS_PIN 7
#define EN_PIN 6
#define D4_PIN 5
#define D5_PIN 4
#define D6_PIN 3
#define D7_PIN 2
#define PUSH_BUTTON_PIN 8

// Initialize LiquidCrystal object with pin numbers
LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);


// Array to store messages for different counter states
const char* messages[] = {
    "Allahu Akbar :",
    "Subhanallah :",
    "El Hamdoulilah :",
    "LastMessage" // Last message is not displayed !
};

// Variables for counter and button states
int counter, counterState = 0;
bool previousButtonLevel, currentButtonLevel = LOW;
bool lastMessageReached = false;

// Function to display message on LCD
void displayMessage(const char* message, int value = -1) {
    // Clear LCD
    lcd.clear();
    // Set cursor to start of first line
    lcd.setCursor(0, 0);
    // Print message on LCD
    lcd.print(message);
    // If a value is provided, print it on the second line
    if (value != -1) {
        lcd.setCursor(7, 1);
        lcd.print(value);
    }
}

// setup function, runs once at the begining
void setup() {
    // Initialize LCD
    lcd.begin(16, 2);
    // set push button pin as input with pull-up resistor
    pinMode(PUSH_BUTTON_PIN, INPUT_PULLUP);
}

// Loop function, runs repeatedly
void loop() {
    // Read current and previous button states
    previousButtonLevel = currentButtonLevel;
    currentButtonLevel = digitalRead(PUSH_BUTTON_PIN);

    // Check if the button is pressed
    if (currentButtonLevel == LOW && previousButtonLevel == HIGH) {
        // Increment counter if button is pressed
        counter++;

        // If we're at the last message and the button is pressed, reset counter and message state
        if (counterState == sizeof(messages) / sizeof(messages[0]) - 1) {
            lastMessageReached = true;
        } else if (counter == 34) { // If counter reaches 34, change message state
            counter = 0;
            counterState = (counterState + 1) % (sizeof(messages) / sizeof(messages[0]) - 1);
        }
    }

    // Display message based on counter state
    if (lastMessageReached && currentButtonLevel == LOW && previousButtonLevel == LOW) {
        counterState = 0;
        counter = 0;
        lastMessageReached = false;
    }
    displayMessage(messages[counterState], counter);

    // Delay for stability
    delay(100);
}