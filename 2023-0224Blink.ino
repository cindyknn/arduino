// the setup function runs once when you press reset or power the board
int a = 100;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(7, 1);  // turn the LED on (HIGH is the voltage level)
  delay(a);                      // wait for a second
  digitalWrite(7, 0);   // turn the LED off by making the voltage LOW
  delay(a);                      // wait for a second
 
  digitalWrite(8, 1);  // turn the LED on (HIGH is the voltage level)
  delay(a);                      // wait for a second
  digitalWrite(8, 0);   // turn the LED off by making the voltage LOW
  delay(a);
 
  digitalWrite(9, 1);  // turn the LED on (HIGH is the voltage level)
  delay(a);                      // wait for a second
  digitalWrite(9, 0);   // turn the LED off by making the voltage LOW
  delay(a);
}
