#include <OSCBoards.h>
#include <OSCBufferedPrint.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <OSCMatch.h>
#include <OSCMessage.h>
#include <OSCTiming.h>
#include <SLIPEncodedSerial.h>
#include <SLIPEncodedTCP.h>

#include<Wire.h>

#include <WiFi.h>
#include <WiFiUdp.h>    // Réseau UDP

// METTRE LE PORT OSC À 9999 DANS TOUCH

// MPU6500
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

// wifi
char hotspotName[] = "Aidens_Magic_Rectangle";
char password[] = "12345678"; //minimum 8 caractères

WiFiUDP Udp;
const IPAddress IP_ordinateur(192, 168, 4, 2);//Addresse de l'ordinateur
const int outPort = 9999;  // Port que l'ordinateur écoute

void setup() {
  setup_WiFi();
  setup_MPU6500();

}

void loop() {
  grab_MPU6500_data();
  sendData();
  delay(50);
}

// MPU6500
void setup_MPU6500() {
  Wire.begin(21,22);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
}

void grab_MPU6500_data() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
  // Serial.print("AcX = "); Serial.print(AcX);
  // Serial.print(" | AcY = "); Serial.print(AcY);
  
  delay(10); 
}

// Wifi Hotspot
void setup_WiFi() {
  WiFi.softAP(hotspotName, password); // Création du Hotspot
  Udp.begin(outPort);      // Start UDP
}

void sendData() {
  
  OSCMessage msg("/accelX");
  msg.add(AcX); //Message: " /capteur1 <int> "

  Udp.beginPacket(IP_ordinateur, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty(); // On vide l'espace mémoire

  OSCMessage msg2("/accelY");
  msg2.add(AcY); //Message: " /capteur1 <int> "

  Udp.beginPacket(IP_ordinateur, outPort);
  msg2.send(Udp);
  Udp.endPacket();
  msg2.empty(); // On vide l'espace mémoire
  // delay(20); //Cadence du message (période d'échantillionnage)
}

