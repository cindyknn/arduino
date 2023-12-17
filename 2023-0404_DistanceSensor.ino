const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance<10){
    digitalWrite(8,1);
    digitalWrite(7,0);
    digitalWrite(6,0);
    tone(11,800);
    delay(100);
    noTone(11);
  }else if (distance<30){
    digitalWrite(7,1);
    digitalWrite(8,0);
    digitalWrite(6,0);
    tone(11,400);
    delay(100);
    noTone(11);
  }else{
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,0);
    tone(11,100);
    delay(100);
    noTone(11);
  }

  delay(100);
}
