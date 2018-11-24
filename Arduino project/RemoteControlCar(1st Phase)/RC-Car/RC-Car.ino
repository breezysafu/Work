/*
 * #ifndef check whether variable is defined earlier or not in header file
 * If it is not defined #define assign value to it.  
 * It is safe to use for constant because it may have been declared in header file
 */
#ifndef BTSTATE
#define BTSTATE 0 //initial condition for car i.e rest
#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif

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
char state;
int vSpeed = 150; // assigning default speed
int ledState = 0;


void setup() {
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {

  // initially setting car to rest
  if(digitalRead(BTSTATE)==LOW) { state='S'; }
  
  // Check incoming data and set it to variable
  if (Serial.available()){
    state = Serial.read(); 
    Serial.println(state);   
  }
  
  
  // Change speed
  if (state == '0'){
    vSpeed = 0;
  }
  else if (state == '1'){
    vSpeed = 75;   

  }
  else if (state == '2'){
    vSpeed = 150;
  }
  else if(state == '3'){
    vSpeed = 200;
  }
  else if(state == '4'){
    vSpeed = 255;
  }

  // change direction
  if (state == 'F'){
  car1.forward(vSpeed);
    
  }
  else if (state == 'G'){
  car1.left_forward(vSpeed);
 
  }
  else if (state == 'I'){
  car1.right_forward(vSpeed);
  }
  else if (state == 'L'){
  car1.left(vSpeed);
  }
  else if (state == 'R'){
   car1.right(vSpeed);
  }
  else if (state == 'B'){
   car1.reverse(vSpeed);
  }
  else if (state == 'H'){
   car1.left_reverse(vSpeed);
  }
   else if (state == 'J'){
   car1.right_reverse(vSpeed);
  }
   else if (state == 'S'){
   car1.stopCar();
  }
  else if(state == 'W'){
  //Toggle LED lights
    ledState = (ledState == 1)?0:1;
  }

  else if (state == 'V'){
    exit(0);
  }

  // turn the lights on or off
  if (ledState == 1) digitalWrite(13,HIGH);
  else if (ledState == 0) digitalWrite(13,LOW);

}
