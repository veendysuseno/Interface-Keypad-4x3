# Arduino Keypad Input Reader

## Description

This project demonstrates how to interface a 4x3 matrix keypad with an Arduino. It reads the keypresses from the keypad and displays them on the Serial Monitor. This can be used for various input systems like password entries, menu navigation, or simple number input.

## Components

- Arduino Uno
- 4x3 Matrix Keypad
- Jumper wires
- Breadboard

## Libraries Required

- **Keypad.h**: For handling the matrix keypad.

## Wiring Diagram

| Keypad Pin | Arduino Pin |
| ---------- | ----------- |
| Row 1      | 2           |
| Row 2      | 3           |
| Row 3      | 4           |
| Row 4      | 5           |
| Column 1   | 6           |
| Column 2   | 7           |
| Column 3   | 8           |

## Code

```cpp
#include <Keypad.h>

const byte ROWS = 4; // 4 rows
const byte COLS = 3; // 3 columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // Row pins connected to Arduino
byte colPins[COLS] = {6, 7, 8};    // Column pins connected to Arduino

// Initialize keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Set baud rate to 9600 bps
}

void loop() {
  char key = keypad.getKey(); // Read the key press

  if (key != NO_KEY) { // If a key is pressed
    Serial.println(key); // Send key value to the Serial Monitor
  }
}
```

## How It Works

1. Keypad Setup: The 4x3 keypad is connected to the Arduino using digital pins. The Keypad library is used to map the keypad layout and manage keypresses.

2. Serial Communication: When a key is pressed, the corresponding character (from 1 to 9, 0, \*, or #) is sent to the Serial Monitor using Serial.println().

3. Main Loop: The loop() continuously checks for key presses using the keypad.getKey() function, and if a valid key is pressed, it is displayed on the Serial Monitor.

## Usage

1. Connect the components according to the wiring diagram.
2. Upload the code to your Arduino.
3. Open the Serial Monitor (set to 9600 baud rate) to view the keypresses.

## Applications

This project can be used in various input systems, including:

- Keypad-based security systems (e.g., door locks)
- Menu navigation systems for selecting options
- Number inputs for calculators or other applications
