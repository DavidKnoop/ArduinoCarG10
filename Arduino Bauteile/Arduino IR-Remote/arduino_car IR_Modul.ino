//eingebundene Libaries:
#include <IRremote.h>
#include <Servo.h>
//Pin festlegung:
#define LT_R 10 //Line Tracker ((R)echts Tracker)
#define LT_M 4  //Line Tracker ((M)ittel Tracker)
#define LT_L 2  //Line Tracker ((L)inks Tracker)

#define ENA 5   //Car-Speed
#define ENB 6   //Car-Speed
#define IN1 7   //Antrieb
#define IN2 8   //Antrieb
#define IN3 9   //Antrieb
#define IN4 11  //Antrieb
#define LED       13        //LED pin
#define RECV_PIN  12 //Infrarot Sensor
#define carSpeed 150

//Variablen festlegen:
Servo myservo;
String irauswertung;


void setup(){
    myservo.attach(3); //Servo wird angesteuert
    myservo.write(99);// dreht die Servo auf Referenz -> 90° 
    Serial.begin(9600);
    IrReceiver.begin(RECV_PIN);
    IrReceiver.enableIRIn(); //IR-Receiver wird eingeschaltet
}

void startmenu(){
if (IrReceiver.decode()) {
    irauswertung=IrReceiver.decodedIRData.command;
    switch(irauswertung.toInt()){ //wandelt den string in ein Integer um
        case 22:
        Serial.println("Das war case 1");
        break; //geht raus aus den case
        case 25:
        Serial.println("Das war case 2");
        break;

    }
    IrReceiver.resume();
}
}

void loop(){
    startmenu();
}