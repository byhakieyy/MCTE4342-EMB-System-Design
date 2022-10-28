unsigned long previousTime;
unsigned char *D_dir=(unsigned char*)0x2A; //Points to DDRD
unsigned char *D_writer=(unsigned char*)0x2B; //Points to PORTD

void setup() //To run on Arduino, just change this function to void setup()
{
  *D_dir=0b00000100;
  for(;;)
  {
    unsigned long currentTime=millis();

    if(((*D_writer)&0b00000100) == 0) //If the LED is currently OFF
    {
      if(currentTime-previousTime>=2000) //2000 is OFF duration
      {
        *D_writer|=0b00000100; //Turn ON the LED
        previousTime=currentTime; //Take note of the time
      }
    }
    else//LED is currently ON
    {
      if(currentTime-previousTime>=2000) //2000 is ON duration
      {
        *D_writer&=0b11111011; //Turn OFF the LED
        previousTime=currentTime; //Take note of the time
      }
    }
    //Code to perform other functions (such as button debouncing) can be inserted here
  }
}
