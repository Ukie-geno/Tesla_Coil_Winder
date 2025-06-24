
// This program counts the number of revolutions of a rotating cylinder using the IR detector module
// It was designed for a tesla coil winder

const int analogInPin = A0;
int cnt = 0;
bool enable_count = false;

int sensorValue = 0;  // value read from the pot

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  if (sensorValue > 500) enable_count = true;

  if (enable_count)
  {
    if ((sensorValue >= 10) && (sensorValue <= 100))
    {
      enable_count = false;
      cnt++;
    }
  }
  
  Serial.println(cnt);

  delay(10);
}
