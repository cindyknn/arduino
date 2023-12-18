void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i<13; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {  // put your main code here, to run repeatedly:
  
  //0
  for(int i = 6; i<13; i++){
    if(i==12){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
      digitalWrite(i,LOW);
  }
  delay(time());
  
  //1
  for(int i = 6; i<13; i++){
    if(i==12 or i==11 or i==10 or i==7 or i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==2){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //2
  for(int i = 6; i<13; i++){
    if(i==11 or i==8){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==3){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //3
  for(int i = 6; i<13; i++){
    if(i==11 or i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==2 or i==3){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //4
  for(int i = 6; i<13; i++){
    if(i==10 or i==7 or i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==4){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //5
  for(int i = 6; i<13; i++){
    if(i==9 or i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==2 or i==4){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //6
  for(int i = 6; i<13; i++){
    if(i==9){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==3 or i==4){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //7
  for(int i = 6; i<13; i++){
    if(i==12 or i==11 or i==7 or i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==2 or i==3 or i==4){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //8
  for(int i = 6; i<13; i++){
    digitalWrite(i,HIGH);
  }
  for(int i = 2; i<6; i++){
    if(i==5){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

  //9
  for(int i = 6; i<13; i++){
    if(i==6){
      digitalWrite(i,LOW);
    }else{
      digitalWrite(i,HIGH);
    }
  }
  for(int i = 2; i<6; i++){
    if(i==2 or i==5){
      digitalWrite(i,HIGH);
    }else{
      digitalWrite(i,LOW);
    }
  }
  delay(time());

}

int time(){
  int timev = analogRead(A0);
  int Delay = timev * 10;
  Serial.println(Delay);
  return(Delay);
}
