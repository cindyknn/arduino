int n = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 10; i < 13; i++) {
    digitalWrite(i, HIGH);
    delay(n);
    digitalWrite(i, LOW);
    delay(n);
  }
}
