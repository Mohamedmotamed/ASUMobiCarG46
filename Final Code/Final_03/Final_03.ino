#include <elapsedMillis.h>





//motor A

#define in1 8
#define in2 9

//motor b

#define in3 10
#define in4 11


int r, c, l ;
const int trigPin = 2;
const int echoPin = 6;
int led = 13;
int h=2;
int b=2;
int S1=5 , S2=3; //Capital S
long duration;
int distance;
char estado ;
int spd=255;
int spd0=180;
int lfd=400;
int f1,f2,f3,f4,f5,f6,ff,fff;
unsigned int interval = 1000;
  elapsedMillis timeElapsed;
void setup() {
Serial.begin(9600);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
 pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
digitalWrite(led,LOW);
l=analogRead(A3);
c=1000-analogRead(A4);
r=analogRead(A5);
 Serial.print("l  ");
    Serial.println(analogRead(A3));
  Serial.print("c  ");
  Serial.println(1000-analogRead(A4));
  Serial.print("r  ");
  Serial.println(analogRead(A5));
   Serial.println(lfd);
   Serial.println(spd);
   Serial.println(spd0);


  
if(Serial.available()>0){ 
estado = Serial.read();
} 
Serial.println("bt " +estado);

if(estado=='L'){
 Max();
left ();

}

else if (estado=='R'){
  Max();
right ();
 
}
else if (estado=='G'){
  analogWrite(S1,spd);
  analogWrite(S2,255);
forward ();
 
}
else if (estado=='I'){
  analogWrite(S2,spd);
  analogWrite(S1,255);
forward ();
 
}
else if (estado=='H'){
  analogWrite(S1,spd);
  analogWrite(S2,255);
  back(); 
}
else if (estado=='J'){
  analogWrite(S2,spd);
  analogWrite(S1,255);
  back(); 
}
else if (estado=='1'){
 spd=25;
}
else if (estado=='2'){
 spd=50;
}
else if (estado=='3'){
 spd=75;
}
else if (estado=='4'){
 spd=100;
}
else if (estado=='5'){
 spd=125;
}
else if (estado=='6'){
 spd=150;
}
else if (estado=='7'){
 spd=175;
}
else if (estado=='8'){
 spd=200;
}
else if (estado=='9'){
 spd=225;
}
else if (estado=='q'){
 spd=255;
}
else if (estado=='W'){
 spd0=255;
}
else if (estado=='w'){
 spd0=210;
}
else if (estado=='U'){
 spd0=180;
}
else if (estado=='u'){
 spd0=150;
}
else if (estado=='X')
{
  lfd=800;
}
else if (estado=='x')
{
  lfd=500;
}
else if (estado=='v')
{
  
lfd=200;

  }

else if(estado=='F')
{
  Max();
forward ();

if (distance<=15)
 {

   
    while(timeElapsed<interval)
   {
  digitalWrite(13, HIGH);
 
 avoid();
   }
   timeElapsed=0;
    digitalWrite(led,LOW);
 Stop();
  
  

  }
}
else if (estado=='B')
{
  Max();
back();
}

else if (estado=='V')
{
  
lf ();

  }

// phase 3 orders

else if (estado=='z')
{
  right();
  delay(83.3*1.9);
  Stop();
}
else if (estado=='T')
{
  right();
  delay(125*1.8);
  Stop();
}
else if (estado=='Z')
{
  right();
  delay(166.6*1.6);
  Stop();
}
else if (estado=='c')
{
  right();
  delay(250*1.27);
  Stop();
}
else if (estado=='C')
{
  right();
  delay(500*1.1);
  Stop();
}
else if (estado=='y')
{
  right();
  delay(750*1.1);
  Stop();
}
else if (estado=='Y')
{
  right();
  delay(1000*1.01);
  Stop();
}

else if (estado=='m')
{
  forward();
  delay(58.8*1.5);
  Stop();
}

else if (estado=='M')
{
  forward();
  delay(117.64*1.15);
  Stop();
}

else if (estado=='l')
{
  forward();
  delay(588*1.11);
  Stop();
}

else if (estado=='Q')
{
  forward();
  delay(1176*1.14);
  Stop();
}

else if (estado=='e')
{
  forward();
  delay(2352*1.14);
  Stop();
}

else if (estado=='E')
{
  forward();
  delay(5880*1.14);
  Stop();
}

else if (estado=='t')
{
  forward();
  delay(11760*1.13);
  Stop();
}



else if (estado=='S')
{
int d1=100; // width in cm
int d2=400; // length in cm
float t1=d1/90.0; // time for width
float t2=d2/90.0; //time for length
 for (int i=0;i<2;i++)
 {
 analogWrite(S1,255); analogWrite(S2,255);
 forward();
 delay (t2*1000);
  right();
  delay(250*1.3);
  forward();
  delay (t1*pow(10, 3));
  right();
  delay(250*1.3);
  }
   Stop();
delay(25000);
for(int x=0;x<25;x++)
  {
  
    Max();
      forward();
    delay(588*1.11);
    right();
    delay(83.3*1);
       
  }
  Stop();
  Max();
}

// phase 3 finish

else 
{
  Stop();
  }
}
 
  
  
void Max()
{
  analogWrite(S1,spd);
  analogWrite(S2,spd);
  }

  void forward ()
    {
    
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);}
      void back ()
    {
     
      digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);}
      void right ()
    {
      
      digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);}

 
      void left ()
 {

     digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);}

  
      void Stop ()                //care to 's' char in stop ----> capital
{
     digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}

  void avoid()
  {
     back();
      delay(500);
  right();
    delay(300);
    if (distance <20)
    {
      Stop();
    }
     else {
   forward();
    delay(1000);
    left();
   delay(300); 
      Stop();
   /*    forward();
   delay(1000);
    left();
    delay(300); 
    
    forward();
    delay(500);
    right();
    delay(300);
    Stop();*/
    }
    }
    

 
 void lf ()
   {
      if((c > lfd && r < lfd && l < lfd )|| (c > lfd && r> lfd && l > lfd))
  {
   
 
      analogWrite(S1,spd); analogWrite(S2,spd);
  h=1;
   
    forward();
     Serial.println("FFFFFF");
  }
 else if((r >lfd && c < lfd && l < lfd)||(r >lfd && c > lfd && l < lfd))
  {
   analogWrite(S1,spd0); analogWrite(S2,spd0);
  h=2;
  b=2;
   right();
 Serial.println("RRRRRRRR");
    
  }
  

  else if((l > lfd && c<lfd && r <lfd)||(l > lfd && c>lfd && r <lfd))
  {
   analogWrite(S1,spd0); analogWrite(S2,spd0);
   h=3;
   b=3;
  left();
  
    Serial.println("LLLLLLLLLLL");
   }
  
 else 
  {
    if (h==1)
    {  analogWrite(S1,spd0); analogWrite(S2,spd0); 

    right();
    /* if (b==2)
     {
     left();
    
   }
   else if (b==3)
   {
    right();
   }*/
     Serial.println("EEEEEEE1111111");
     }
    
    if (h==2)
    {  analogWrite(S1,spd0); analogWrite(S2,spd0);

  
   right();
   Serial.println("EEEEEEEEEE222222222");
    }
    if (h==3)
    {  
      
      analogWrite(S1,spd0); analogWrite(S2,spd0); 
      left();
      Serial.println("EEEEEEEE3333333333");
      }
     
}

}
  
/*int tester ()
{
  f1=0;
  f2=0;
  f3=0;
  f4=0;
  f5=0;
  f6=0;
  ff=0;
  fff=0;
  if (l<lfd && c<lfd && r <lfd)
  {
    f1=1;
  }
  else
  {
    f1=0;
  }
  delay (50);
   if (l<lfd && c>lfd && r <lfd)
  {
    f2=1;
  }
   else
  {
    f2=0;
  }
  delay (50);
    if (l<lfd && c<lfd && r <lfd)
  {
    f3=1;
  }
   else
  {
    f3=0;
  }
   delay (50);
   if (l<lfd && c>lfd && r <lfd)
  {
    f4=1;
  }
   else
  {
    f4=0;
  }
  delay (50);
    if (l<lfd && c<lfd && r <lfd)
  {
    f5=1;
  }
   else
  {
    f5=0;
  }
  delay (50);
   if (l<lfd && c>lfd && r <lfd)
  {
    f6=1;
  }
   else
  {
    f6=0;
  }

  ff=f1+f2+f3+f4+f5+f6;
  
  if (ff>5)
  {
    fff=1;
  }
  else
  {
    fff=0;
  }

  return (fff);
}
*/
