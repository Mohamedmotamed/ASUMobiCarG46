 int x ,z=10 ,m=11 ;
 boolean i=false;

void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(13,OUTPUT);
pinMode(z,OUTPUT);
pinMode(m,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
attachInterrupt(digitalPinToInterrupt(2),blink,CHANGE);


}

void loop() {
digitalWrite(13,HIGH);
digitalWrite(5,HIGH);
digitalWrite(7,LOW);
x=analogRead(A0);
if ((x/4)>255)
{
  x=4*255;
}
Serial.println(digitalRead(2));
Serial.println(x/4);
if (i)
{
  z=11;
  m=10;
}
if (!i)
{
  z=10;
  m=11;
}
analogWrite(z,x);
analogWrite(m,LOW);


}

void blink()
{
  digitalWrite(7,HIGH);
  i=!i;
  
}

