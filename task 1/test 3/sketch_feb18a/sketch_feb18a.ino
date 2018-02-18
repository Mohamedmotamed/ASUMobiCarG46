#define LED 13
#define LDR 2
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  }
  
  void loop()
  {
    int value = digitalRead(LDR);
    digitalWrite(LED, value);
}

