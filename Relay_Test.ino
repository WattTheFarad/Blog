/*
////////////////////////////////////////////////
////////////////////////////////////////////////
Note: This is an active low relay. Which basically means
      Relay is ON, when power signal is LOW
      Relay is OFF, when power signal is HIGH
////////////////////////////////////////////////
////////////////////////////////////////////////
 */


int relay_switch = 10;

void setup() 
{
  // put your setup code here, to run once:
pinMode(relay_switch,OUTPUT);                           //Setting the relay as an output 
}
                                             
void loop() 
{
  // put your main code here, to run repeatedly:

digitalWrite(relay_switch,HIGH);                        // Relay is OFF for one second  
delay(1000);

digitalWrite(relay_switch,LOW);                         // Relay is On for one second
delay(1000);
}
