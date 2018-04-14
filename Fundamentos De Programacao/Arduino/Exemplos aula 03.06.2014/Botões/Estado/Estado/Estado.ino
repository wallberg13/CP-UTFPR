int botao = 13;
int led = 8;

int botaoapertado = 0;
int estado = 0;

void setup(){
  pinMode(botao, INPUT);  
  pinMode(led, OUTPUT);
}

void loop(){
  
  if (digitalRead(botao) == 1){
    estado = !estado;
    while(digitalRead(botao) == 1);
    if(estado == 1){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);  
    }
    delay(300);
  }
}

