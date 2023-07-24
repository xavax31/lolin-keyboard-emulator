/*
 */
#define US_KEYBOARD 0

#include <BleKeyboard.h>
#include <Keypad.h>

/**************************/
/* << CONFIG */

#define VERSION "1.0.0"

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {15, 2, 0, 4};   // connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 18, 19, 21}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* >> CONFIG */
/**************************/
BleKeyboard bleKeyboard;

/** */
void setup()
{
  Serial.begin(115200);
  Serial.print("VERSION: ");
  Serial.println(VERSION);

  bleKeyboard.begin();
}

/** */
void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.println(key);
    if (bleKeyboard.isConnected())
    {
      if (key == '7')
      {
        bleKeyboard.write(KEY_LEFT_ARROW);
      }
      else if (key == '*')
      {
        bleKeyboard.write(KEY_RIGHT_ARROW);
      }
      else if (key == '0')
      {
        bleKeyboard.write(KEY_DOWN_ARROW);
      }
    }
  }
}
