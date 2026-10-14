/////////////////////////////////
// EVALUATION 1 - EXERCICE 2
// AIDEN OLIVEIRA OLIA87280306
/////////////////////////////////

const int pinLEDr = 27;
const int pinLEDg = 14;
const int pinLEDb = 12;

const int pinJoystickX = 15;
const int pinJoystickY = 4;
const int pinJoystickBtn = 5;

int valeurJoystickX;
int valeurJoystickY;

int valeurLEDb;
int valeurLEDr;
int valeurBright;

bool btnState = 1;
bool oldBtnState = 1;
bool ledState = 1;

void setup() {
  Serial.begin(9600);
  
  pinMode(pinLEDr, OUTPUT);
  pinMode(pinLEDb, OUTPUT);
  pinMode(pinLEDg, OUTPUT);

  pinMode(pinJoystickBtn, INPUT);
  digitalWrite(pinLEDb, ledState);
  digitalWrite(pinLEDr, ledState);
  digitalWrite(pinLEDg, 0);
}

void loop() {
    // joystick intensité lumineuse
  valeurJoystickY = analogRead(pinJoystickY);
  valeurBright = map(valeurJoystickY, 0, 4095, 0, 255);

    // joystick rouge à bleu
  valeurJoystickX = analogRead(pinJoystickX);
  valeurLEDb = map(valeurJoystickX, 0, 4095, 0, valeurBright);
  valeurLEDr = map(valeurJoystickX, 0, 4095, valeurBright, 0);
  analogWrite(pinLEDb, valeurLEDb * ledState);
  analogWrite(pinLEDr, valeurLEDr * ledState);
  analogWrite(pinLEDg, 0);
  delay(20);
  // merci Marianne pour le coup de main

    // joystick bouton on et off
  btnState = digitalRead(pinJoystickBtn);
  if (btnState == HIGH && oldBtnState == LOW) {
      ledState = !ledState;
      delay(100);
      // merci à Alexandre pour le coup de main
  }
  oldBtnState = btnState;
}
