//eingebundene Libaries:
#include <IRremote.h>
#include <Servo.h>
//Pin festlegung:
//-----------Linetracker-------------------------
#define LT_R 10 //Line Tracker ((R)echts Tracker)
#define LT_M 4  //Line Tracker ((M)ittel Tracker)
#define LT_L 2  //Line Tracker ((L)inks Tracker)
//-----------Ultraschallsensor-------------------
#define ECHO_PIN A4 //Signal empfangen
#define TRIG_PIN A5 //Signal senden
//-----------Motor-Rechts------------------------
#define ENA 5  //Car-Speed
#define IN1 7   //Antrieb
#define IN2 8   //Antrieb
//-----------Motor-Links-------------------------
#define ENB 6   //Car-Speed
#define IN3 9   //Antrieb
#define IN4 11  //Antrieb
//-----------LED---------------------------------
#define LED 13  //LED pin
//-----------Infrarot--------------------s--------
#define RECV_PIN  12 //Infrarot Sensor
//-----------Bluetooth Modul---------------------
#define RX 0
#define TX 1
//-----------------------------------------------

//Variablen festlegen:
Servo myservo;

// -ALLE- Geschwindigkeiten lassen sich beim Funktionsaufruf festlegen: 
//        " funktion(Wert1, Wert2); " der Erste Wert für die Linke Seite und der Zweite für die Rechte.

//Funktion Ausnahme beim Aufruf: " cycle_to(Richtung, Wert1, Wert2); " 
// Wird keine Richtung angegeben dreht er sich im Kreis und fährt gerade aus Weiter.
//Beachte das ich mit einem Zeitbaustein gearbeitet habe und die drehrichtung daher nicht PERFEKT ist! ( Aber NAH dran!  👈(ﾟヮﾟ👈)  )

const int DEFAULT_SPEED = 200; //Standartmäßige Geschwindigkeit für Vor/Zurück // Hart/zurück-R/L 
const int DEFAULT_C_SPEED = 75; //Standartmäßige geschwindigkeit für die schwache antriebsseite in einer Kurve
const int DEFAULT_CYCLE_LS = 100; //Standartmäßige Geschwindigkeit für die Drehung auf der Stelle (Light-Site)
const int DEFAULT_CYCLE_SS = 200; //Standartmäßige Geschwindigkeit für die Drehung auf der Stelle (Strong-Site)
const char *DEFAULT_DIRECTION = "forward"; //Standartmäßige Fahrtrichtung 
long myTimer = 0;

void setup(){
//-----------------------------------------------
    myservo.attach(3);
    myservo.write(99);// dreht die Servo auf Referenz -> 90° 
//----------------------L298N--------------------
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
//-----------------------------------------------
}

void loop(){

}