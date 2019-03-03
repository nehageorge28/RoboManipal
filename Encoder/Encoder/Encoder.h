//Header File
#ifndef Encoder_h
#define Encoder_h
#include "Arduino.h"
#include "Stream.h"

class Encoder
{
	Stream *_serial;
public:
	Encoder();
	Encoder(Stream *AttachedSerial);
	void gotoPos(int pos);
	 void reset();
	 void isr();
	 void goToAngle();
	};
	#endif
