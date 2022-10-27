void setup()
{
  unsigned char *dir = (unsigned char*) 0x24; 
  *dir = 0b00100000;  //or dir = 32 or dir = 0x20
}

void loop()
{
  unsigned char *port = (unsigned char*) 0x25;
  *port = 0b00100000; //or dir = 32 or dir = 0x20
  delay(1000);
  *port = 0;
  delay(1000);
}
