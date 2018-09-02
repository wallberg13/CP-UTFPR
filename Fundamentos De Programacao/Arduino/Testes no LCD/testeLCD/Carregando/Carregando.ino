#include  <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte newChar1[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

byte newChar2[8] = {
  B00000,
  B00100,
  B01110,
  B11011,
  B10001,
  B00000,
  B00000,
  B00000
};
byte newChar3[8] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B11011,
  B01110,
  B00100,
  B00000
};

void setup() {
  lcd.createChar(0, newChar1);
  lcd.createChar(1, newChar2);
  lcd.createChar(2, newChar3);
  lcd.begin(16, 2);
}
  
void loop() {
   
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  delay(100);

  
}

