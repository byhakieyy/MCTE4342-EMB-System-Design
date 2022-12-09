#include <EEPROM.h>
byte led_to_lit = 0;
byte led_lit = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT_PULLUP); //green
  pinMode(A2, INPUT_PULLUP); //yellow
  pinMode(A3, INPUT_PULLUP); //red led

  pinMode(5, OUTPUT); //red led
  pinMode(6, OUTPUT); //yellow led
  pinMode(7, OUTPUT); //green led
  led_to_lit = EEPROM.read(0); 
  digitalWrite(led_to_lit, HIGH);
}

void loop() {
  if (digitalRead(A1) == 0) led_to_lit = 7; 
  if (digitalRead(A2) == 0)led_to_lit = 6;
  if (digitalRead(A3) == 0)led_to_lit = 5;

  if (led_to_lit != 0 and led_to_lit != led_lit) {
    if (led_to_lit == 7) {
      digitalWrite(7, HIGH); //turn on the led
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      EEPROM.write(0, 7); //write to eeprom
    }
    if (led_to_lit == 6) {
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH); //turn on the led
      digitalWrite(5, LOW);
      EEPROM.write(0, 6); //write to eeprom
    }
    if (led_to_lit == 5) {
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH); //turn on the led
      EEPROM.write(0, 5); //write to eeprom
    }
    EEPROM.write(0, led_to_lit  );
    Serial.println(led_to_lit);
  }
  led_lit = led_to_lit;

}
