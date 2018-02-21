const int button = 8;
const int LED = 6 ;
int ButtonValue = LOW ;
void setup ()
{
  pinMode (button,INPUT);
  pinMode (LED,OUTPUT);
}
void loop ()
{
  
  ButtonValue = digitalRead (button);
  if (ButtonValue==HIGH)
{
  digitalWrite (LED,HIGH);
  delay(20000);
}
else 
digitalWrite (LED,LOW);
}

