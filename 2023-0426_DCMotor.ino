int motorPin = 10;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<250; i++){
    analogWrite(motorPin, i);
    delay(2000);
  }
  for(int i = 250; i>=0; i--){
    analogWrite(motorPin, i);
    delay(2000);
  }
}
