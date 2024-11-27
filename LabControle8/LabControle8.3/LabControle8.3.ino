int duty;
int Ts = 500; // Ripple mínimo
unsigned long tempoAnt = 0;
int leitura;
float valor;

void setup() {
  pinMode(A2,INPUT);
  TCCR3B = TCCR3B & B11111000 | B00000001;
  pinMode(3, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  if(micros() - tempoAnt > Ts){
    leitura = analogRead(A2);
    valor = leitura*0.0048875855;
    duty = map(leitura, 0, 1023, 0, 255);
    analogWrite(3, duty);
    tempoAnt = micros();
    Serial.println(valor);
  }
}
