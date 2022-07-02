#include <Arduino.h>

const int ledPin = 12;
const int dotDelay = 400;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
Serial.println("type the morse code to be displayed");
}
  
void loop() {
  /*
  digitalWrite(ledPin, HIGH);
  delay(dotDelay);
  digitalWrite(ledPin,LOW);
  delay(dotDelay*2);
  */
  if (Serial.available() > 0){
    
  int ascii_morse = Serial.read();
  while (ascii_morse != '0' && ascii_morse != '\0')
  {
    
    if(ascii_morse == '.')
    {
      digitalWrite(ledPin, HIGH);
      delay(dotDelay);
    }
    else if (ascii_morse == '-')
    {
      digitalWrite(ledPin, HIGH);
      delay(dotDelay*2);
    }
    else if (ascii_morse == ' ')
    {
      delay(dotDelay*3);
    }
    ascii_morse = Serial.read();
     digitalWrite(ledPin, LOW);
     delay(dotDelay/2); 
  }
  
  }
}
