//Libraries
#include <Servo.h> 
#include "Ultrasonic.h"

class Motor{
  
  /* 
          MOTOR_MOTOR_PIN1 ------------> IN1/IN3
          MOTOR_MOTOR_PIN2 ------------> IN2/IN4
          ENABLE_MOTOR_MOTOR_PIN ------------> enableMOTOR_MOTOR_PIN
             __    __    __
          __|  |__|  |__|  |__  Pulse Width Modulation PWM (here 'pulsewm' variable)
  */
    public:
    int MPIN1,MPIN2,ENABLE;
    int pulsewm;
    
  public:
    Motor(){}
                                                          
    void forward(int plusewm); // driving motor forward logic
    void reverse(int plusewm);// driving motor backward logic
    void stopmo(); //Stop the motor
    void left(int plusewm); // driving motor left logic
    void right(int plusewm);// driving motor right logic
};
void Motor::left(int plusewm){
  forward(plusewm);
}

void Motor::right(int plusewm){
  reverse(plusewm);
}

void Motor::forward(int plusewm){
  digitalWrite(this->MPIN1,HIGH); 
  digitalWrite(this->MPIN2, LOW);
  analogWrite(this->ENABLE, plusewm);                      
}
void Motor::reverse(int plusewm){
  digitalWrite(this->MPIN1, LOW); 
  digitalWrite(this->MPIN2,HIGH);
  analogWrite(this->ENABLE, plusewm);                     
}
void Motor::stopmo(){
  digitalWrite(this->MPIN1, LOW);
  digitalWrite(this->MPIN2, LOW);
  analogWrite(this->ENABLE, 0);
}


class Car{
  
  public:
    Motor Front , Back ;
  public:
  
    Car(int bmoPin1,int bmoPin2,int benPin ,int fmoPin1,int fmoPin2,int fenPin)
    { 
     Back.MPIN1 = bmoPin1; 
     Back.MPIN2 = bmoPin2;
     Back.ENABLE = benPin;
     Front.MPIN1 = fmoPin1; 
     Front.MPIN2 = fmoPin2; 
     Front.ENABLE = fenPin; }
                                                                                                      
    void forward(int plusewm); // Moving Car forward logic
    void reverse(int plusewm);// Moving Car backward logic
    void stopCar(); //Stop the Car
    void left(int plusewm); // Move Car to left
    void right(int plusewm);// Move Car to right
    
    void left_forward(int plusewm); // Move Car to left and forward
    void right_forward(int plusewm);// Move Car to right and forward
    void left_reverse(int plusewm); // Move Car to left and reverse
    void right_reverse(int plusewm);// Move Car to right and reverse

 
};

void Car::forward(int plusewm){
  Back.forward(plusewm);                     
}
void Car::reverse(int plusewm){
  Back.reverse(plusewm);                     
}
        

inline void Car::stopCar(){
  Back.stopmo();
  Front.stopmo();

}

void Car::left(int plusewm){
  Front.left(plusewm);
}

void Car::right(int plusewm){
  Front.right(plusewm);
}

void Car::left_forward(int plusewm){
   Front.left(plusewm);
   Back.forward(plusewm);
}

void Car::right_forward(int plusewm){
  Front.right(plusewm);
  Back.forward(plusewm);
}
void Car::left_reverse(int plusewm){
   Front.left(plusewm);
   Back.reverse(plusewm);
}

void Car::right_reverse(int plusewm){
  Front.right(plusewm);
  Back.reverse(plusewm);
}


Car car1(9, 8 , 5,2, 4, 3);

Ultrasonic ultrasonic(A4 ,A5); //Create Ultrsonic object ultrasonic(trig pin,echo pin)
Servo myservo;          //Create Servo object to control a servo

//Variables
int distance;         //Variable to store distance from an object
int checkRight;
int checkLeft;
int active = 0;         //Variable to store function of robot: '1' running or '0' stoped. By default is stoped
int buttonState=1;            //Variable to store the state of the button. By default '0'
int pos=90;             //Variable to store the servo position. By default 90 degrees - sensor will 'look' forward
int vSpeed = 75 ;
char state;

void setup()
{
   
    myservo.attach(7); //Servo pin connected to pin 5
    myservo.write(0);
    Serial.begin(9600);
}

void loop()
{
  //Check button state
   if (Serial.available()){
    state = Serial.read(); 
    Serial.println(state);   
  }
  
  // Activate Auto mode
  if (state == 'F'){
  buttonState = 1 ;
                Serial.println("automode");   

  }

  //Deactive Auto mode
   if (state == 'B'){
  buttonState = 0 ;
  }
    
  
  //Change main function (stoped/running) when button is pressed 
    if (buttonState == 0) {
      
          active = 0;
              Serial.println("inactive");   

      }
      else if ( buttonState == 1){   
        active = 1;
        Serial.println("active");   
      }    
    
    
  if (active == 0){   //If button is unpressed or pressed twice then:
                  Serial.println("servo active");   

    myservo.write(90);    //set servo 90 degress - sensor will look forward
    car1.stopCar();         //robot remain stoped
    
  }
  else if (active == 1){//If button is pressed then:
                      Serial.println("distance measurement active");   

    //Read distance...
    distance = ultrasonic.Ranging(CM); //Tip: Use 'CM' for centimeters or 'INC' for inches
                          Serial.println(distance);   

    //Check for objects...
    if (distance > 10){
                            Serial.println("distance is greater than zero hence forward");   

      car1.forward(vSpeed); //All clear, move forward!
    }
    else if (distance <=10){
      car1.stopCar(); //Object detected! Stop the robot and check left and right for the better way out!
    
      //Start scanning... 
      for(pos = 0; pos < 180; pos += 1){  //goes from 0 degrees to 180 degrees 
                myservo.write(pos);             //tell servo to go to position in variable 'pos' 
                delay(10);                      //waits 10ms for the servo to reach the position 
            } 
            
            checkLeft = ultrasonic.Ranging(CM);   //Take distance from the left side
            
            for(pos = 180; pos>=0; pos-=1){     //goes from 180 degrees to 0 degrees                           
                myservo.write(pos);             //tell servo to go to position in variable 'pos' 
                delay(10);                      //waits 10ms for the servo to reach the position   
            }
            
            checkRight= ultrasonic.Ranging(CM);
            
            myservo.write(90);                   // Sensor "look" forward again
            
            //Finally, take the right decision, turn left or right?
            if (checkLeft < checkRight){
              car1.left_forward(vSpeed);
              delay(400); // delay, change value if necessary to make robot turn.            
              }
            else if (checkLeft > checkRight){
              car1.right_forward(vSpeed);
              delay(400); // delay, change value if necessary to make robot turn.
            }
            else if (checkLeft <=10 && checkRight <=10){
              car1.reverse(vSpeed); //The road is closed... go back and then left ;)
              car1.left(vSpeed);
            }
    }
  }

}


