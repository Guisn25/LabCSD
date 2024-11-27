int Ts = 80;
unsigned long tempoAnt = 0;
int leituraR, leituraY;
float r;
float y;
float e;
float u;
float uPWM;
float Kp = 1;
float Ki = 0.5;
float somaErro = 0;

void setup() {
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  TCCR3B = TCCR3B & B11111000 | B00000001;
  pinMode(3, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  if(millis() - tempoAnt > Ts){
    leituraR = analogRead(A2);
    leituraY = analogRead(A0);
    r = leituraR*0.0048875855;
    y = leituraY*0.0048875855;
    e = r-y;
    somaErro += e;
    u = Kp*e +Ki*somaErro;
    if(u<0){
      u=0;
    }
    if(u>5){
      u=5;
    }
    uPWM = u*51;
    analogWrite(3, uPWM);
    tempoAnt = millis();
  }
}
