#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig= 6;
int echo= 7;
long mesafe;
long sure;
void setup()
{

    pinMode( trig, OUTPUT);
  pinMode( echo, INPUT);
  Serial.begin(9600);
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("");
}

void loop()
{
	 digitalWrite( trig , HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig, LOW);
 sure = pulseIn(echo, HIGH);
 mesafe = (sure / 2) / 29.1;
 lcd.println("boy");
  lcd.backlight();
  lcd.print(mesafe);
  delay ( 500);
  lcd.clear();
  int boy=190-mesafe;
  lcd.println("boy");
  lcd.backlight();
  lcd.print(boy);
  delay (500);
  
 
 
}
