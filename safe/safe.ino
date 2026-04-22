#include <Servo.h>
#include "keyPad.h"
#include "trafficLight.h"
#include "buzzer.h"

byte rowPins[4] = {9, 8, 7, 6}; 
byte colPins[4] = {5, 4, 3, 0}; 
keyPad numPad(rowPins, colPins);
trafficLight tLight(11, 13, 12);
Servo servo;
buzzer buzzer(2);
int melodyFw[] = {200, 0, 200, 0, 250, 0, 300, 250, 300};
int melodyDr[] = {100, 50, 100, 50, 100, 50, 275, 100, 325};

String password = "6767";

void setup(){
  Serial.begin(9600);
  tLight.begin();
  tLight.ledOn('r');
  servo.attach(10);
  servo.write(0);
  buzzer.begin();
}
  
void loop(){
  String attempt = "";
  for (int i = 0; i < 4; i++) {
    while (true) {
      if (numPad.keyPadPressed()) {
        tLight.setData(false, true, false);
        attempt += numPad.getKey();
        Serial.println(attempt);
        buzzer.playSound(350, 150);
        while (numPad.keyPadPressed()) { delay(100); }
        break;
      }
    }

    if (attempt.indexOf('#') != -1) {
      Serial.println("Attempt cancelled/safe locked.");
      tLight.setData(true, false, false);
      servo.write(0);
      break;
    }
    delay(100);
  }

  if (attempt == password) {
    Serial.println("Password entered correctly, safe unlocked.");
    tLight.setData(true, false, false);
    servo.write(90);
    buzzer.playMelody(melodyFw, melodyDr, 9);
  }
  else {
    Serial.println("Password enterd incorrectly.");
    tLight.setData(false, false, true);
    servo.write(0);
    buzzer.playSound(200, 750);
  }

  delay(100);
}