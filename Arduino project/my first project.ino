int trigpin= 13;
int echopin= 11;
float pingtime;
float speedofsound= 332; //meter per second
float distance; //inch 

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  pingtime=pulseIn(echopin,HIGH);
  distance=speedofsound*pingtime/2; 
  distance=distance/1000000; //meter
  Serial.print("the distance is :");
  Serial.print(distance);
  Serial.println("meter");
  delay(3000);
  

}
