//Header file
#ifndef Rhino_h
#define Rhino_h
#include "Arduino.h"
#include "Stream.h"

class Rhino
{Stream *_serial
 public: 
 Rhino();
 Rhino(Stream *AttachedSerial);
 void AttachRhinoSerial(Stream *AttachedSerial);
 
 
 
 void rotate(int speed);
 void gotoPos(int pos);
 void setI2CAddr(int addr);

 
 int getI2CAddr();
 void reset();
};
  #endif