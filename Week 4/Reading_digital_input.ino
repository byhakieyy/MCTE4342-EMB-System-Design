void setup()
{
  unsigned char *dir = (unsigned char*) 0x24; 
  unsigned char *writer = (unsigned char*) 0x25;
  unsigned char *reader = (unsigned char*) 0x23;

  *dir=0b00100000; //or *dir = 32 or *dir = 0x20

  for (;;)
  {
    if (((*reader) & 0b00010000) != 0)
    {
      *writer = 0b00100000;
    } 
    else
    {
      *writer = 0;
    }
  }
}
