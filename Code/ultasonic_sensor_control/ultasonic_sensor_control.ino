int trigpin1=14,echopin1=15,trigpin2=16,echopin2=17,trigpin3=18,echopin3=19;
long durationL,distanceL,durationC,distanceC,durationR,distanceR;

int ultrasonic_sensor1();
int ultrasonic_sensor2();
int ultrasonic_sensor3();

void setup() {
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1, INPUT);
  Serial.begin(9600);
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(trigpin3,OUTPUT);
  pinMode(echopin3, INPUT);
}

void loop() 
{
  ultrasonic_sensor1();
  ultrasonic_sensor2();
  ultrasonic_sensor3();
  if(distanceL<=30 || distanceR<=30 || distanceC<=30)
  {
    //stop();
    delay(2000);
  }
  else if(distanceL>distanceC && distanceL>distanceR)
  {
    //Leftturn();
    delay(1000);
  }
  else if(distanceR>distanceL && distanceR>distanceC)
  {
    // Rightturn();
    delay(1000);
  }
  else
  {
    //Forward();
    delay(1000);
  }
   
   
}
int ultrasonic_sensor1()
{
 digitalWrite(trigpin1,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(20);
  durationL=pulseIn(echopin1,HIGH);
  //distance=duration/58.2;
  distanceL=(durationL*0.0343)/2;
  Serial.println("distanceL:");
  Serial.println(distanceL);
  delay(100);
  return(distanceL);
}
int ultrasonic_sensor2()
{
 digitalWrite(trigpin2,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(20);
  durationC=pulseIn(echopin2,HIGH);
  distanceC=(durationC*0.0343)/2;
  Serial.println("distanceC:");
  Serial.println(distanceC);
  delay(100);
  return(distanceC);
}
int ultrasonic_sensor3()
{
 digitalWrite(trigpin3,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin3,HIGH);
  delayMicroseconds(20);
  durationR=pulseIn(echopin3,HIGH);
  distanceR=(durationR*0.0343)/2;
  Serial.println("distanceR:");
  Serial.println(distanceR);  
  delay(100);
  return(distanceR);
}
