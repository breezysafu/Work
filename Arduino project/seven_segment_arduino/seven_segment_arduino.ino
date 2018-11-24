int e=13;
int d=12;
int c=11;
int dp=10;
int b=9;
int a=8;
int f=7;
int g=6;


void zero()
{
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW); 
}

void one()
{
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW); 
}
void two()
{
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH); 
}
void three()
{
  digitalWrite(e,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH); 
}
void four()
{
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
void five()
{
  digitalWrite(e,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
void six()
{
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
void seven()
{
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH); 
}
void eight()
{
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
void nine()
{
  digitalWrite(e,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}


void setup() {
  pinMode(e,OUTPUT);
  pinMode(d,OUTPUT); 
  pinMode(c,OUTPUT);
  pinMode(dp,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  
 

}

void loop() {

  zero();
  delay(1000);
  one();
  delay(1000);
  two();
  delay(1000);
  three();
  delay(1000);
  four();
  delay(1000);
  five();
   delay(1000);
  six();
  delay(1000);
  seven();
  delay(1000);
  eight();
  delay(1000);
  nine();
  delay(1000);



}
