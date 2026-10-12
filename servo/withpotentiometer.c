
#include <ESP32Servo.h>

#define SERVO_PIN 26
#define POTENTIOMETER_PIN 34

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);

  int pos = map(analogValue, 0, 4095, 0, 180);

  servoMotor.write(pos);

  Serial.print("Potentiometer Value: ");
  Serial.print(analogValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(pos);

  delay(15);
}
