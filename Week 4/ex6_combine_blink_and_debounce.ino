////////////// Variables for blinking LED ////////////////////
unsigned long previousTime;
unsigned char*D_dir=(unsigned char*)0x2A;
unsigned char*D_writer=(unsigned char*)0x2B;

////////////// Variables for debouncing////////////////////
unsigned int count;
bool previous;
bool waiting;
unsigned long pressed_time;
unsigned char *B_reader=(unsigned char*)0x23;

void setup()
{
  *D_dir=0b00000100;
  Serial.begin(9600);
  for(;;)
  {
  BlinkLED(); //BlinkLEDhandles stuff for blinking PD2
  DebounceButton(); //DebounceButtonhandles stuff for debouncingPB4
  }
}
