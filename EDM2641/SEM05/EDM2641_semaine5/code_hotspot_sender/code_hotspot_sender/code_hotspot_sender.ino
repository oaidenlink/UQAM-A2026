#include <WiFi.h>
#include <WiFiUdp.h>    // Réseau UDP
#include <OSCMessage.h> // Protocole OSC

char hotspotName[] = "patou_hotspot";
char password[] = "12345678"; //minimum 8 caractères

WiFiUDP Udp;
const IPAddress IP_ordinateur(192, 168, 4, 2);//Addresse de l'ordinateur
const int outPort = 9999;  // Port que l'ordinateur écoute

void setup() {
  WiFi.softAP(hotspotName, password); // Création du Hotspot
  Udp.begin(outPort);      // Start UDP
}

void loop() {
  int valCapteur = touchRead(15);
  
  OSCMessage msg("/capteur1");
  msg.add(valCapteur); //Message: " /capteur1 <int> "

  Udp.beginPacket(IP_ordinateur, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty(); // On vide l'espace mémoire
  delay(50); //Cadence du message (période d'échantillionnage)
}
