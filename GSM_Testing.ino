#include <SoftwareSerial.h>

SoftwareSerial GSM_Sim800l(10, 11);    // Software Serial Object for the GSM SIM800L

String textMessage;                    // Incoming Text Message

const int led = 13;                    // Indicator Led


void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);             // Initial State of Led is LOW

  Serial.begin(9600);


  GSM_Sim800l.begin(2400);            //Start Serial communication between Arduino and SIM800L

  Serial.println("Initializing...");
  delay(1000);

  GSM_Sim800l.println("AT");                   //If the initial connection is successful, it will return OK
  update_GSM();

  GSM_Sim800l.println(" AT+CMEE=2");           // Used to display if there are any errors
  update_GSM();

  //GSM_Sim800l.println("AT+CMGS=?;+CMSS=?;+CNMI=?;+CMGL=?;+CMGR=?");
  //update_GSM();

  GSM_Sim800l.println("AT+CMGF=1");           // Configuring to TEXT mode
  update_GSM();
  GSM_Sim800l.println("AT+CNMI=1,2,0,0,0");  // Decides how newly arrived SMS messages should be indicated
  update_GSM();
}
void func(String textMessage)
{
  if (textMessage.indexOf("ON") > 0)
  {
    Serial.println("Works");
    digitalWrite(led, HIGH);

    GSM_Sim800l.println("AT+CMGF=1\r");                    // TEXT Mode
    delay(50);
    GSM_Sim800l.println("AT+CMGS=\"+************\"\r");    // Sends message to this particular Number
                                                           // Country code + Number; Example: 915678956789
    delay(50);

    GSM_Sim800l.println("Light is ON");                    // This is the text sent

    delay(50);

    GSM_Sim800l.println((char)26);                         // Required to end the message

    delay(50);

    GSM_Sim800l.println();
    delay(50);
  }
  if (textMessage.indexOf("OFF") > 0)
  {
    Serial.println("Works");
    digitalWrite(led, LOW);
    GSM_Sim800l.println("AT+CMGF=1\r");
    delay(50);
    GSM_Sim800l.println("AT+CMGS=\"+************\"\r");

    delay(50);

    GSM_Sim800l.println("Light is OFF");

    delay(50);

    GSM_Sim800l.println((char)26);
    delay(500);
    GSM_Sim800l.println();

    delay(50);
  }


  delay(10);
}

void loop()
{
  update_GSM();
}

void update_GSM()
{
  delay(500);

  while (Serial.available())
  {
  
    GSM_Sim800l.write(Serial.read());       //Push data to Software Serial Port (GSM)
  
  }
  
  while (GSM_Sim800l.available())
  {
    textMessage = GSM_Sim800l.readString(); // Read incoming message
    Serial.println(textMessage);
    func(textMessage);
    delay(10);
    Serial.write(GSM_Sim800l.read());      //Push data to Serial Port (Arduino)
  }
}
