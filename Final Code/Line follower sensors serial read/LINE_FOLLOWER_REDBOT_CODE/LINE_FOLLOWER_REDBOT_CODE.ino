#include <elapsedMillis.h>



//motor A
#include <RedBot.h>
#define in1 8
#define in2 9
//motor b

#define in3 10
#define in4 11
 
int lineStandard = 800;
int r, c, l ;
const int trigPin = 2;
const int echoPin = 6;
int led = 13;
int S1=5 , S2=3;//Capital S
long duration;
int distance;
char estado ;
unsigned int interval = 1000;
  elapsedMillis timeElapsed;
void setup() {
  RedBotSensor left_sen =1000 - RedBotSensor(A3);   
RedBotSensor center_sen = RedBotSensor(A4); 
RedBotSensor right_sen = RedBotSensor(A5); 
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
 if(center_sen.read() > lineStandard)
  {//right
   right();
  }
  //data_sheet
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right_sen.read() > lineStandard)
  {//left
  left();
  }
  //data_sheet
  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left_sen.read() > lineStandard)
  {//right
  right();
  }
  //data_sheet
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left_sen.read() > lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    //stop
    Stop ();
  }
  else
  {
  //any dir
    forward();
  }
  delay(0);  // add a delay to decrease sensitivity.
}
/*l=1000-analogRead(A3);
c=analogRead(A4);
r=analogRead(A5);
 Serial.print("l  ");
  Serial.println(1000-analogRead(A3));
  Serial.print("c  ");
  Serial.println(analogRead(A4));
  Serial.print("r  ");
  Serial.println(analogRead(A5));



  
/*if(Serial.available()>0){ 
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
else if(estado=='F')
{
  Max();
forward ();

if (distance<=15)
 {

   
   while(timeElapsed<interval)
   {
   digitalWrite(13, HIGH);
  back();
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
}*/
 

  void right() {
  analogWrite(S1,255);
  analogWrite(S2,255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Stop () {
  analogWrite(S1, 0);
  analogWrite(S2, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void left() {
  analogWrite(S1, 255);
  analogWrite(S2, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forward() {
  analogWrite(S1, 255);
  analogWrite(S2, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void back(){

   analogWrite(S1, 255);
  analogWrite(S2, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
  
/*void Max()
{
  analogWrite(S1,255);
  analogWrite(S2,255);
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

 
  
 void lf ()
  {
    analogWrite(S1,150);
    analogWrite(S2,150);
      if(c > 700 && r < 700 && l < 700)
  {
    forward();
  }
 else if(r > 700 && c < 700 && l < 700)
  {
   digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
  }
  

  else if(l > 700 && c<700 && r <700)
  {
     digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   }
 else if ( l + r +c >2100)
 {
  forward();
  }
  else 
  {
     digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 }
  
  }*/
