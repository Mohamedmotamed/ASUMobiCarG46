#define LED 13
#define BUTTON 7
void setup()
{
pinMode(LED, OUTPUT);
pinMode(BUTTON, INPUT);
}
void loop()
{
int value = digitalRead(BUTTON);
digitalWrite(LED, value);
}

