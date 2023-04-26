void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
 
}

void loop()
{
  /*analogWrite(3,255);
  Serial.println("full duty cycle");
  delay(1000);
  analogWrite(3,128); 
   Serial.println("Half duty cycle");
  delay(1000); 
  analogWrite(3,0); 
   Serial.println("zero duty cycle");
  delay(1000);*/ 
   
  int Avalue=analogRead(A0);
  Serial.print("Avalue:");
  Serial.println(Avalue);
  int m=map(Avalue,0,1023,0,255);
  Serial.print("m value is");
  Serial.println(m);
  analogWrite(3,m);
   analogWrite(9,m);
   
  delay(1000);
 
}
