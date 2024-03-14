//eingebundene Libaries:
#include <Servo.h>
#include <IRremote.h>
//Pin festlegung:
//-----------Linetracker-------------------------
#define LT_R 10 //Line Tracker ((R)echts Tracker)
#define LT_M 4  //Line Tracker ((M)ittel Tracker)
#define LT_L 2  //Line Tracker ((L)inks Tracker)
//-----------Ultraschallsensor-------------------
#define ECHO_PIN A4 //Signal empfangen
#define TRIG_PIN A5 //Signal senden
//-----------Motor-Rechts------------------------
#define ENA 5   //oder Pin 5 Car-Speed
#define IN1 7   //Antrieb
#define IN2 8   //Antriebn
//-----------Motor-Links-------------------------
#define ENB 6   //Car-Speed
#define IN3 9   //Antrieb
#define IN4 11  //Antrieb
//-----------LED---------------------------------
#define LED 13  //LED pin
//-----------Infrarot----------------------------
#define RECV_PIN  12 //Infrarot Sensor
//-----------Bluetooth Modul---------------------
#define RX 0
#define TX 1
//-----------------------------------------------
#define carSpeed 150

//Variablen festlegen:
Servo myservo;
long entfernung = 0;
long zeit = 0;
//-----------Servomotor code---------------------

//geht schritt für schritt alle positionen durch 0 - 180 und zurück 180 - 0
void servomotor()
{
  int i;
  for (i=0; i<=180; i++)
  {
    myservo.write(i);
    delay(20);
      entfernung_berechnen(sensor());
  }
  for (i=180; i>=0; i--)
  {
    myservo.write(i);
    delay(20);
    entfernung_berechnen(sensor());
  }
}
//-----------------------------------------------

//-----------Ultraschallsensor code---------------------
int sensor()
{
  //denn Sender Kurz ausschalten damit keine Störungen da sind
  digitalWrite(TRIG_PIN,LOW);
  delay(5);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  zeit = pulseIn(ECHO_PIN, HIGH);
  return zeit;
}

//berechnung der Entfernung zu einem Objekt
bool entfernung_berechnen(int travel_time)
{
  //travel_time/2 da wir nur einmal die Strecke brauchen
  entfernung = (travel_time/2) * 0.03432;
  Serial.println(entfernung);
  if (entfernung <= 10){
    //für das bremsen vor einem objekt und darauffolgendem rückwärtsfahren
    return true;
  }
  else{
    return false;
  }
}


//-----------------------------------------------

void setup(){
  Serial.begin(9600);
    myservo.attach(3); //servopin
    myservo.write(99);// dreht die Servo auf Referenz -> 90° 
    pinMode(TRIG_PIN, OUTPUT); //setzt den sender vom Ultraschallsensor auf output
    pinMode(ECHO_PIN, INPUT);  //setzt den empfäner vom Ultraschallsensor auf input
}

void loop(){
servomotor();
}