
int trigpin=13; //sensor trig pin is connected to arduino pin 13
int echopin=11; //sensor echo pin is conected to arduino pin 11

float pingtime;
float targetdistance=6;
float speedofsound;

void setup() {
 Serial.begin(9600); //turn on serial port
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, OUTPUT);
 
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigpin,LOW);

  pingtime=pulseIn(echopin,HIGH);

  speedofsound=2*targetdistance/pingtime;
  speedofsound=speedofsound/63360*1000000*3600;
  

  Serial.print("The speed of sound is:");
  Serial.print(speedofsound);
  Serial.println("miles per hour");

 
 }
