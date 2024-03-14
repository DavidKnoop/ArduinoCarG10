void carspeed(int speedA, int speedB)
{
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
}

void forward(int SA, int SB)
{
    carspeed(255, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void backward(int SA, int SB)
{
    carspeed(255, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void curve_right_forward(int SA, int SB)
{
    carspeed(200, 75);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void curve_left_forward(int SA, int SB)
{
    carspeed(75, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void curve_left_backward(int SA, int SB)
{
    carspeed(75, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void curve_right_backward(int SA, int SB)
{
    carspeed(SA, SB);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
void loop()
{
    forward(255, 255);
    backward(255, 255);
    curve_right_forward(200, 75);
    curve_left_forward(75, 200);
    curve_left_backward(75, 200);
    curve_right_backward(200, 75);
}