#include <elapsedMillis.h>
elapsedMillis timeElapsed=0;
unsigned int interval = 1500;
int led = 13;
int pin6=8;//B2
int pin7=9;//B1
int pin8=10;//A2
int pin9=11;//A1
const int trigPin = 3;
const int echoPin = 2;
int red=5;
int green=4;
int red_state;int green_state;

float duration, distance;

char BluetoothData;

void setup() {
pinMode(led,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(pin9,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
Serial.begin(9600);
}


void loop() {



if (Serial.available()){

BluetoothData=Serial.read();


if(BluetoothData=='L'){ 


digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);

}

else if (BluetoothData=='R'){

digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
  

}
else if(BluetoothData=='F')
{

digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);

}
else if (BluetoothData=='B')
{

digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
}
else
{

digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}


}
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
    
    
    
    //this part of code is responsible on driving a car automaically without andorid app to avoid obstacles


 
  if (distance<200) //2m btw ultra sensor and barrier
  { 
    red_state=digitalRead(red);
    green_state=digitalRead(green);
    if ((distance>0) && (distance<=11))
    { digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);}
    if ((distance>11) && (distance<=30)) //care about range from 18cm to 35cm
    {digitalWrite(red,HIGH); //will detect with a red led
    digitalWrite(green,LOW);
    delay(100);            //just to stable any change
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW); // 4 orders to stop the car
     delay (250);
     do {
      digitalWrite(pin6,LOW);
     digitalWrite(pin7,HIGH);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH);  //refering to back direction
     }
     while (red_state==HIGH);     //this loop will stay excuting as long as our detector (red led) is high
    }
     else if ((distance>30) && (distance<=50))  //another range from more than 35cm to 50cm
     {
      timeElapsed=0; //to reset the counter to 0 before entering the loop
      digitalWrite(green,HIGH);   //here green led is the detector
    digitalWrite(red,LOW);
    delay(100);
     while (timeElapsed <= interval)
     {
    digitalWrite(pin6,HIGH);   
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH); }  //these 4 orders refering to turn right
         //this loop refering to the required time to make car turn right completely -----> measured from video=1.5s
     do {digitalWrite(pin6,HIGH);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW); 
     digitalWrite(pin9,HIGH); //4 orders refering to forward direction
     }
     while (green_state==HIGH); //this loop will stay excuting as long as our detector (green led) is high
     }
  
   else
   {timeElapsed=0;
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
       while (timeElapsed <= interval){
     digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,LOW);}
    
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH); //2 leds here detect that the car in a zone from 50cm to 2m (existance of barrier)

      while(BluetoothData=='L')
   {digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,LOW);}

while(BluetoothData=='R')
{digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);}

while(BluetoothData=='F')
{digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);}

while (BluetoothData=='B')
{digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);}
   }
    
    
    
    
    }



}

