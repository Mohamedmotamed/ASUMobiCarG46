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
int S1=5 , S2=3;//Capital S
long duration;
int distance;
char estado ;
int spd=255;
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


  
if(Serial.available()>0){ 
estado = Serial.read();
Serial.println("bt " + estado);
} 

if(estado=='L'){
 Max();
left ();

}

else if (estado=='R'){
  Max();
right ();
 
}
else if (estado=='G'){
  analogWrite(S1,200);
  analogWrite(S2,255);
forward ();
 
}
else if (estado=='I'){
  analogWrite(S2,200);
  analogWrite(S1,255);
forward ();
 
}
else if (estado=='H'){
  analogWrite(S1,200);
  analogWrite(S2,255);
  back(); 
}
else if (estado=='J'){
  analogWrite(S2,200);
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
    if (distance <18)
    {
      Stop();
    }
    else
    {
   forward();
    delay(500);
    left();
   delay(300);
   delay(300);
    if (distance <18)
    {
      Stop();
    }
    else 
    {
    forward();
   delay(1000);
    left();
    delay(300);
    delay(300);
    if (distance <18)
    {
      Stop();
    }
    else 
    {
    forward();
    delay(500);
    right();
    delay(300);
    }
    }
    }
  }

 
 void lf ()
   {
      if(c > 500 && r < 500 && l < 500)
  {
   //el code da 3ashan a3ml accelration with time bas faks  el project msh worth it
   /* if (timeElapsed<interval)
    {
    analogWrite(S1,(5+timeElapsed/10));
    analogWrite(S2,(5+timeElapsed/10));
    }
    else if ((timeElapsed/10)>250)
     {
    analogWrite(S1,255);
    analogWrite(S2,255);
    }*/
 
      analogWrite(S1,230); analogWrite(S2,230);
    h=1;
    forward();
     Serial.println("FFFFFF");
  }
 else if(r > 500 && c < 500 && l < 500)
  {
   analogWrite(S1,180); analogWrite(S2,180);
  h=2;
   digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 Serial.println("RRRRRRRR");
    
  }
  

  else if(l > 500 && c<500 && r <500)
  {
   analogWrite(S1,180); analogWrite(S2,180);
   h=3;
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
    Serial.println("LLLLLLLLLLL");
   }
 else if ( l + r + c > 2000)
 {
       analogWrite(S1,230); analogWrite(S2,230);
  h=1;
  forward();
  Serial.println("AAAAAAAAAAA");
  }
  
  else 
  {
    if (h==1)
    {  analogWrite(S1,180); analogWrite(S2,180); digitalWrite(in1, HIGH); digitalWrite(in2, LOW); digitalWrite(in3, LOW); digitalWrite(in4, LOW);Serial.println("EEEEEEE1111111");}
    if (h==2)
    {  analogWrite(S1,180); analogWrite(S2,180); digitalWrite(in1, HIGH); digitalWrite(in2, LOW); digitalWrite(in3, LOW); digitalWrite(in4, LOW);Serial.println("EEEEEEEEEE222222222");}
    if (h==3)
    {  analogWrite(S1,180); analogWrite(S2,180); digitalWrite(in1, LOW); digitalWrite(in2, LOW); digitalWrite(in3, HIGH); digitalWrite(in4, LOW);Serial.println("EEEEEEEE3333333333");}
}
  
  }
