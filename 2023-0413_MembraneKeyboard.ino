#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {' ','0','=','/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String eqt = "";

void setup(){
  Serial.begin(9600);

}
  
void loop(){
  char key = keypad.getKey();// Read the key

  // Print if key pressed
  if (key){
    eqt.concat(key);
    Serial.print(key);

    if (key=='='){
      
      int space = eqt.indexOf(" ");
      String numA = eqt.substring(0,space);
      String numB = eqt.substring(space+3, eqt.length()-2);

      int a = numA.toInt();
      int b = numB.toInt();

      //Serial.print(space);
      //Serial.print(eqt);
      //Serial.print(numA);
      //Serial.print(numB);

      int ans = 0;
      if(eqt.indexOf("+")>=0){
        ans = a + b;
      }
      if(eqt.indexOf("-")>=0){
        ans = a - b;
      }
      if(eqt.indexOf("*")>=0){
        ans = a * b;
      }
      if(eqt.indexOf("/")>=0){
        ans = a / b;
      }
      Serial.print(" ");
      Serial.print(ans);
      Serial.println("");
      eqt = "";
    }
  }
}