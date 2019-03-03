float value;
int pin_number=4;
void setup()
{pinMode(pin_number,OUTPUT);
Serial.begin(9600);
Serial1.begin(9600);
  }
  void loop()
  {digitalWrite(pin_number,LOW);
  while(Serial1.available())
  {value=Serial1.read();
   Serial.print(value);
  
    }
    }
