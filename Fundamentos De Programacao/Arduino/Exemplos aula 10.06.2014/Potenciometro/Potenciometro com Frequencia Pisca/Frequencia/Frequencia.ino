int pinPot = 0;
int pinLed = 10;

void setup(){
 pinMode(pinLed, OUTPUT);  
}

void loop(){
  
  int valorpot = analogRead(pinPot);
 
  int valorpwm = map(valorpot, 0, 1023, 10, 300);
  
  digitalWrite(pinLed, HIGH);
  delay(valorpwm);
  digitalWrite(pinLed, LOW);
  delay(valorpwm);
    
  
}
