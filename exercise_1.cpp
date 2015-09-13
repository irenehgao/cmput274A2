int p1ButtonPin = 7;
int p2ButtonPin = 6;
int LEDPins[5] = {9,10,11,12,13};
int LED[5] = { LOW,LOW,LOW,LOW,LOW};
bool pressed = false;

void setup() {

or ( int i = 0;i < 5; i++ ) {
 pinMode(LEDPins[i],OUTPUT);
 digitalWrite(LEDPin[i],LED[i]);
 }


 iMode(p1ButtonPin,INPUT);
 digitalWrite(p1ButtonPin,HIGH);
 pinMode(p2ButtonPin,INPUT);
 digitalWrite(p2ButtonPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((pressed = true) && igitalRead(p1ButtonPin) == LOW) {
      for( int i = 0; i < 5; i++ ) {
        if (LED[i] == LOW) {
          digitalWrite(LEDPins[i],HIGH);
          LED[i] == HIGH;
          break;
        }else if (LED[i] == HIGH) {
          digitalWrite(LEDPins[i] == LOW);
          LED[i] = LOW;
        }
      }
  }else if ((pressed = true) && digitalRead(p2ButtonPin) == LOW) {
    for(int i = 0; i < 5; i++) {
      if (LED[i] == LOW) {
        digitalWrite(LEDPins[i],HIGH);
        LED[i] == HIGH;
        break;
      }else if (LED[i] == HIGH){
        digitalWrite(LEDPins[i] == LOW);
        LED[i] = LOW;
      }
    }
  }

  if ((digitalRead(p1ButtonPin) == LOW)
    & digitalRead(p2ButtonPin) == LOW) {
        pressed = true;
    }else if  ((digitalRead(p1ButtonPin) == HIGH)
      & digitalRead(p2ButtonPin) == HIGH) {
        pressed = false;
      }
}
