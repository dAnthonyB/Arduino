// Love-O-Meter
const int g_nSensorPin = A0;
const float g_fBaselineTemp = 26.0;
int g_nBlueLED = 2;
int g_nYellowLED = 3;
int g_nRedLED = 4;

void setup() 
{
    Serial.begin(9600);
    for (int nPin = g_nBlueLED; nPin <= g_nRedLED; nPin++)
    {
        pinMode(nPin, OUTPUT);
        digitalWrite(nPin, LOW);
    }
}

void loop()
{
  int nSensorVal = analogRead(g_nSensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(nSensorVal);

  // convert the ADC reading to voltage
  float fVoltage = nSensorVal / 1024.0 * 5.0;
  Serial.print(", Volts: ");
  Serial.print(fVoltage);

  // convert the voltage to temperature in degrees C
  float fTempInC = (fVoltage - 0.5) * 100;

  Serial.print(", degrees C: ");
  Serial.println(fTempInC);

  if (fTempInC < g_fBaselineTemp + 2.0)
  {
      digitalWrite(g_nBlueLED, LOW);
      digitalWrite(g_nYellowLED, LOW);
      digitalWrite(g_nRedLED, LOW);
  }
  else if (fTempInC >= g_fBaselineTemp + 1.0 && fTempInC < g_fBaselineTemp + 3)
  {
      digitalWrite(g_nBlueLED, HIGH);
      digitalWrite(g_nYellowLED, LOW);
      digitalWrite(g_nRedLED, LOW);
  }
  else if (fTempInC >= g_fBaselineTemp + 3.0 && fTempInC < g_fBaselineTemp + 5.0)
  {
      digitalWrite(g_nBlueLED, HIGH);
      digitalWrite(g_nYellowLED, HIGH);
      digitalWrite(g_nRedLED, LOW);
  }
  else if (fTempInC >= g_fBaselineTemp + 5.0)
  {
      digitalWrite(g_nBlueLED, HIGH);
      digitalWrite(g_nYellowLED, HIGH);
      digitalWrite(g_nRedLED, HIGH);
  }

  delay(1);
}
