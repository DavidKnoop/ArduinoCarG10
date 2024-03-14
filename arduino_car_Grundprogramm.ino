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
#define ENA 3   //oder Pin 5 Car-Speed
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