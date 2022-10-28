void setup()
{
  unsigned long begin_time = micros(); 
  unsigned char *reader = (unsigned char*) 0x29;

  // Benchmarking starts here
  for (int i=0; i<10000; i++)
  {
  unsigned char value = *reader;
  }
  // Benchmarking ends here

  unsigned long duration = micros() - begin_time;

  Serial.begin(9600);
  Serial.println(duration);
}

void loop() 
{ 
  
}
