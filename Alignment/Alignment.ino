

//Constants
#define ULTRAECHOBL 5 // give the pin numbers for echo pin in backward left position
#define ULTRATRIGBL 4 // give the pin numbers for trigger pin in backward left position

#define ULTRAECHOBR 10 // give the pin numbers for echo pin in backward right position
#define ULTRATRIGBR 9 // give the pin numbers for trigger pin in backward right position
#define THRESHOLD 10 //this stores the max distance upto which you can classify an object as an obsruction

//Global Variables

int us1;
int us2;
int thresh=10;

void setup()
{ pinMode(ULTRATRIGBL,OUTPUT);
  pinMode(ULTRAECHOBL,INPUT);
  pinMode(ULTRATRIGBR,OUTPUT);
  pinMode(ULTRAECHOBR,INPUT);
  Serial.begin(9600); 

}

void getUSValues()
{
  digitalWrite(ULTRATRIGBL,LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRATRIGBL,HIGH);
  delayMicroseconds(2);
  digitalWrite(ULTRATRIGBL,LOW);

  long timedelay = pulseIn(ULTRAECHOBL,HIGH);
  us1 = 0.0343 * (timedelay/2);

  delayMicroseconds(2);

  digitalWrite(ULTRATRIGBR,LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRATRIGBR,HIGH);
  delayMicroseconds(2);
  digitalWrite(ULTRATRIGBR,LOW);

  long td = pulseIn(ULTRAECHOBR,HIGH);
  us2 = 0.0343 * (td/2);
  Serial.println("Values are" );
  Serial.print(us1);
  Serial.print("\t");
  Serial.println(us2);
  delay(100);
 
}

void align()
{

    
      if(us2>us1)
        {//Move the motor on the us2 side forward
      Serial.println("Move US2 side motor forward");
        }
      else
      {//Move the motor on the us1 side forward
        Serial.println("Move the US1 side motor forward");

      }
    
    if(us2==us1)
      {//Bot aligned parallel to the wall
        Serial.println("Bot aligned");
      }
  delay(1000)  ;
}

void thresholdCondition()
{

  if(us2<thresh && us1<thresh)
  {//Reverse the bot in the same alignment and start over
    Serial.println("Reverse the bot");

  }
}

void loop()
{
  getUSValues();
  delay(1000);
  thresholdCondition();
  delay(1000);
  align();
  delay(1000);
}
