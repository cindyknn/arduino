void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 2; i<12; i++){
    pinMode(i,OUTPUT);
  }

  for(int i = 2; i<12; i++){
    digitalWrite(i,1);
  }
  delay(200);
  for(int i = 2; i<12; i++){
    digitalWrite(i,0);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  int y = analogRead(A1);
  int sw = analogRead(A2);
  Serial.print("x = ");
  Serial.println(x);
  Serial.print("y = ");
  Serial.println(y);
  Serial.print("sw = ");
  Serial.println(sw);
  delay(100);

  if(x<301 && y<301){
    for(int i = 2; i<11; i++){
      if(i==8){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if(x>301 && x<751 && y<301){
    for(int i = 2; i<11; i++){
      if(i==9){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x>751 && y<301){
    for(int i = 2; i<11; i++){
      if(i==10){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x<301 && y>301 && y<751){
    for(int i = 2; i<11; i++){
      if(i==5){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x>301 && x<751 && y>301 && y<751){
    for(int i = 2; i<11; i++){
      if(i==6){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x>751 && y>301 && y<751){
    for(int i = 2; i<11; i++){
      if(i==7){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x<301 && y>751){
    for(int i = 2; i<11; i++){
      if(i==2){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x>301 && x<751 && y>751){
    for(int i = 2; i<11; i++){
      if(i==3){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }if (x>751 && y>751){
    for(int i = 2; i<11; i++){
      if(i==4){
        digitalWrite(i,1);
      }else{
        digitalWrite(i,0);
      }
    }
  }
  if (sw<100){
    digitalWrite(11,1);
  } else{
    digitalWrite(11,0);
  }
}

