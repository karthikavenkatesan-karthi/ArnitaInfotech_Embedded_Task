#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // if not works, try 0x3F

int gasSensor = A0;
int gasValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  gasValue = analogRead(gasSensor);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality");

  lcd.setCursor(0, 1);
  lcd.print(gasValue);

  if (gasValue > 400) {
    lcd.setCursor(8, 1);
    lcd.print("BAD");
  } else {
    lcd.setCursor(8, 1);
    lcd.print("GOOD");
  }

  delay(1000);
}