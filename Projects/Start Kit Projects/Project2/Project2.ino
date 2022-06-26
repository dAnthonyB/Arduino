// Spaceship interface
int g_nInput = 2;
int g_nGreenLED = 3;
int g_nRedLED1 = 4;
int g_nRedLED2 = 5;
int g_nSwitchState = LOW;

void setup() 
{
    pinMode(g_nGreenLED, OUTPUT);
    pinMode(g_nRedLED1, OUTPUT);
    pinMode(g_nRedLED2, OUTPUT);
    pinMode(g_nInput, INPUT);
}

void loop()
{
  if (digitalRead(g_nInput) == LOW)
  {
    digitalWrite(g_nGreenLED, HIGH);
    digitalWrite(g_nRedLED1, LOW);
    digitalWrite(g_nRedLED2, LOW);
  }
  else
  {
    digitalWrite(g_nGreenLED, LOW);
    digitalWrite(g_nRedLED1, LOW);
    digitalWrite(g_nRedLED2, HIGH);
   
    delay(250);
    digitalWrite(g_nRedLED1, HIGH);
    digitalWrite(g_nRedLED2, LOW);
    delay(250);
  }
}
