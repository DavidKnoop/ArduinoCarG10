// eingebundene Libaries:
#include <IRremote.h>
#include <Servo.h>
// Pin festlegung:
//-----------Linetracker-------------------------
#define LT_R 10 // Line Tracker ((R)echts Tracker)
#define LT_M 4  // Line Tracker ((M)ittel Tracker)
#define LT_L 2  // Line Tracker ((L)inks Tracker)
//-----------Ultraschallsensor-------------------
#define ECHO_PIN A4 // Signal empfangen
#define TRIG_PIN A5 // Signal senden
//-----------Motor-Rechts------------------------
#define ENA 5 // Car-Speed
#define IN1 7 // Antrieb
#define IN2 8 // Antrieb
//-----------Motor-Links-------------------------
#define ENB 6  // Car-Speed
#define IN3 9  // Antrieb
#define IN4 11 // Antrieb
//-----------LED---------------------------------
#define LED 13 // LED pin
//-----------Infrarot--------------------s--------
#define RECV_PIN 12 // Infrarot Sensor
//-----------Bluetooth Modul---------------------
#define RX 0
#define TX 1
//-----------------------------------------------

// Variablen festlegen:
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

void setup()
{
  //-----------------------------------------------
  myservo.attach(3);
  myservo.write(99); // dreht die Servo auf Referenz -> 90°
                     //----------------------L298N--------------------
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //-----------------------------------------------
}

void carspeed(int speedA = DEFAULT_SPEED, int speedB = DEFAULT_SPEED)
{
  if (speedA < 0 || speedA > 50) speedA = DEFAULT_SPEED;
  if (speedB < 0 || speedB > 50) speedB = DEFAULT_SPEED;

  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void forward(int SA = DEFAULT_SPEED, int SB = DEFAULT_SPEED)
{
  carspeed(SA, SB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void backward(int SA = DEFAULT_SPEED, int SB = DEFAULT_SPEED)
{
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void curve(const char *DIRECTION, int SS = DEFAULT_SPEED, int LS = DEFAULT_C_SPEED) // DIRECTION: Should Not Be Empty!!!
{
  if (strcmp(DIRECTION, "right") == 0)
  {
    carspeed(SS, LS);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else if (strcmp(DIRECTION, "left") == 0)
  {
    carspeed(LS, SS);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else ERROR();
}
void curve_backward(const char *DIRECTION, int LS = DEFAULT_C_SPEED, int SB = DEFAULT_SPEED)
{
  if (strcmp(DIRECTION, "right") == 0)
  {
    carspeed(LS, SS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (strcmp(DIRECTION, "left") == 0)
  {
    carspeed(SS, LS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else ERROR();
}
void cycle_to(const char *direction = DEFAULT_DIRECTION, int LS = DEFAULT_CYCLE_LS, int SS = DEFAULT_CYCLE_SS, long myTimout = 0)
{
  if (strcmp(direction, "left") == 0)
  {
    myTimer = millis();   // setzte myTimer auf aktuelle laufzeit
    long myTimeout = 220; // soviele millis soll das car sich drehen

    while (millis() < myTimer + myTimeout) //(myTimout == 1000) Nun wird geschaut ob meine aktuelle Laufzeit(millis()) noch im bereich meiner gewünschten zeit ist, die die funktion durchlaufen soll
    {
      carspeed(LS, SS);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
  }
  else if (strcmp(direction, "right") == 0)
  {
    myTimer = millis();   // setzte myTimer auf aktuelle laufzeit
    long myTimeout = 220; // soviele millis soll das car sich drehen

    while (millis() < myTimer + myTimeout) //(myTimout == 1000) Nun wird geschaut ob meine aktuelle Laufzeit(millis()) noch im bereich meiner gewünschten zeit ist, die die funktion durchlaufen soll
    {
      carspeed(LS, SS);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  }
  else if (strcmp(direction, "back") == 0)
  {
    myTimer = millis();   // setzte myTimer auf aktuelle laufzeit
    long myTimeout = 717; // soviele millis soll das car sich drehen

    while (millis() < myTimer + myTimeout) //(myTimout == 1000) Nun wird geschaut ob meine aktuelle Laufzeit(millis()) noch im bereich meiner gewünschten zeit ist, die die funktion durchlaufen soll
    {
      carspeed(255, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  }
  else if (strcmp(direction, DEFAULT_DIRECTION) == 0)
  {
    myTimer = millis();    // setzte myTimer auf aktuelle laufzeit
    long myTimeout = 2300; // soviele millis soll das car sich drehen

    while (millis() < myTimer + myTimeout) //(myTimout == 1000) Nun wird geschaut ob meine aktuelle Laufzeit(millis()) noch im bereich meiner gewünschten zeit ist, die die funktion durchlaufen soll
    {
      carspeed(255, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  } else ERROR();
}

void HARD(const char *direction, int SS = DEFAULT_SPEED)
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(SS, 0);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (strcmp(direction, "left") == 0)
  {
    carspeed(0, SS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else ERROR();
}

void HARDBACK(const char *direction, int SS = DEFAULT_SPEED)
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(SS, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (strcmp(direction, "left") == 0)
  {
    carspeed(0, SS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else ERROR();
}

void ERROR() // Gedacht als physischer Error (Falls ein falscher wert gegeben wird)
{
  int myTimer = millis();
  while (millis() != myTimer) // dar ich zuvor myTimer auf den gleichen wert wie millis() gesetzt habe, ist millis() sowieso größer(oder zuanfang noch gleich)
  {
    if (millis() % 1000 > 500) {
      carspeed(70, 70);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    } else {
      carspeed(70, 70);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
  }
}

void loop()
{
delay(1000);
forward();
delay(1000);
backward();
delay(1000);
curve("right");
delay(1000);
curve("left");
delay(1000);
curve_backward("right");
delay(1000);
curve_backward("left");
delay(1000);
cycle_to("right");
delay(1000);
cycle_to("left");
delay(1000);
cycle_to("back");
delay(1000);
HARD("left");
delay(1000);
HARD("right");
delay(1000);
HARDBACK("left");
delay(1000);
HARDBACK("right");
}