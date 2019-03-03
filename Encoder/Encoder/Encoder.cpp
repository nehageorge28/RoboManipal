//CPP File
#include "Encoder.h"
int ref=50;
volatile  int virPos=50;//Random value

Encoder::Encoder()
{
//Empty constructor
}
Enocder::Encoder(Stream *AttachedSerial)
{AttachEncoderSerial(AttachedSerial);
}
void Encoder::gotoPos(int pos)
{
	_serial->write(pos);
}

 void Encoder::reset()
 {
 
    virPos= 50;
    Serial.println("Reset");}
// If the current rotary switch position has changed then update everything
  if (virPos!= ref) 
  {
    Serial.println(virPos);
   // Keep track of this new value
    ref = virPos;
}
void Encoder::isr()
{
  //Check the condition

  if(digitalRead(pinB)!= digitalRead(pinA))
  {if(digitalRead(pinB)>digitalRead(pinA))
    virPos++;
  else 
    virPos--;
  } Serial.println(virPos);
  
}
void Encoder::goToAngle()
{
	angle=virPos*0.375;
	_serial->write(angle);
}
