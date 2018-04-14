int ledV = 8;
int ledA = 9;
int ledVer = 10;
int ledPVer = 7;
int ledPV = 6;
int botao = 13;

void setup(){
  pinMode(ledV,OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(ledVer,OUTPUT);
  pinMode(ledPVer, OUTPUT);
  pinMode(ledPV, OUTPUT);
  pinMode(botao, INPUT);
  digitalWrite(ledPVer, HIGH);
  digitalWrite(ledV, HIGH);
}

void loop(){
  int pinBotao = digitalRead(botao);
  
  if(digitalRead(botao) == 1){
    semaforo();
    semaforoP();    
  }
}

void semaforoP(){
  int i = 0;
  
  digitalWrite(ledPVer,LOW);  
  digitalWrite(ledPV, HIGH);
  delay(3550);
  digitalWrite(ledPV, LOW);
  delay(50);
  digitalWrite(ledPV, HIGH);
  delay(100);
  digitalWrite(ledPV, LOW);
  delay(50);
  digitalWrite(ledPV, HIGH);
  delay(100);
  digitalWrite(ledPV, LOW);
  delay(50);
  digitalWrite(ledPV, HIGH);
  delay(100);
  
  digitalWrite(ledPV, LOW);
  digitalWrite(ledPVer, HIGH); 
  
  digitalWrite(ledV, HIGH);
  digitalWrite(ledVer, LOW);  
}

void semaforo(){
  int i;
  for(i = 8; i<= 10; i++){
    if(i == 8 || i == 10){
      digitalWrite(i,HIGH);
      if(i == 10)  
        delay(500);
      digitalWrite(i,LOW);
    }
    if(i == 9){
      digitalWrite(i,HIGH);
      delay(2000);
      digitalWrite(i,LOW);    
    }  
  }
  digitalWrite(ledVer, HIGH);
}

