int pinPot = 0;
int pinLed = 10;

void setup(){
 pinMode(pinLed, OUTPUT);  
}

void loop(){
  int valorpot;
 
  valorpot = analogRead(pinPot);
 
  int valorpwm = map(valorpot, 0, 1023, 0, 255);
  analogWrite(pinLed, valorpwm); 
  
}
