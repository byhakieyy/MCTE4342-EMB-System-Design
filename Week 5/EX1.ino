void setup()
{
  Serial.begin(9600); //For now, we are still using the Serial library
}

void loop()
{
  int value =analogRead(A0); //intor unsigned intdoes not matter
  Serial.println(value);
}
