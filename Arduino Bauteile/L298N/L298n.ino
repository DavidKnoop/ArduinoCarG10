void carspeed(int speedA = DEFAULT_SPEED, int speedB = DEFAULT_SPEED)
{
  if (speedA < 0 || speedA > 50)
    speedA = DEFAULT_SPEED;
  if (speedB < 0 || speedB > 50)
    speedB = DEFAULT_SPEED;

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

void curve_right_forward(int SA = DEFAULT_SPEED, int SB = DEFAULT_C_SPEED)
{
  carspeed(SB, SA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void curve_left_forward(int SA = DEFAULT_C_SPEED, int SB = DEFAULT_SPEED)
{
  carspeed(SA, SB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void curve_left_backward(int SA = DEFAULT_C_SPEED, int SB = DEFAULT_SPEED)
{
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void curve_right_backward(int SA = DEFAULT_SPEED, int SB = DEFAULT_C_SPEED)
{
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void cycle_to(const char *direction = DEFAULT_DIRECTION, int LS = DEFAULT_CYCLE_LS, int SS = DEFAULT_CYCLE_SS)
{
  if (strcmp(direction, "left") == 0)
  {
    myTimer = millis(); //setzte myTimer auf aktuelle laufzeit
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
    myTimer = millis(); //setzte myTimer auf aktuelle laufzeit
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
    myTimer = millis(); //setzte myTimer auf aktuelle laufzeit
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
  else if (strcmp(direction, DEFAULT_DIRECTION)==0)
  {
    myTimer = millis(); //setzte myTimer auf aktuelle laufzeit
    long myTimeout = 2300; // soviele millis soll das car sich drehen
    
    while (millis() < myTimer + myTimeout) //(myTimout == 1000) Nun wird geschaut ob meine aktuelle Laufzeit(millis()) noch im bereich meiner gewünschten zeit ist, die die funktion durchlaufen soll
    {
      carspeed(255, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  } else { // Gedacht als physischer Error (Falls ein falscher wert gegeben wird)
    myTimer = millis();
    while(millis() >= myTimer)//dar ich zuvor myTimer auf den gleichen wert wie millis() gesetzt habe, ist millis() sowieso größer(oder zuanfang noch gleich)
    {
      carspeed(255, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
  }
}

void HARD_RIGHT(int SA = DEFAULT_SPEED)
{
  carspeed(SA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void HARDBACK_RIGHT(int SA = DEFAULT_SPEED)
{
  carspeed(SA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void HARDBACK_LEFT(int SB = DEFAULT_SPEED)
{
  carspeed(0, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void HARD_LEFT(int SB = DEFAULT_SPEED)
{
  carspeed(0, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}