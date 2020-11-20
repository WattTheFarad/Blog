int flexsensor = A0;
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(flexsensor);
Serial.println(val);
delay(50);
}
