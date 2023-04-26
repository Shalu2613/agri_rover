#include <EEPROM.h>// EEPROM pre-installed library

#define RightF 6
#define RightB 7  //28,29,30,31
#define LeftF 8
#define LeftB 9

//int data;
//int trigpin1=A0;
//int echopin1=A1;
//int trigpin2=A2;
//int echopin2=A3;
//int trigpin3=A6;
//int echopin3=A7;
//long durationL,distanceL,durationC,distanceC,durationR,distanceR;
//
//int ultrasonic_sensor1();
//int ultrasonic_sensor2();
//int ultrasonic_sensor3();

/************Global Variables and Arrays***************/
 
unsigned long int data ; // stores the incoming hex value
byte seq = 0; //stores the current number of executed sequences
byte seq_Array[100];// array to store the movement sequence in terms of integers(1 for FWD, 2 for LEFT and so on..)

//counter for counting the number of times program pass through a movement function(fwd, lft etc.)
int fwd_Counter = -1;
int lft_Counter = -1;
int rgt_Counter = -1;
int bwd_Counter = -1;
int stp_Counter = -1;


//global "current time" variables for different movement functions(fwd, lft etc.)
unsigned long int current_Time0 = 0;// for FWD movement
unsigned long int current_Time1 = 0;// for LEFT movement
unsigned long int current_Time2 = 0;// for RIGHT movement
unsigned long int current_Time3 = 0;// for BWD movement
unsigned long int current_Time4 = 0;// for STOP

//total time spend by the pgm in executing the movement(fwd, lft etc.) for a particular movement counter
unsigned long int total_Fwd_Time[100];
unsigned long int total_Lft_Time[100];
unsigned long int total_Rgt_Time[100];
unsigned long int total_Bwd_Time[100];
unsigned long int total_Stp_Time[100];

#define RESET_PIN A0

void setup() {
  
   Serial1.begin(9600);
   Serial.begin(9600);
   pinMode(RESET_PIN, OUTPUT);
 
  //set all the pin as output for movement
  pinMode(RightF,OUTPUT);
  pinMode(RightB,OUTPUT);
  pinMode(LeftF,OUTPUT);
  pinMode(LeftB,OUTPUT);

  //set ultrasonic sensor pins
//  pinMode(trigpin1,OUTPUT);
//  pinMode(echopin1, INPUT);
//  pinMode(trigpin2,OUTPUT);
//  pinMode(echopin2, INPUT);
//  pinMode(trigpin3,OUTPUT);
//  pinMode(echopin3, INPUT);
}
void loop() {

  if(Serial1.available()){
  data = Serial1.read();
  Serial.println(data);
}
   /*  -------------------
----------ULTRASONIC SENSOR INTERFACE CONTROL-----------
 -------------------- */
//  ultrasonic_sensor1();
//  ultrasonic_sensor2();
//  ultrasonic_sensor3();
//  if(distanceL<=30 || distanceR<=30 || distanceC<=30)
//  {
//    Stop();
//    delay(3000);
//  }
//  else if(distanceL>distanceC && distanceL>distanceR)
//  {
//    Leftturn();
//    delay(1000);
//  }
//  else if(distanceR>distanceL && distanceR>distanceC)
//  {
//    Rightturn();
//    delay(1000);
//  }
//  else
//  {
//    //Forward();
//    delay(1000);
//  }

  delay(100);
  check_func(data);
  data=0;

}

void check_func(long int data)
{ 
/*  -------------------
----------MOTOR MOVENENT CONTROL-----------
 -------------------- */
 switch(data){
   case 'F':
    go_Forward();
    break;
   case 'L':
    go_Leftturn();
    break;
   case 'R':
    go_Rightturn();
    break;
   case 'B':
    go_Backward();
    break;
   case 'S':
    go_Stop();
    break;
   
   
  /*  -------------------
MOTOR CONTROL---------------------
 -------------------- */
    case 'REPEAT':
      go_In_Seq();
      delay(10);
      break;
    case  'DEL':
      del_From_Local_Mem();
      delay(10);
      break;
    case 'PERST' :
      write_To_Permt_Mem();
      delay(10);
      break;      
    case 'PLAYEPROM' :
      Read_Permt_Mem();
      delay(10);
      break;   
    case 'RESET':
     pinMode(RESET_PIN, OUTPUT);
      digitalWrite(RESET_PIN,HIGH);   
      break;
    default:
      data = 0;
     // break;
 }
}

void go_Forward(){
  Forward();
  
  current_Time0 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 2:
      // total time elaspsed since Left button is pressed including rest time 
      total_Lft_Time[lft_Counter + 1] = (current_Time0 - current_Time1);
      lft_Counter++;
      break;

    case 3:
      // total time elaspsed since Right button is pressed including rest time 
      total_Rgt_Time[rgt_Counter + 1] = (current_Time0 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time0 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time0 - current_Time4);
      stp_Counter++;
      break;
  }
  seq_Array[seq] = 1;
  seq++;  
}


void go_Leftturn(){
  Leftturn();

   current_Time1 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time1 - current_Time0);
      fwd_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time1 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time1 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time1 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 2;
  seq++;
}

void go_Rightturn(){
  Rightturn();
  current_Time2 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time2 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time2 - current_Time1);
      lft_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time2 - current_Time3);
      bwd_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time2 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 3;
  seq++;
  
}

void go_Backward(){
  Backward();
  
  current_Time3 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time3 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time3- current_Time1);
      lft_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time3 - current_Time2);
      rgt_Counter++;
      break;

    case 5:
      total_Stp_Time[stp_Counter + 1] = (current_Time3 - current_Time4);
      stp_Counter++;
      break;
  }

  seq_Array[seq] = 4;
  seq++; 
}

void go_Stop(){
  Stop();
   current_Time2 = millis();
  int i = seq_Array[(seq - 1)];
  switch (i) {
    case 1:
      total_Fwd_Time[fwd_Counter + 1] = (current_Time4 - current_Time0);
      fwd_Counter++;
      break;

    case 2:
      total_Lft_Time[lft_Counter + 1] = (current_Time4 - current_Time1);
      lft_Counter++;
      break;

    case 3:
      total_Rgt_Time[rgt_Counter + 1] = (current_Time4 - current_Time2);
      rgt_Counter++;
      break;

    case 4:
      total_Bwd_Time[bwd_Counter + 1] = (current_Time4 - current_Time3);
      bwd_Counter++;
      break;
  }

  seq_Array[seq] = 3;
  seq++;
  
}

void go_In_Seq(void){
  data = 0;
  for (int i = 0; i < (seq + 1); i++) {
    int data1 = 0;
    data1 = seq_Array[i];
    switch (data1) {
      case 1:
        static int j = 0;
        go_Forward_Seq(j);
        j++;
        break;
      case 2:
        static int k = 0;
        go_Leftturn_Seq(k);
        k++;
        break;
      case 3:
        static int l = 0;
        go_Rightturn_Seq(l);
        l++;
        break;
      case 4:
        static int m = 0;
        go_Backward_Seq(m);
        m++;
        break;
      case 5:
        static int n = 0;
        go_Stop_Seq(n);
        n++;
        break;
      default:
        j = 0; k = 0; l = 0; m = 0; n = 0;
    }
  }
}

void del_From_Local_Mem() {
  //set the movement counters to their default values
  fwd_Counter = -1;
  lft_Counter = -1;
  rgt_Counter = -1;
  bwd_Counter = - 1;
  stp_Counter = - 1;

  //set the total movement time to its default value
  for (int i = 0; i < 10; i++) {
    total_Fwd_Time[i] = 0;
    total_Lft_Time[i] = 0;
    total_Rgt_Time[i] = 0;
    total_Bwd_Time[i] = 0;
    total_Stp_Time[i] = 0;
  }

  // Reset the sequence array(stored movement instructions)
  for (int i = 0; i < 50; i++) {
    seq_Array[i] = 0;
  }

  seq = 0;
  
}

/**********************************************************************************************************
     This function copy the data from the arrays to the EEPROM(permanent memory)
************************************************************************************************************/

void write_To_Permt_Mem(){
  // total number of movement is stored in a random address i.e, 100
  EEPROM.write(100,seq);
    
  //writing the movement sequence
  for(int i=0; i<seq; i++){ 
  EEPROM.write(2*i,seq_Array[i]);
  }

  //storing the time bw two successive movements
  for(int i=1; i<seq+1; i++){           
  if(seq_Array[i-1]==1){
    static byte a=0;
    EEPROM.write(2*i-1,(total_Fwd_Time[a])/1000);// Note: One location can store maximum value of 255, hence the time is divided by 1000 here. And then multiplied by 1000 while retreiving the data from EEPROM location
    a++;
    }
  else if(seq_Array[i-1]==2){
    static byte b=0;
    EEPROM.write(2*i-1,(total_Lft_Time[b])/1000);
    b++;
    }
  else if(seq_Array[i-1]==3){
    static byte c=0;
    EEPROM.write(2*i-1,(total_Rgt_Time[c])/1000);
    c++;
    }
  else if(seq_Array[i-1]==4){
    static byte d=0;
    EEPROM.write(2*i-1,(total_Bwd_Time[d])/1000);  
    d++;
    }
  else if(seq_Array[i-1]==5){
    static byte e=0;
    EEPROM.write(2*i-1,(total_Stp_Time[e])/1000);  
    e++;
    }             
  }
}


/**********************************************************************************************************
     This function reads the stored sequence from the EEPROM(permanent memory)
************************************************************************************************************/

void Read_Permt_Mem(){
  // Read from permanent memory
   byte x = EEPROM.read(100);
   for(int i=0; i<x+1; i++){
    byte r = EEPROM.read(2*i);
    switch(r){
      case 1:
        Forward();
        break;
      case 2:
        Leftturn();
        break;
      case 3:
        Rightturn();
        break;
      case 4:
        Backward();
        break; 
      case 5:
        Stop();
        break;                          
      }
     delay((EEPROM.read(i+1))*1000);    // multiplied by thousand because the original time was divided by 1000 while storing in EEPROM.
    }
  }

/**********************************************************************************************************
     These function moves the car in a direction for the time specified/stored in the total_x_time array
************************************************************************************************************/
void go_Forward_Seq(int j) {
  //go in forward direction sequence
   Forward();
  delay(total_Fwd_Time[j]);
}

void go_Leftturn_Seq(int k) {
  //go in Left direction sequence
  Leftturn();
  delay(total_Lft_Time[k]);
}

void go_Rightturn_Seq(int l) {
  //go in right direction sequence
  Rightturn();
  delay(total_Rgt_Time[l]);
}

void go_Backward_Seq(int m) {
  //go in backward direction sequence
  Backward();
  delay(total_Bwd_Time[m]);
}

void go_Stop_Seq(int n) {
  //go in Stop sequence
  Stop();
  delay(total_Stp_Time[n]);
}

/*********************************************************************************************
          These movement instruction are repeated(required) several times in the code
**********************************************************************************************/

void Forward(){
  Serial.println("Going_Forward");
       digitalWrite(RightF, HIGH);
      digitalWrite(RightB, LOW);
      digitalWrite(LeftF, HIGH);
      digitalWrite(LeftB, LOW);
}
void Backward(){
  Serial.println("Going_Backward"); 
       digitalWrite(RightF, LOW);
      digitalWrite(RightB, HIGH);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, HIGH);
}
void Stop(){
      Serial.println("Stopping");
      digitalWrite(RightF, LOW);
      digitalWrite(RightB, LOW);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, LOW);
}
void Rightturn(){
      Serial.println("Going_Right");
      digitalWrite(RightF, LOW);
      digitalWrite(RightB,HIGH);
      digitalWrite(LeftF, HIGH);
      digitalWrite(LeftB, LOW);
}

void Leftturn(){
  Serial.println("Going_Left");
       digitalWrite(RightF, HIGH);
      digitalWrite(RightB,LOW);
      digitalWrite(LeftF, LOW);
      digitalWrite(LeftB, HIGH);
}
//int ultrasonic_sensor1()
//{
// digitalWrite(trigpin1,LOW);
//  delayMicroseconds(20);
//  digitalWrite(trigpin1,HIGH);
//  delayMicroseconds(20);
//  durationL=pulseIn(echopin1,HIGH);
//  //distance=duration/58.2;
//  distanceL=(durationL*0.0343)/2;
//  Serial.println("distanceL:");
//  Serial.println(distanceL);
//  delay(100);
//  return(distanceL);
//}
//int ultrasonic_sensor2()
//{
// digitalWrite(trigpin2,LOW);
//  delayMicroseconds(20);
//  digitalWrite(trigpin2,HIGH);
//  delayMicroseconds(20);
//  durationC=pulseIn(echopin2,HIGH);
//  distanceC=(durationC*0.0343)/2;
//  Serial.println("distanceC:");
//  Serial.println(distanceC);
//  delay(100);
//  return(distanceC);
//}
//int ultrasonic_sensor3()
//{
// digitalWrite(trigpin3,LOW);
//  delayMicroseconds(20);
//  digitalWrite(trigpin3,HIGH);
//  delayMicroseconds(20);
//  durationR=pulseIn(echopin3,HIGH);
//  distanceR=(durationR*0.0343)/2;
//  Serial.println("distanceR:");
//  Serial.println(distanceR);  
//  delay(100);
//  return(distanceR);
//}
