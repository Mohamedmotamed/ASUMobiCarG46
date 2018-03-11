int speed;
int pot = A0;
int dir1 = 12; 
int dir2 = 11;
int sw=0;
int motorpin =9;
void setup ()
{
  pinMode (dir1,OUTPUT);
  pinMode (dir2,OUTPUT);
  pinMode (sw,INPUT);
}
void loop ()
{
  
  if (digitalRead (sw)==HIGH)
  {
    digitalWrite (dir1,HIGH);
  digitalWrite (dir2,LOW);
   delay(3000);
  }
  
 
  else 
  {
    
    digitalWrite (dir1,LOW);
  digitalWrite (dir2,HIGH);
   delay(3000);
  }
  speed = analogRead (pot)/4;
  analogWrite (motorpin,speed);
  delay(20);
  
  
 
  
}

