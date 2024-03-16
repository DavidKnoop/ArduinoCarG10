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

void curve(int SS = DEFAULT_SPEED, int LS = DEFAULT_C_SPEED, const char *direction) // SNBE: Should Not Be Empty!!!
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(SS, LS);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else if (strcmp(direction, "left") == 0)
  {
    carspeed(LS, SS);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else ERROR();
}
void curve_backward(int LS = DEFAULT_C_SPEED, int SB = DEFAULT_SPEED, const char *direction)
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(LS, SS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (strcmp(direction, "left") == 0)
  {
    carspeed(SS, LS);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else ERROR();

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

void HARD(int SA = DEFAULT_SPEED const char *direction)
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(SA, 0);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (strcmp(direction, "left") == 0)
  {
    carspeed(0, SB);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else ERROR();
}
}
void HARDBACK(int SA = DEFAULT_SPEED)
{
  if (strcmp(direction, "right") == 0)
  {
    carspeed(SA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (strcmp(direction, "left") == 0)
  {
    carspeed(0, SB);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else ERROR();
}

void ERROR() // Gedacht als physischer Error (Falls ein falscher wert gegeben wird)
{
  myTimer = millis();
  while (millis() >= myTimer) // dar ich zuvor myTimer auf den gleichen wert wie millis() gesetzt habe, ist millis() sowieso größer(oder zuanfang noch gleich)
  {
    carspeed(255, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}