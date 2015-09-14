/**
  name of file: Exercise 1:counting lights;
  name: Zihan(Irene) Gao; section: CMPUT 274 A2
  created on 12th, September, 2015;
  code copied from:Arduino Intro Labs for Tangible Computing
  (http://ugweb.cs.ualberta.ca/~c274/web/ArduinoIntro/section/lab_TugOfWar.htm)
  quick description:  make the LED blink and change the status of LEDS by pressing the buttons
  */

#include <Arduino.h>

int p1ButtonPin = 7;
//the increment pushbutton is attached to this pin
int p2ButtonPin = 6;
//the decrement pushbutton is attached to this pin
int LEDPins[5] = {9,10,11,12,13};
//the LEDs are connected to these pins
int LED[5] = {LOW, LOW, LOW, LOW, LOW};
//LEDs status


void setup() {
  // use a for loop to initialize each pin as an output:
  for ( int i = 0;i <= 4; i++ ) {
    pinMode(LEDPins[i],OUTPUT);
    digitalWrite(LEDPins[i],LED[i]);
  }
  // initialize the p1button pin as an input:
  pinMode(p1ButtonPin,INPUT);
  //set increment button to input;
  digitalWrite(p1ButtonPin, HIGH);
  // initialize the p2button pin as an input:
  pinMode(p2ButtonPin, INPUT);
  //set decrement button to input
  digitalWrite(p2ButtonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(150);
  // delay time in order to control the speed of blinking
  if (digitalRead(p1ButtonPin) == LOW) {
    //if the increment button is pressed
      for( int i = 0; i <= 4; i++ ) {
        //loop from the lowest pin to the highest
        if (LED[i] == LOW) {
          //if the LEDs are off, turn them on
          LED[i] = HIGH;
          digitalWrite(LEDPins[i], LED[i]);
          break;
          // break looping
        }else if (LED[i] == HIGH) {
          // if the LEDS are on, thern them off
          LED[i] = LOW;
          digitalWrite(LEDPins[i], LED[i]);
        }
      }
  }else if ( digitalRead(p2ButtonPin) == LOW) {
    //if the decrement buttonis pressed
    for(int i = 0; i <= 4; i++) {
      //loop from the lowest pin to the highest
      if (LED[i] == LOW){
        // if the LEDS are off, turn them on
        LED[i] = HIGH;
        digitalWrite(LEDPins[i], LED[i]);
      }else if (LED[i] == HIGH){
        // if LEDs are on, turn them off
        LED[i] = LOW;
        digitalWrite(LEDPins[i], LED[i]);
        break;
        // break looping
    }
  }
}
}
