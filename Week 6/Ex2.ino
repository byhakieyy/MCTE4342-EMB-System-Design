void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00001000;     //PB5 (pin 11) OC0b
  OCR0B = 127;           //50% duty cycle
  TCCR0A = 0b00100011;   //Normal output channel B, Fast PWM 255 top
  TCCR0B = 0b00000001;   //1 pre-scaler
}

void loop() {
  // put your main code here, to run repeatedly:

}
