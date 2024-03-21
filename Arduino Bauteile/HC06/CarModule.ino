#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // Lesen von der seriellen Schnittstelle des Bluetooth-Moduls
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.write(c); // Daten auf der seriellen Schnittstelle des Arduino ausgeben
  }

  // Lesen von der seriellen Schnittstelle des Arduino
  if (Serial.available()) {
    char c = Serial.read();
    BTSerial.write(c); // Daten an das Bluetooth-Modul senden
  }
}
