

#include <Servo.h>

Servo myservo; 

int pos = 0,dummy; 
int sensorValue = 0;
char data = 0 ;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  dummy = pos;
}

void loop() 
{
sensorValue = digitalRead(7);
if(sensorValue == 0)
{ 
 close();
}
if(Serial.available()> 0)
{
  data = Serial.read();
  Serial.println(data);

   if(data =='1'){
    open();
    }
    else if(data == '0'){
      close();
      }
  
  }
}

void close(){
   for (pos = dummy; pos <= 180; pos++) { 
    myservo.write(pos); 
    delay(20); 
    dummy = pos;           
       }
  }

  void open(){
   for (pos = dummy; pos > 0; pos--) { 
    myservo.write(pos); 
    delay(20); 
    dummy = pos;           
       }
  }
