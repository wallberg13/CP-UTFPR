int ledV = 8;
int ledA = 9;
int ledVer = 10;

void setup(){
  pinMode(ledV,OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(ledVer,OUTPUT);
}

void loop(){
  int i;
  for (i=8;i<=10;i++){
    if(i == 8 || i == 10){
      digitalWrite(i,HIGH);
      delay(5000);
      digitalWrite(i,LOW);  
    }
    if(i == 9){
      digitalWrite(i,HIGH);
      delay(2000);
      digitalWrite(i,LOW);    
    }
  }
  
}
