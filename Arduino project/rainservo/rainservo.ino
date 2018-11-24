#include <Servo.h>
Servo myServo;
int const potPin = A0;
int potVal;
int angle;
void setup() {
// initialize serial communication at 9600 bits per second:
myServo.attach (9);
Serial.begin(9600);
}


void loop() {
// read the input on analog pin 0:
int sensorValue = analogRead(A0); Serial.println(sensorValue);
delay(100);}

int sensorValue = LOW;
potVal = analogRead(potPin);
Serial.print("potVal; ");
Serial.print(angle);
angle = map(potVal 1, 1023,1 179);
Serial.print(", angle; ");
Serial.println(angle);
myServo.write(angle);
delay(20);
}

}
