//Define all the input pins of the motor driver
#define RightF 6
#define RightB 7 
#define LeftF 8
#define LeftB 9


void setup() {
 //Set baud rate for serial communication
Serial.begin(9600);

//Set all the pin as OUTPUT
  pinMode(RightF,OUTPUT);
  pinMode(RightB,OUTPUT);
  pinMode(LeftF,OUTPUT);
  pinMode(LeftB,OUTPUT);
}
 
void loop() {
  //FORWARD
  Serial.println("Going_Forward");
  digitalWrite(RightF, HIGH);
  digitalWrite(RightB, LOW);
  digitalWrite(LeftF, HIGH);
  digitalWrite(LeftB, LOW);
   delay(3000);
   
  //BACKWARD
    Serial.println("Going_Backward"); 
    digitalWrite(RightF, LOW);
    digitalWrite(RightB, HIGH);
    digitalWrite(LeftF, LOW);
    digitalWrite(LeftB, HIGH);
    delay(3000);
    
  //LEFT TURN
    Serial.println("Going_Left");
    digitalWrite(RightF, HIGH);
    digitalWrite(RightB,LOW);
    digitalWrite(LeftF, LOW);
    digitalWrite(LeftB, HIGH);
    delay(3000);
    
  //RIGHT TURN
    Serial.println("Going_Right");
    digitalWrite(RightF, LOW);
    digitalWrite(RightB,HIGH);
    digitalWrite(LeftF, HIGH);
    digitalWrite(LeftB, LOW);
    delay(3000);
   
 //STOP
   Serial.println("Stopping");
   digitalWrite(RightF, LOW);
   digitalWrite(RightB, LOW);
   digitalWrite(LeftF, LOW);
   digitalWrite(LeftB, LOW);
   delay(3000);
}
