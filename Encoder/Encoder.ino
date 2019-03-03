int pinA=2;
int pinB=3;
volatile  int virPos=50;//Random value
int ref=50;
void isr()
{
  //Check the condition

  if(digitalRead(pinB)!= digitalRead(pinA))
  {if(digitalRead(pinB)>digitalRead(pinA))
    virPos++;
  else 
    virPos--;
  }
  
}
void setup()
 {
  
  Serial.begin(9600);

 
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT);

  
  attachInterrupt(digitalPinToInterrupt(pinA), isr, FALLING);
attachInterrupt(digitalPinToInterrupt(pinB), isr, FALLING);
  Serial.println("Start");
}
void loop()
{

  
   // Serial.print(virPos > ref ? "Up  :" : "Down:");
    Serial.println(virPos);
    delay(500);
    
  }
