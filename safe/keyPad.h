#include <Keypad.h>

class keyPad {
  private:
    byte rowPins[4]; 
    byte colPins[4]; 

    char hexaKeys[4][4] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };

  public:
    keyPad(byte rows[4], byte cols[4]) {
      for (int i = 0; i < 4; i++) {
        rowPins[i] = rows[i];
        colPins[i] = cols[i];
      }
    }

    char getKey() {
      Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
      char customKey = customKeypad.getKey();
      if (customKey) return customKey;
      else return 'n';
    }

    bool keyPadPressed() {
      Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
      char customKey = customKeypad.getKey();
      if (customKey) return true;
      else return false;
    }
};