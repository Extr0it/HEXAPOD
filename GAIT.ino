#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
//TENTATIVA DE GAIT(DAR MAI TREBUIE LUCRAT)
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();

#define SERVO_MIN 150
#define SERVO_MAX 600

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void miscaPicior(int coxa, int femur, int tibia) {
  // Femur: ridică la 150°
  for (int angle = 60; angle <= 150; angle++) {
    pca9685.setPWM(femur, 0, angleToPulse(angle));
    delay(10);
  }

  // Tibia: coboară la 180° și rămâne acolo
  for (int angle = 60; angle <= 180; angle++) {
    pca9685.setPWM(tibia, 0, angleToPulse(angle));
    delay(10);
  }

  // Coxa: pas înainte (90 -> 110)
  for (int angle = 90; angle <= 110; angle++) {
    pca9685.setPWM(coxa, 0, angleToPulse(angle));
    delay(10);
  }

  delay(200);

  // Coxa revine (110 -> 90)
  for (int angle = 110; angle >= 90; angle--) {
    pca9685.setPWM(coxa, 0, angleToPulse(angle));
    delay(10);
  }

  delay(200);
}

void setup() {
  pca9685.begin();
  pca9685.setPWMFreq(50);
}

void loop() {
  miscaPicior(13, 14, 15);  // Picior 1
  miscaPicior(10, 11, 12);  // Picior 2
  miscaPicior(7, 8, 9);     // Picior 3

  while (true);  // oprește loop-ul după 1 gait complet
}



