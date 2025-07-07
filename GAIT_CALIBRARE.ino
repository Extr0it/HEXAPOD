
/*
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


*/
/*
// calibrare
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();

#define SERVO_MIN 150  // puls minim (~0°)
#define SERVO_MAX 600  // puls maxim (~180°)
#define CHANNEL 15     // ultimul canal

void setup() {
  pca9685.begin();
  pca9685.setPWMFreq(50);  // 50 Hz pentru servo

  // Calculează poziția pentru 90°
  int middle = (SERVO_MIN + SERVO_MAX) / 2;
  pca9685.setPWM(CHANNEL, 0, middle);
}

void loop() {
  // Nu face nimic în loop
}
*/




// MISCARE A UNUI SINGUR PICIOR
/*
//#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// initializam modulul PCA9685 (pt servo-uri)
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();

// valorile min si max ale pulsului pt servo
#define SERVO_MIN 150
#define SERVO_MAX 600

// functie ca sa transformi gradele (0-180) in puls pt pca
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

bool executat = false;  // flag ca sa se execute o singura data

void setup() {
  pca9685.begin();         // pornim pca-ul
  pca9685.setPWMFreq(50);  // 50Hz, frecventa standard pt servo
}

void loop() {
  if (!executat) {  // intra aici doar o data
    // misca canalul 13 (coxa maybe?) de la 50 la 100 grade
    for (int angle = 50; angle <= 100; angle++) {
      pca9685.setPWM(13, 0, angleToPulse(angle));
      delay(30);  // delay mic sa nu tremure
    }

    delay(300); // scurta pauza

    // misca canalul 14 (femur?) de la 30 la 160 grade
    for (int angle = 30; angle <= 160; angle++) {
      pca9685.setPWM(14, 0, angleToPulse(angle));
      delay(30);
    }

    delay(300); // pauza din nou

    // canalul 15 (tibia maybe?) se duce direct la 180 grade
    pca9685.setPWM(15, 0, angleToPulse(180));

    executat = true;  // ca sa nu mai repete, ruleaza doar o data
  }
}
*/



