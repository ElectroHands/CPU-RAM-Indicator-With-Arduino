#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //If it doesn't work, write the address 0x3f. Sometimes address 0x27 does not work.
                                  //Eger calısmazsa 0x3f adresini yazin. Bazen 0x27 adresi çalışmıyor.
void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop(){
  if (Serial.available()) {
    delay(100);
    lcd.setCursor(0, 0);
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}
