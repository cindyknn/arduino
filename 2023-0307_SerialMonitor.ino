int time = 500;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  time = analogRead(A0);
  int Delay = 100 + time;
  delay(Delay);
  Serial.println("time = ");
  Serial.println(time);
  delay(2000);
}
