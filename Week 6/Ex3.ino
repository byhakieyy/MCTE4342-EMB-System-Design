void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00001000;     //PB5 (pin 11) OC0b
  OCR0A = 5;             //top value is 5
  OCR0B = 2.5;           //50% duty cycle
  TCCR0A = 0b00100011;   //Normal output channel B, Fast PWM OCR0A(5) top
  TCCR0B = 0b00001001;   //1 pre-scaler
}

void loop() {
  // put your main code here, to run repeatedly:

}
