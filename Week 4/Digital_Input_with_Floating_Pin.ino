void setup()
{
  pinMode(13, OUTPUT); 
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int state = digitalRead(12);
  Serial.println(state);
  
  if (state==HIGH)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
