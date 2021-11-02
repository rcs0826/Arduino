#include <Servo.h>

const int potGarra = A5;
const int potBase = A4;

Servo garra;
Servo base;

int readAnalog = 0;
int readAnalogBase = 0;

void setup() {
  Serial.begin(9600);
  garra.attach(7);
  garra.write(0); 

  base.attach(6);
  base.write(0); 
}

void loop() {
  readAnalog = analogRead(potGarra);
  readAnalogBase = analogRead(potBase);

  readAnalog = map(readAnalog, 0, 1023, 0, 179);
  readAnalogBase = map(readAnalogBase, 0, 1023, 0, 179);
  // Seta o sinal de controle de acordo com o potGarra
  garra.write(readAnalog);  
  base.write(readAnalogBase);  

  //Serial.println(readAnalog);
  delay(500);
}
