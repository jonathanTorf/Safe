class buzzer {
  private:
    int buzzerPin;

  public:
    buzzer(int pin) { buzzerPin = pin; }

    void begin() { 
      pinMode(buzzerPin, OUTPUT); 
    }

    void playSound(int fw, int dr) {
      tone(buzzerPin, fw);
      delay(dr);
      noTone(buzzerPin);
    }

    void playMelody(int fw[], int dr[], int size) {
      for (int i = 0; i < size; i++) {
        playSound(fw[i], dr[i]);
      }
    }
};