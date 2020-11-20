/*
  ////////////////////////////////////////////////
  ////////////////////////////////////////////////
  Note: This is a test code to check the working of an IR sensor.
      We'll be using it to detect obstacles with the help of an indicator LED.
  ////////////////////////////////////////////////
  ////////////////////////////////////////////////
*/
int indicator = 13;
int IR = 10;
void setup()
{
  // put your setup code here, to run once:

  pinMode(IR, INPUT);                                    // Setting the Output from the IR sensor as an inpur to Arduino
  pinMode(indicator, OUTPUT);                            // Setting the Indicator LED as an Output
  Serial.begin(9600);                                    // Set up the Serial Monitor to dispay data
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(IR))                                   // Checks   if Object is present
  {
    Serial.println("Object Detected");
    digitalWrite(indicator, HIGH);
  }

  else
  {
    Serial.println("Object Not Detected");
    digitalWrite(indicator, LOW);
  }

}
