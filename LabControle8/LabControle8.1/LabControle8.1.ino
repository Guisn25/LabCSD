int duty = 50;

void setup() {
  pinMode(A3,OUTPUT);
  TCCR3B = TCCR3B & B11111000 | B00000001;
  duty = map(duty,0, 100, 0, 255);
  analogWrite(3,duty);
}

void loop() {
}
