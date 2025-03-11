int r=6;
int b=5;
int g=3;

void setup() {
  pinMode(r,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() 
{
int rr= random (0,255);
int br =random(0,255);
int gr =random(0,255);

analogWrite(r,rr);
analogWrite(b,br);
analogWrite(g,gr);
 
delay(1000);

}
