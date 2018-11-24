#include <Servo.h> 
Servo myservo;

int state;
void setup()
{
  myservo.attach(12);// here depends on which pin you've 
                      //connected your Servo motor
  Serial.begin(9600);
  myservo.write(0);
}

void loop()
{
  if(Serial.available() > 0){     
      state = Serial.read(); }

       myservo.write(state);
}

