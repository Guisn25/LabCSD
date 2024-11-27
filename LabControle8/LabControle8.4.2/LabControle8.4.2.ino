int duty;
int Ts = 500;
unsigned long tempoAnt = 0;
int leitura;
float valor;
float r = 0;
float u;
float uPWM;
float e[3] = {0};

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
    e[0] = r-valor;
    u = -(0.333333)*(e[0]+e[1]+e[2]);
    if(u<0){
      u=0;
    }
    uPWM = u*51;
    analogWrite(3, uPWM);
    
    e[2] = e[1];
    e[1] = e[0];
    tempoAnt = micros();
  }
}
