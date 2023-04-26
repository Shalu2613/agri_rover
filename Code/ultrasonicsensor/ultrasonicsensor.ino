int trigpin=3;
int echopin=2;
long duration,distance,dist;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.2;
  //dist=(duration*0.0343)/2;
  Serial.println("distance:");
  Serial.println(distance);
  //Serial.println("dist:");
  //Serial.println(dist);
  delay(100);

}
