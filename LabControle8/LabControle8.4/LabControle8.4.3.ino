int Ts = 500;
unsigned long tempoAnt = 0;
int leitura;
float valor;
float r = 1;
float u;
float uPWM;
float e;

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
    e = r-valor;
    if(valor>2){
      u = -e;
    }else{
      u=2;
    }
    if(u<0){
      u=0;
    }
    uPWM = u*51;
    analogWrite(3, uPWM);
    
    tempoAnt = micros();
  }
}
