#define Right1  6
#define Right2  7
#define Left1   8
#define Left2   9

void setup() {
  pinMode(Right1,OUTPUT);
  pinMode(Right2,OUTPUT);
  pinMode(Left1,OUTPUT);
  pinMode(Left2,OUTPUT);
}
void loop()
{
  int forward,backward,stop,rightturn,leftturn;
  if(forward==1)
  {
    Forward();
  }
  if(backward==1)
  {
    Backward();
  }
  if(stop==1)
  {
    Stop();
  }
  if(rightturn==1)
  {
    Rightturn();
  }
  if(leftturn==1)
  {
    Leftturn();
  }
}

void Forward(){
       digitalWrite(Right1, HIGH);
      digitalWrite(Right2, LOW);
      digitalWrite(Left1, HIGH);
      digitalWrite(Left2, LOW);
}

void Backward(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2, HIGH);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, HIGH);
}

void Stop(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2, LOW);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, LOW);
}

void Rightturn(){
       digitalWrite(Right1, LOW);
      digitalWrite(Right2,HIGH);
      digitalWrite(Left1, HIGH);
      digitalWrite(Left2, LOW);
}
void Leftturn(){
       digitalWrite(Right1, HIGH);
      digitalWrite(Right2,LOW);
      digitalWrite(Left1, LOW);
      digitalWrite(Left2, HIGH);
}
         
