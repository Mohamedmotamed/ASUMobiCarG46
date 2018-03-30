#include <elapsedMillis.h>
elapsedMillis timeElapsed=0;
unsigned int interval = 1500;
int i;
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
  delayMicroseconds(2);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.034029)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
    timeElapsed=0;
       
        if ((Serial.available())&&(distance>=55)){
      

BluetoothData=Serial.read();


if(BluetoothData=='L'){ 
Serial.println("left");

digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);

}

else if (BluetoothData=='R'){
Serial.println("right");
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
  

}
else if(BluetoothData=='F')
{
Serial.println("frward");
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);

}
else if (BluetoothData=='B')
{
Serial.println("back");
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
}
else
{
Serial.println("stop");
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}}
    
    
    
    
    //this part of code is responsible on driving a car automaically without andorid app to avoid obstacles




  
  else  if ((distance>=0)&&(distance<55)) //55cm btw ultra sensor and barrier
  { 
    
   if ((distance>0) && (distance<=11))  //(stage 1)
    {digitalWrite(red,HIGH); 
    digitalWrite(green,HIGH);
    delay (200);
    digitalWrite(red,LOW); 
    digitalWrite(green,LOW);
      Serial.println("auto stop range 1");                         //detect with flashing
      digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);}
    else if ((distance>11) && (distance<=27.2)) //care about range from 11cm to 27.2cm ---->(stage 2)
    {digitalWrite(red,HIGH); //will detect with a red led
    digitalWrite(green,LOW);
    delay(100);            //just to stable any change
    Serial.println("auto stop range 2"); 
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW); // 4 orders to stop the car
     delay (250);
     if ( digitalRead(red) ==HIGH) {
      Serial.println("auto back range 2"); 
      digitalWrite(pin6,LOW);
     digitalWrite(pin7,HIGH);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH);  //refering to back direction
     }
          //this loop will stay excuting as long as our detector (red led) is high
    }
     else if ((distance>27.2) && (distance<=40))  //another range from more than 27.2cm to 40cm ----->(stage 3)
     {
      timeElapsed=0; //to reset the timer to 0 before entering the loop
      digitalWrite(green,HIGH);   //here green led is the detector
    digitalWrite(red,LOW);
    delay(100);
    for ( i=0;i<1;i++){
   while (timeElapsed<=interval)
     {
      Serial.println("auto right range 3");
      Serial.println( "timeElapsed=");
      Serial.println( timeElapsed);
    digitalWrite(pin6,HIGH);   
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,HIGH); 
     
      } }//these 4 orders refering to turn right
         //this loop refering to the time required  to make car turn right completely -----> measured from video=1.5s
        timeElapsed=1500;
     Serial.println( "finally");
    
    while (digitalRead (green)==HIGH) {
     if ( timeElapsed==1500) {
      Serial.println("auto forward range 3"); 
      digitalWrite(pin6,HIGH);   
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,HIGH); 
     digitalWrite(pin9,LOW); //4 orders refering to forward direction
     
     }}timeElapsed=0;
      //this loop will stay excuting as long as our detector (green led) is high
     }
  
   else                             //stage 4
   {if (timeElapsed <= interval){
    Serial.println("auto stop range 4"); 
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);  //stop forwarding from previous stage
     delay (150);
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH); //2 leds here detect that the car in a region from 40cm to 55cm (existance of barrier)

       while (timeElapsed < interval){
        Serial.println("auto left range 4"); 
     digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    digitalWrite(pin9,LOW);
    }                           //to turn left copmpletely (90 degree)
    Serial.println("auto stop range 4"); 
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
   }}
  }    else {
   
    digitalWrite(red,LOW); 
    digitalWrite(green,LOW);
     Serial.println("auto stop range 5"); 
    digitalWrite(pin6,LOW);
     digitalWrite(pin7,LOW);
     digitalWrite(pin8,LOW);
     digitalWrite(pin9,LOW);
     delay (150);
     if ((timeElapsed >= interval)&& (timeElapsed <= (interval+interval)))
     {
          digitalWrite(red,LOW); 
          digitalWrite(green,HIGH); //acting like stage 3
          while (timeElapsed <= (interval+interval))
         {
           Serial.println("auto forward range 5.5"); 
          digitalWrite(pin6,HIGH);
          digitalWrite(pin7,LOW);
          digitalWrite(pin8,LOW); 
          digitalWrite(pin9,HIGH);  //4 orders refering to forward direction
         } 
         timeElapsed=3000;
     }
       else if ((timeElapsed >=(interval+interval))&&(timeElapsed < (interval+interval+interval))){
          digitalWrite(red,HIGH); 
          digitalWrite(green,HIGH); //acting like stage 4
          while (timeElapsed <= 3*interval)
          {
             Serial.println("auto lefe range 5.5"); 
          digitalWrite(pin6,LOW);
          digitalWrite(pin7,HIGH);
          digitalWrite(pin8,HIGH);
          digitalWrite(pin9,LOW); }  //left direction
           timeElapsed=0;
       }
       
      
   }
       
    
    
    
     }




