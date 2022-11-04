#define NOTE_G4  392
#define NOTE_A  440
#define NOTE_B  494
#define NOTE_C  523
#define NOTE_D  587
#define NOTE_E  659
#define NOTE_F  698
#define NOTE_G5  784


// notes in the melody:
int melody[25] = {NOTE_G4, NOTE_G4, NOTE_A, NOTE_G4, NOTE_C, NOTE_B, NOTE_G4, NOTE_G4, NOTE_A, NOTE_G4, NOTE_D, NOTE_C, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E, NOTE_C, NOTE_B, NOTE_A, NOTE_F, NOTE_F, NOTE_E, NOTE_C, NOTE_D, NOTE_C};
int buttonState = 0;

void setup() 
{
  pinMode(2,INPUT);
  
}

void loop() 
{
  buttonState = digitalRead(2);
  int count=0;
  
  if (buttonState == HIGH)
  {
    count+=1;
  }
  
  if (count == 1)
  {
  HappyBirthdaySong();
  count = 0;
  }
}

void HappyBirthdaySong()
{
  for (int thisNote = 0; thisNote < 25; thisNote++) 
   {
      tone(8, melody[thisNote]);

    if (thisNote == 5 || thisNote == 11 || thisNote == 18)
    {
        delay(1500); 
      }
      else
    {
      delay(500);
    }
      if (thisNote == 24)
        {
          noTone(8);
        }
    }
}
