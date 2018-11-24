void setup() {
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(4,OUTPUT);
pinMode(2,OUTPUT);
pinMode(6,OUTPUT);

}

void loop() {


digitalWrite(8,LOW);
digitalWrite(7,HIGH);
analogWrite(9,200);
delay(1000000);

digitalWrite(4,LOW);
digitalWrite(2,HIGH);
analogWrite(6,150);
delay(100);
digitalWrite(4,LOW);
digitalWrite(2,LOW);
analogWrite(6,150);
delay(100);
digitalWrite(2,LOW);
digitalWrite(4,HIGH);
analogWrite(6,150);
delay(100);
digitalWrite(4,LOW);
digitalWrite(2,LOW);
analogWrite(6,150);
delay(100);

}
