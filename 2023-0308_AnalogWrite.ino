void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  for(int i = 1; i<20; i++){
    digitalWrite(11,1);
    delay(55);
    digitalWrite(11,0);
    delay(55);
  }
  analogWrite(11,255);
  delay(1000);
  analogWrite(11,150);
  delay(1000);
  analogWrite(11,50);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:


}
