//eingebundene Libaries:
#include <IRremote.h>
#include <Servo.h>
//Pin festlegung:
#define LT_R 10 //Line Tracker ((R)echts Tracker)
#define LT_M 4  //Line Tracker ((M)ittel Tracker)
#define LT_L 2  //Line Tracker ((L)inks Tracker)

#define ENA 3   //Car-Speed
#define ENB 6   //Car-Speed
#define IN1 7   //Antrieb
#define IN2 8   //Antrieb
#define IN3 9   //Antrieb
#define IN4 11  //Antrieb

#define carSpeed 150
//Variablen festlegen:
Servo myservo;


void setup(){
    myservo.attach(3);
    myservo.write(99);// dreht die Servo auf Referenz -> 90° 

}

void loop(){

}