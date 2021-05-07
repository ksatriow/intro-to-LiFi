#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
SoftwareSerial GSerial(11,12); 
char rec=0;

void setup()
{
  Serial.begin(9600);
  GSerial.begin(400);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Receiver LiFi");
  lcd.setCursor(0, 1);
  lcd.print(" Nomor dan Text ");
  delay(3000);
  lcd.clear();
}

void loop()
{
  if(GSerial.available() != 0)
  {    
    rec = GSerial.read();
    if(rec=='^')
    {
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
    }
    else if(rec=='&')
    {
      lcd.clear();
    }
    
    else
    {
      Serial.print(rec);
      lcd.print(rec);
    }
  }
}
