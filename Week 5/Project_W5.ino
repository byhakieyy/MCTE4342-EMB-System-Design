int pot;
int led;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  pot = analogRead(A0);
  led = map(pot, 0, 1023, 0, 255);

  analogWrite(6, led);
}
