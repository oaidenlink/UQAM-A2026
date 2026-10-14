const int pinCapteur = 4;
const int pinLED = 2;
int valeurCapteur;
int valeurLED;

void setup() {
  // remplacez 9600 par 115200 la communiccation se fera plus vite
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  valeurCapteur = analogRead(pinCapteur);
  Serial.println(valeurCapteur); // faut le limiter entre 100 et 600

  valeurCapteur = constrain(valeurCapteur, 100, 600);
  valeurLED = map(valeurCapteur, 100, 600, 0, 255);
  analogWrite(pinLED, valeurLED);
  delay(20);
}
