int relay = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(relay, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(relay, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(relay, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}
