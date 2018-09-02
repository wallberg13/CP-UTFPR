int pinPot = 0;
int pinLedV = 11;
int pinLedA = 10;
int pinLedVe = 9;

void setup(){
  pinMode(pinLedV,OUTPUT);
  pinMode(pinLedA,OUTPUT);
  pinMode(pinLedVe,OUTPUT);
}

void loop(){
  int valorpot = analogRead(pinPot);
  
  if(valorpot<=1023 && valorpot>=307){
    analogWrite(pinLedV,map(valorpot,307,1023,0,255));
    digitalWrite(pinLedA,LOW);
    digitalWrite(pinLedVe,LOW);
  }
  if(valorpot<307 && valorpot>=102){
    analogWrite(pinLedA,map(valorpot,102,307,0,255));
    digitalWrite(pinLedV,LOW);
    digitalWrite(pinLedVe,LOW);
  }
  if(valorpot<102 && valorpot>0){
    analogWrite(pinLedVe,map(valorpot,1,102,0,255));
    digitalWrite(pinLedV,LOW);
    digitalWrite(pinLedA,LOW);
  }
  if(valorpot == 0){
    digitalWrite(pinLedVe,HIGH);
    delay(100);
    digitalWrite(pinLedVe,LOW);
    delay(100);
  }  
  
}
