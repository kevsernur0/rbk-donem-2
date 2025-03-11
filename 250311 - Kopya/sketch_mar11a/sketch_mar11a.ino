int r=6;
int b=5;
int g=3;
void setup() {
  pinMode(r,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);

}

void loop() {
  analogWrite(r,250);
  analogWrite(b,50);
  analogWrite(g,150);
  delay(1000);

}
