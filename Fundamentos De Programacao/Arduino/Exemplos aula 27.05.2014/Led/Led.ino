int pinLed1 = 13;
int pinLed2 = 12;
int pinLed3 = 11;
int i = 0;

void setup(){
  pinMode(pinLed1,OUTPUT);  
 // pinMode(pinLed3,OUTPUT);  
  pinMode(pinLed2,OUTPUT);  
}


void loop(){

  if(i<100){
    //digitalWrite(pinLed1,HIGH);
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed3,HIGH);
    delay(500);
    //digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);


    digitalWrite(pinLed1,LOW);
    delay(1000);
    i++;
  }
  if(i>=100){
    digitalWrite(pinLed1,LOW);
    
  }
}
