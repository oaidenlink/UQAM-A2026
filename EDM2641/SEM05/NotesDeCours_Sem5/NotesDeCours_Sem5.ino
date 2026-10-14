// voir dans les notes de cours le Gyroscope (& comm i2C) et l'Accéléromètre

/////////////////////////
//// Sonar (Trig/Echo)

// voir dans les notes de cours le Seuil Hysteresis
// voir dans les notes de cours le Lissage d'un signal

const int TrigPin = 18;
const int EchoPin = 19;
float distance;

void setup() {
  Serial.begin(115200);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  digitalWrite(TrigPin, LOW);
}

void loop() {
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  distance = pulseIn(EchoPin, HIGH) / 58.8;

  Serial.println(distance);
  delay(50);
}

/////////////////////////
//// servo moteur
// #include <ESP32Servo.h>

// Servo monServo;

// int pinServo = 18;
// int pinCapteur = 4;
// int positionServo = 0;
// int valeurCapteur = 0;

// void setup()
// {
//   monServo.attach(pinServo);
// }

// void loop()
// {
//   valeurCapteur = analogRead(pinCapteur);
//   positionServo = map(valeurCapteur, 0, 4095, 0, 180);
//   monServo.write(positionServo);
// }



///////////////////////////////////////
//// test de base
// const int pinServo = 18;
// int i;

// void setup() {
//   monServo.attach(pinServo);
// }

// void loop() {
//   for(i = 0; i <= 180; i++)
//   {
//     monServo.write(i);
//     delay(20);
//   }

//   for (i=0; i<=180; i++)
//   {
//     monServo.write(180-i);
//     delay(20);
//   }
// }
