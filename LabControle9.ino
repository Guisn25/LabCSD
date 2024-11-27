int Ts = 50;
unsigned long tempoAnt = 0;
int leituraR, leituraY, leituraPot;
float pot;
float r;
float y;
float e;
float u;
float uPWM;
float Kp = 1;

void setup() {
  pinMode(A4,INPUT);
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  TCCR3B = TCCR3B & B11111000 | B00000001;
  pinMode(3, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  delay(1000);
  if(millis() - tempoAnt > Ts){
    leituraPot = analogRead(A4);
    leituraR = analogRead(A2);
    leituraY = analogRead(A0);
    pot = leituraPot*0.0048875855;
    r = pot;
    y = leituraY*0.0048875855;
    e = r-y;
    u = Kp*e;
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
