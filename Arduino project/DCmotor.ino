void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  

}

void loop() {
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  analogWrite(9,450);
  delay(1000);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  analogWrite(9,450);
  delay(1000);
  
  
  

}
