# Arduino LCD Display with Counter

***This Arduino sketch allows you to display multiple messages along with a counter on an LCD screen. The counter increments each time a push button is pressed. After reaching a certain value, the displayed message changes. Additionally, when the last message is reached, pressing the button again resets the counter and starts displaying messages from the first one.***

## Components Used
- Arduino Uno board (e.g., Arduino Uno)
- LCD screen compatible with LiquidCrystal library
- Push Button

## Libraries Used
1. **On VSCODE platformIO :**
   - **Arduino.h :** The Arduino Library, it basically in the file when you create the platformIO project
   - **LiquidCrystal.h :** This library allows interfacing with character LCD based on the Hitachi HD44780 (or compatible) chipset, which is common type of LCD.
   - **Wire.h :** This library provides the necessary functions for I2C

2. **Tinkercad :**
   - **Adafruit_LiquidCrystal.h :** this is the same library is the same as the based arduino library.


## How It Works
1. **Initialization :** The code initializes the LCD screen and sets up the push button pin as an input with a pull-up resistor.
2. **Message Array :** Messages to be displayed on the LCD screen are stored in an array. The last message in the array is not displayed initially.
3. **Counter :** A counter variable keeps track of the number of times the push button is pressed. Once the counter reaches a certain value (in this case, 34), it resets, and the displayed messages changes.
4. **Last Message Handling :** When the last message is reached, pressing the button again resets the counter and starts displaying messages from the first one.

## Usage
- Upload the sketch to your Arduino board using the Arduino IDE or any compayible software.
- Ensure the connections are correctly set up according to the wiring specified in the code.
- Power up the Arduino board.
- Press the push button to increment the counter.
- Observe the LCD screen to see the displayed messages change as the counter reaches its predefined value. When the last message is reached, pressing the button again resets the counter and starts displaying messages from the first one.

## Circuit Diagram
![](https://i.ibb.co/zmnBhNz/Capture-d-cran-2024-05-08-145812.jpg)

## Note
- You can customize the messages displayed on the LCD screen by modifying the `messages` array in the code.
- Adjust the value at which the counter resets and triggers a change in the displayed message by modifying the comparison condition (`if (counter == 34)`) in the code.
- If you encounter flashing or flickering on the LCD screen, consider adjusting the code to minimize screen updates or check the quality of the LCD screen and connections.
- Ensure stable connections between the Arduino board, LCD screen, and push button to prevent electromagnetic interferences.
- Contributions and feedback are welcome. Feel free to submit issues or pull requests on Github.

[Click to watch](https://youtu.be/Ui4lkuP0W4w)
