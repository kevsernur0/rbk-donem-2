#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;  // Trig pin'i
const int echoPin = 10; // Echo pin'i

// LCD ekranın adresi ve boyutu
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C adresi genellikle 0x27 veya 0x3F olabilir, kontrol etmeniz gerekebilir.

void setup() {
  // Seri iletişimi başlat
  Serial.begin(9600);

  // HC-SR04 pinlerini çıkış ve giriş olarak ayarla
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LCD ekranı başlat
  lcd.begin();
  lcd.print("Mesafe Hesapla");
  delay(2000);  // Başlangıçta 2 saniye gösteri yap

  lcd.clear();
}

void loop() {
  // Ultrasonik sensöre kısa bir darbe gönder
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo pin'inden gelen darbenin süresini ölç
  long duration = pulseIn(echoPin, HIGH);

  // Mesafeyi hesapla (ses hızı 34300 cm/s)
  long distance = duration * 0.0344 / 2;  // cm cinsinden mesafe

  // LCD ekranda mesafeyi göster
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Seri portta da mesafeyi yazdır
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 1 saniye bekle
  delay(1000);
}
