/*

*/

#include <Arduino.h>

int p1ButtonPin = 7;
int p2ButtonPin = 6;
int LEDPins[5] = {9,10,11,12,13};
int LED[5] = {LOW, LOW, LOW, LOW, LOW};
bool pressed = false;

void setup() {
  for ( int i = 0;i <= 4; i++ ) {
    pinMode(LEDPins[i],OUTPUT);
    digitalWrite(LEDPins[i],LED[i]);
  }

  pinMode(p1ButtonPin,INPUT);
  digitalWrite(p1ButtonPin, HIGH);
  pinMode(p2ButtonPin, INPUT);
  digitalWrite(p2ButtonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(300);
  if ((pressed = true) && (digitalRead(p1ButtonPin) == LOW)) {
      for( int i = 0; i <= 4; i++ ) {
        if (LED[i] == LOW) {
          LED[i] = HIGH;
          digitalWrite(LEDPins[i], HIGH);
          break;
        }else if (LED[i] == HIGH) {
          LED[i] = LOW;
          digitalWrite(LEDPins[i], LOW);
        }
      }
  }else if ((pressed = true) && (digitalRead(p2ButtonPin) == LOW)) {
    for(int i = 0; i <= 4; i++) {
      if (LED[i] == LOW) {
        LED[i] = HIGH;
        digitalWrite(LEDPins[i], HIGH);
      }else if (LED[i] == HIGH){
        LED[i] = LOW;
        digitalWrite(LEDPins[i], LOW);
        break;
      }
    }
  }

  if ((digitalRead(p1ButtonPin) == LOW)
    && (digitalRead(p2ButtonPin) == LOW)) {
        pressed = true;
    }else if ((digitalRead(p1ButtonPin) == HIGH)
      && (digitalRead(p2ButtonPin) == HIGH)) {
        pressed = false;
      }
}
