//CPP FILE
#include "Rhino.h"
Rhino::Rhino()
{}
Rhino::Rhino(Stream *AttachedSerial)
{AttachRhinoSerial(AttachedSerial);
}
void Rhino::AttachRhinoSerial(Stream *AttachedSerial)
{_serial=AttachedSerial;

}

void Rhino::rotate(int speed1)
{
	String speed=String(speed);
speed="S"+speed;
speed.concat("\r");
_serial->write(speed);
}

		void Rhino::gotoPos(int pos1)
	{
		
		pos1=(int)pos1;
 String pos=String(pos1);
 pos="G"+pos;
 pos.concat("\r");
 _serial->write(pos);
	}


	     void Rhino::setI2CAddr(int addr1)
				{
					
					String addr=String(addr1);	
  					addr="E"+addr;
 					 addr.concat("\r");
  					_serial->write(addr);
				}

				int Rhino::getI2CAddr()
	 			{
					_serial->write("E\r");
				}
				void Rhino::void reset()
	              {
		            _serial->write("Y\r");}



