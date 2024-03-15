
void carspeed(int speedA, int speedB) {
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void forward(int SA, int SB) {
  carspeed(SA, SB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward(int SA, int SB) {
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void curve_right_forward(int SA, int SB) {
  carspeed(SB, SA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void curve_left_forward(int SA, int SB) {
  carspeed(SA, SB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void curve_left_backward(int SA, int SB) {
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void curve_right_backward(int SA, int SB) {
  carspeed(SA, SB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
'void loop()
{
    delay(1000);
    forward(255, 255);
    delay(1000);
    backward(255, 255);
    delay(1000);
    curve_right_forward(200, 15);
    delay(1000);
    curve_left_forward(15, 200);
    delay(1000);
    curve_left_backward(15, 200);
    delay(1000);
    curve_right_backward(200, 15);
    delay(1000);
}

void loop()
{
    delay(1000);
    forward(255, 255);
    delay(1000);
    backward(255, 255);
    delay(1000);
    curve_right_forward(200, 75);
    delay(1000);
    curve_left_forward(75, 200);
    delay(1000);
    curve_left_backward(75, 200);
    delay(1000);
    curve_right_backward(200, 75);
    delay(1000);
}'