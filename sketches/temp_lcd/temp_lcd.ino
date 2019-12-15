#include <dht.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 4, 5);

dht DHT;

#define DHT11_PIN 2

void setup(){
  Serial.begin(9600);
    lcd.init();
   lcd.backlight();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
  int hum = DHT.humidity;

   lcd.clear();
  lcd.print("Temperature "); lcd.print(temp);lcd.print("C");
  lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print("Humidity    ");lcd.print(hum); lcd.print("%");
  //lcd.print(millis() / 1000);
  delay(10000);
}
