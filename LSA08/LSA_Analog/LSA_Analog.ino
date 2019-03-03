const int analogPin = A0;   // Connect AN output of LSA08 to analog pin 0
float readVal,positionVal;    // Variables to store analog and line position value
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
readVal = analogRead(analogPin); 
positionVal = ((float)readVal/921)*70;


Serial.println(positionVal);
delay(500);




}
