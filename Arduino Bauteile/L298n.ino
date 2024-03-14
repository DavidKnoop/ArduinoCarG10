#define ENA 3   //Car-Speed
#define ENB 6   //Car-Speed
#define IN1 7   //Antrieb
#define IN2 8   //Antrieb
#define IN3 9   //Antrieb
#define IN4 11  //Antrieb

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
}

void 