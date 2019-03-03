#include <Encoder.h>
int pinA=2;
int pinB=3;
Encoder _serial;
void setup() {
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

attachInterrupt(digitalPinToInterrupt(pinA), isr, FALLING);
attachInterrupt(digitalPinToInterrupt(pinB), isr, FALLING);
Serial.println("Start");
_serial.AttachEncoderSerial(&Serial1);
Serial.println("1.Go to Posititon 2. Reset 3. ISR 4. goToAngle  ");
}

void loop() {
 Serial.println("Enter choice");
 int ch=Serial.read();
 switch(ch)
 {case 1:Serial.print("Enter position");
          _serial.goToPos(Serial.parseInt());
          break;
  case 2:_serial.reset();
          break;
  case 3: _serial.isr()
          break;
  case 4: _serial.goToAngle()
          break;
  }
}
