void setup(){
  Serial.begin(9600);
  Serial.println("Serial Iniciada");
}

void loop(){
  char ret;
  if(Serial.available() > 0){
    ret = Serial.read();
    Serial.print("Recebido: "); 
    Serial.println(ret);
    
  }
}
