#define waterpump   3
#define lorasignal  6

int destination; 

void setup() {
  pinMode(waterpump ,OUTPUT); 
  pinMode(lorasignal,INPUT); 
}

void loop() { 
  destination= digitalRead(lorasignal);  
  if(destination== HIGH) // if water level is full then cut the relay 
  {
  digitalWrite(waterpump ,LOW); 
  }
  else
  {
  digitalWrite(waterpump ,HIGH); //high to continue providing signal and water supply
  }
  delay(400); 
}
