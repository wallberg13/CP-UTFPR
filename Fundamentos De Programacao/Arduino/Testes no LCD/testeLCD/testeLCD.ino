#include  <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte newChar1[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
 
byte newChar2[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};

byte newChar3[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
 
byte newChar4[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};

byte newChar5[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

int i = 0;
int j = 0; 

void setup() {
  lcd.createChar(0, newChar1);
  lcd.createChar(1, newChar2);
  lcd.createChar(2, newChar3);
  lcd.createChar(3, newChar4);
  lcd.createChar(4, newChar5);
  lcd.begin(16, 2);
}
  
void loop() {
  if(j < 16){
    if(i<5){
      lcd.setCursor(j,0);
      lcd.write(byte(i));
      lcd.setCursor(j,1);
      lcd.write(byte(i));
      delay(50);
      i++;
    }else{
      i = 0;
      j++;
    }
  }else{
    lcd.clear();
    j=0;
  }
}
