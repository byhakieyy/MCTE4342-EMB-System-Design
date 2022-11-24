volatile unsigned long ms;
unsigned char *tccr2a = (unsigned char*)0xB0;
unsigned char *tccr2b = (unsigned char*)0xB1;
unsigned char *timsk2 = (unsigned char*)0x70;
unsigned char *portb = (unsigned char*)0x25;
unsigned char *ddrb = (unsigned char*)0x24;
unsigned char *sreg = (unsigned char*)0x5F;
unsigned long previousTime;
ISR(TIMER2_OVF_vect)
{
  ms++;
}
unsigned long getMilliseconds()
{
  *timsk2 = 0b00000000; //Disable timer2 interrupts
  unsigned long val = ms; //Read the variable
  *timsk2 = 0b00000001; //Re-enable timer2 interrupts
  return val;
}
void setup()
{
  *ddrb = 0b00100000; //Set PB5 as output
  *tccr2a = 0b00000011; //8-bit Fast PWM on timer2
  *tccr2b = 0b00000100; //Set pre-scalerto 64
  *sreg |= 0b1000000; //Enable interrupts
  *timsk2 = 0b00000001; //Enable timer2 overflow interrupt
}

void loop()
{
  unsigned long currentTime = getMilliseconds();
    if ((*portb) & 0b00100000) //If LED is currently ON
    {
      if (currentTime - previousTime >= 1000)
      {
        *portb = 0; //Turn it OFF
        previousTime = currentTime;
      }
    }
    else//If LED is currently OFF
    {
      if (currentTime - previousTime >= 1000)
      {
        *portb = 0b00100000; //Turn it ON
        previousTime = currentTime;
      }
    } 
}
