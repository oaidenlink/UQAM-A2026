const int pinLED = 2;
const int pinBtn = 5;

bool btnState = 0;
bool oldBtnState = 0;
bool ledState = 0;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinBtn, INPUT);
  digitalWrite(pinLED, ledState);
}

void loop() {
  btnState = digitalRead(pinBtn);

  if (btnState == HIGH && oldBtnState == LOW) {

      ledState = !ledState;
      digitalWrite(pinLED, ledState);
      delay(100);

  }

  oldBtnState = btnState;
}

//////// pour les inputs pullup (D2, D4, D5, D12, D13, D14, D15, D25, D26, D27 seulement) ////////
/// dans setup:
// pinMode(pinBtn, INPUT_PULLUP);
//
/// dans LOOP
// btnState = !digitalRead(pinBtn);
// digitalWrite(pinLED, btnState);