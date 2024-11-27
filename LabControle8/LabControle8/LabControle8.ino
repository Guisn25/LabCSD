int duty = 50;
int Ts = 5000;
unsigned long tempoAnt = 0;
int leitura;
float valor;

void setup() {
  //pinMode(A2,INPUT);
  Serial.begin(2000000);
  //TCCR3B = TCCR3B & B11111000 | B00000001;
  //duty = map(duty,0, 100, 0, 255);
  //analogWrite(3,duty);
}

void loop() {
  if(micros() - tempoAnt > Ts){
    leitura = analogRead(A2);
    valor = map(leitura, 0, 1023, 0, 5);
    tempoAnt = micros();
    Serial.println(valor);
  }
}
