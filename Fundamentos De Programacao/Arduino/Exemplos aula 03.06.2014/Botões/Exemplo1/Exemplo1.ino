int botao = 12;
int led = 13;


void setup(){
  pinMode(botao, INPUT);  
  pinMode(led, OUTPUT);
}

void loop(){
  int flag = digitalRead(botao);
  
  if (flag == 1){
    digitalWrite(led,HIGH);    
  }else{
     digitalWrite(led,LOW);    
  }
  
  
}

