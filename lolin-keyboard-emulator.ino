/*
 */
#define US_KEYBOARD 0

#include <BleKeyboard.h>
#include <Keypad.h>

/**************************/
/* << CONFIG */

#define VERSION "1.0.0"

// KEYPAD
const byte ROWS = 4; // num of rows
const byte COLS = 4; // num of columns

// keys disposition
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
      // adapt here to send different keys values
      if (key == '1')
      {
        bleKeyboard.write(KEY_NUM_1);
      }
      else if (key == '2')
      {
        bleKeyboard.write(KEY_NUM_2);
      }
      else if (key == '3')
      {
        bleKeyboard.write(KEY_NUM_3);
      }
      else if (key == '4')
      {
        bleKeyboard.write(KEY_NUM_4);
      }
      else if (key == '5')
      {
        bleKeyboard.write(KEY_NUM_5);
      }
      else if (key == '6')
      {
        bleKeyboard.write(KEY_NUM_6);
      }
      else if (key == '8')
      {
        bleKeyboard.write(KEY_NUM_8);
      }
      else if (key == '9')
      {
        bleKeyboard.write(KEY_NUM_9);
      }
      else if (key == '7')
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
      else if (key == 'A')
      {
        bleKeyboard.write('Q');
      }
      else if (key == '#')
      {
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press('@');
        bleKeyboard.releaseAll();
      }
      else
      {
        bleKeyboard.write(key);
      }
    }
  }
}
