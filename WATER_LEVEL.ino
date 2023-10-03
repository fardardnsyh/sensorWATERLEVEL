#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Wire.h> 

int buzzer = 2;     // inisialisasi buzzer pin pada 2
int waterlevel = A0;     // inisialisasi buzzer pin pada A0 WATER LEVEL



void setup() {
pinMode(waterlevel, INPUT);     //pengaturan pin WATER LEVEL sebagai input
pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  int value = analogRead(waterlevel);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("   ");
  Serial.println(value);
  lcd.setCursor(0, 1);
  lcd.print("W Level :");


  if (value == 0) {
    lcd.print("Empty ");
    digitalWrite(buzzer, LOW); 
  } else if (value > 1 && value < 350) {
    lcd.print("LOW");
    digitalWrite(buzzer, LOW); 
  } else if (value > 350 && value < 510) {
    lcd.print(" Medium");
    digitalWrite(buzzer, HIGH); 
  } else if (value > 510){
    lcd.print(" HIGH  ");
    digitalWrite(buzzer, HIGH); 
  }
}
