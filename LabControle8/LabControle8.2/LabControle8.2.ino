int Ts = 10000;
unsigned long tempoAnt = 0;
int leitura;
float valor;

void setup() {
  pinMode(A2,INPUT);
  Serial.begin(2000000);
}

void loop() {
  if(micros() - tempoAnt > Ts){
    leitura = analogRead(A2);
    //valor = map(leitura, 0, 1023, 0, 5);
    valor = leitura*0.0048875855;
    tempoAnt = micros();
    Serial.println(valor);
  }
}
