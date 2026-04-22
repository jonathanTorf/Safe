class trafficLight {
  private:
    int g, y, r;

  public:
    trafficLight(int tg, int ty, int tr) {
      g = tg;
      y = ty;
      r = tr;
    }

    void begin() {
      pinMode(g, OUTPUT);
      pinMode(y, OUTPUT);
      pinMode(r, OUTPUT);
    }

    void ledOn(char light) {
      if (light == 'g') digitalWrite(g, HIGH);
      else if (light == 'y') digitalWrite(y, HIGH);
      else if (light == 'r') digitalWrite(r, HIGH);
      else {
        Serial.println("Invalid char(");
        Serial.print(light);
        Serial.print(") from trafficLight.ledOn");
      }
    }

    void ledOff(char light) {
      if (light == 'g') digitalWrite(g, LOW);
      else if (light == 'y') digitalWrite(y, LOW);
      else if (light == 'r') digitalWrite(r, LOW);
      else {
        Serial.println("Invalid char(");
        Serial.print(light);
        Serial.print(") from trafficLight.ledOff");
      }
    }

    void allOff() {
      ledOff('g');
      ledOff('y');
      ledOff('r');
    }

    void setData(bool gb, bool yb, bool rb) {
      allOff();
      if (gb) ledOn('g');
      if (yb) ledOn('y');
      if (rb) ledOn('r');
    }
};