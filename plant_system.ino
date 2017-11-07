#include <Servo.h>

const unsigned int waterSensor = A4;
const unsigned int moistureSensor = A5;

const unsigned int servoPin = 11;
const unsigned int ledPin = 13;

Servo servo;

void setup() {
  Serial.begin(9600);
  
  servo.attach(servoPin);
  servo.write(0);
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  const unsigned int water = analogRead(waterSensor);
  const unsigned int moisture = analogRead(moistureSensor);
  
  Serial.print(water);
  Serial.print(" ");
  Serial.println(moisture);
  
  if (water <= 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  if (moisture <= 200) {
    servo.write(70);
    delay(100);
    servo.write(0);
    delay(100);
  }
  
  delay(1000);
}
