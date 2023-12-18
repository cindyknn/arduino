int points = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Number of points: ");
  Serial.println(points);
  points++;
  if(points>50){
    digitalWrite(13,HIGH);
    delay(5000);
    points = 0;
  }
  digitalWrite(13,LOW);
  delay(250);
}
