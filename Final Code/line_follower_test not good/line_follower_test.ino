
//motor A

#define in1 8
#define in2 9
//motor b

#define in3 10
#define in4 11


int lineStandard =400;
void setup() {
  // put your setup code here, to run once:
pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    if(center_sen.read() > lineStandard)
  {
    forward();
  }

  else if(right_sen.read() > lineStandard)
  {
 right();
  }

  else if(left_sen.read() < lineStandard)
  {
  left();
  }

  if((left_sen.read() < lineStandard) && (center_sen.read() > lineStandard) && (right_sen.read() > lineStandard) )
  {
    
    forward ();
  }
   else
  {
  
    right ();
  }
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
    {Serial.println("right");
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
