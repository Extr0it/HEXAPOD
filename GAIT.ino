#include <Wire.h> // biblioteca pentru a comunica cu PCA9685
#include <Adafruit_PWMServoDriver.h> // biblioteca pentru a controla PCA9685 (cele 16 canale)

//TENTATIVA DE GAIT(DAR MAI TREBUIE LUCRAT) (gait inseamna 3 picioare mergand 3 pauza si tot asa)

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(); // initializam pca9685 ul, daca sunt 2 trebuie setata adresa implicit la fiecare, pentru cea basic e 0x40

#define SERVO_MIN 150 // frecventele minime pe care servo ul le poate atinge (pulse lenghts) (echivalent cu 0 grade)
#define SERVO_MAX 600 // frecventele maxime in pulse lenght (echivalent cu 180 de grade) aproximativ

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);   //map() este o funcție Arduino care convertește un număr dintr-un interval în alt interval.
}  // functia asta ne permite sa lucram direct cu gradele, iar ea la randul ei o converteste in semnale pe care ii le transmite mai departe servo urilor prin pca9685

void miscaPicior(int coxa, int femur, int tibia) {

  
  // Femur: ridica la 150 de grade
  for (int angle = 60; angle <= 150; angle++) {  /// misca de la 60 la 150 de grade
    pca9685.setPWM(femur, 0, angleToPulse(angle)); // functia setPWM este prestabilita de librarie, are nevoie de 3 parametrii, canalul,
    delay(10); // este 0 (dupa femur) deoarece reprezinta efectul ca NU ESTE niciun delay, si apelam functia angletopulse declarata anterior, pentru a converti unghiurile reale in semnale pwm
  } // 10 milisecunde intre fiecare miscare a servo ului

  // Tibia: coboară la 180° și rămâne acolo
  for (int angle = 60; angle <= 180; angle++) {
    pca9685.setPWM(tibia, 0, angleToPulse(angle));    // exact aceeasi chestie ca si mai sus doar ca pt alt canal denimit tibie
    delay(10);
  }

  // Coxa: pas înainte (90 -> 110)
  for (int angle = 90; angle <= 110; angle++) {
    pca9685.setPWM(coxa, 0, angleToPulse(angle));  // la fel pt COXA
    delay(10);
  }

  delay(200); /// dupa ce s au realizat cele 3 loops, pauza de 200 de ms, adica 0.2 secunde

  // Coxa revine (110 -> 90)
  for (int angle = 110; angle >= 90; angle--) {
    pca9685.setPWM(coxa, 0, angleToPulse(angle));  // procesul de revenire, exact aceeasi chestie doar ca de data asta DECREMENTAM ANGLE UL cu 1
    delay(10);
  }

  delay(200); // din nou delay de 0.2 sec
}

void setup() {
  pca9685.begin(); // initializeaza comunicarea I2C cu pca9685
  pca9685.setPWMFreq(50); // ⚙ Setează frecvența PWM la 50 Hz
  //  - 50 Hz = 50 impulsuri pe secundă
  //  - asta înseamnă că fiecare ciclu durează 20 ms
  //  - frecvența standard pentru controlul servomotoarelor
}

void loop() {
  miscaPicior(13, 14, 15);  // Picior 1  APELAM FUNCTIA PT CANALELE ASTEA (canalele de pe pca9685 care sunt linkuite la servo uri)
  miscaPicior(10, 11, 12);  // Picior 2 // apelam fct pt al doilkea picior
  miscaPicior(7, 8, 9);     // Picior 3 // pt al treilea, cu canalele respective

  while (true);  // opreste loop-ul după 1 gait complet
}



