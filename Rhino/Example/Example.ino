#include <Rhino.h>



Rhino _serial;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  _serial.AttachRhinoSerial(&Serial1);
  Serial.println("S-Speed, G-position, E-I2C address, ");
}

void loop() {
  Serial.println("Enter character");
  char ch = Serial.read();
  switch (ch)
  { case 'Y':
    case 'y': {
        _serial.reset();
        break;
      }


    case 's':
    case 'S': {
        Serial.print("enter speed");
        
       _serial.rotate(Serial.parseInt());
        break;
      }
    case 'g':
    case 'G': {
        Serial.print("enter position");
        
        _serial.gotoPos(Serial.parseInt());
        break;
      }
    case 'E':
    case 'e': {
        Serial.print("Enter address");
        
        _serial.setI2CAddr(Serial.parseInt());
        break;
      }



  }
  

}
