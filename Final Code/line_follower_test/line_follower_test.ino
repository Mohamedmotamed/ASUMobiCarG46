#define in1 8
#define in2 9
//motor b

#define in3 10
#define in4 11
int r, c, l ;

void setup() {
Serial.begin(9600);
pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
 pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void loop() {
  l=1000-analogRead(A3);
c=analogRead(A4);
r=analogRead(A5);
 Serial.print("l  ");
  Serial.println(1000-analogRead(A3));
  Serial.print("c  ");
  Serial.println(analogRead(A4));
  Serial.print("r  ");
  Serial.println(analogRead(A5));

   if(c > 700 && r < 700 && l < 700)
  {
    forward();
  }
 else if(r > 700 && c < 700 && l < 700)
  {
  right();
  }
  

  else if(l > 700 && c<700 && r <700)
  {
   left();
   }
 else if ( l + r +c >2100)
 {
  forward();
  }
  else 
  {
    Stop();

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

 
  

