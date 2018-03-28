#include <elapsedMillis.h>
elapsedMillis timeElapsed=0;
unsigned int interval = 1500;
unsigned int interval2 = 3000;
unsigned int interval3 = 4500;
int led = 13;
int pin6=8;//B2
int pin7=9;//B1
int pin8=10;//A2
int pin9=11;//A1
const int trigPin = 3;
const int echoPin = 6;
int red=5;
int green=4;
int red_state;
int green_state;
float duration, distance;
const int ex=55;
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


 red_state=digitalRead(red);
    green_state=digitalRead(green);
 
  
  if ((distance>=0)&&(distance<55)) //55cm btw ultra sensor and barrier
  { 
    
   if ((distance>0) && (distance<=11))
    {digitalWrite(red,HIGH); 
    digitalWrite(green,HIGH);
    delay (200);
    digitalWrite(red,LOW); 
    digitalWrite(green,LOW);
                               //detect with flashing
      digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);}
    else if ((distance>11) && (distance<=27.2)) //care about range from 11cm to 27.2cm
    {digitalWrite(red,HIGH); //will detect with a red led
    digitalWrite(green,LOW);
    delay(100);            //just to stable any change
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW); // 4 orders to stop the car
     delay (250);
     if (red_state==HIGH) {
      digitalWrite(pin6,LOW);
     digitalWrite(pin7,HIGH);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH);  //refering to back direction
     }
          //this loop will stay excuting as long as our detector (red led) is high
    }
     else if ((distance>27.2) && (distance<=40))  //another range from more than 27.2cm to 40cm
     {
      timeElapsed=0; //to reset the timer to 0 before entering the loop
      digitalWrite(green,HIGH);   //here green led is the detector
    digitalWrite(red,LOW);
    delay(100);
     if (timeElapsed <= interval)
     {
    digitalWrite(pin6,HIGH);   
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH); }  //these 4 orders refering to turn right
         //this loop refering to the time required  to make car turn right completely -----> measured from video=1.5s
     if ((green_state==HIGH)&& (timeElapsed > interval)) {
      digitalWrite(pin6,HIGH);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW); 
     digitalWrite(pin9,HIGH); //4 orders refering to forward direction
     timeElapsed=0;
     }
      //this loop will stay excuting as long as our detector (green led) is high
     }
  
   else
   {if (timeElapsed > interval){
    
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH); //2 leds here detect that the car in a region from 40cm to 55cm (existance of barrier)

       if (timeElapsed <= interval2){
     digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,LOW);}
    
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
   }}
  }    else {
    digitalWrite(red,LOW); 
    digitalWrite(green,LOW);
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
     if ((timeElapsed >= interval)&& (timeElapsed <= interval2)) {
      digitalWrite(red,LOW); 
    digitalWrite(green,HIGH); //acting like stage 3
    
      digitalWrite(pin6,HIGH);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW); 
     digitalWrite(pin9,HIGH); //4 orders refering to forward direction
     }
       else if ((timeElapsed >= interval2)&&(timeElapsed <= interval3)){
          digitalWrite(red,HIGH); 
    digitalWrite(green,HIGH); //acting like stage 4
    
     digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,LOW);}  //left direction
    
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
   timeElapsed=0;
     
    
if ((Serial.available())&&(timeElapsed <= interval)){

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
      
    }
    
    
    
    }




