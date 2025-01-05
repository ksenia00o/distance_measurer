#include <LiquidCrystal.h>
#include <HCSR04.h>

const int trigPin = 7;
const int echoPin = 6;
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin); /* default max distance of 400cm */

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(2,16);
  Serial.begin(9600); //data transfer
}

void loop() {
   
  lcd.setCursor(0, 1);
  lcd.clear();

  float distance = distanceSensor.measureDistanceCm();
  lcd.print(distance, 1); /* with 1 digit after the decimal point */
  lcd.print(" cm");
  delay(500);
}
