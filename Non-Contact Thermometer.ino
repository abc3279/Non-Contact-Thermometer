#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27,16,2); 
 

void setup() {
  Serial.begin(9600);
  lcd.init();   
  lcd.backlight();
  mlx.begin();  
  pinMode(2, INPUT_PULLUP); //2번 핀을 내부전압을 쓰는 입력핀으로 설정
  lcd.begin (16,2); // 16 x 2
}

void loop() {
  if(digitalRead(2) == LOW)
  {
    lcd.setCursor(3, 0);
    lcd.print("Temperature");
    lcd.setCursor(5, 1);
    lcd.print(mlx.readObjectTempC()/98*100);
    lcd.print(" C");
    Serial.println(mlx.readObjectTempC()/98*100);
    delay(2500);
    lcd.clear();
  }
}
