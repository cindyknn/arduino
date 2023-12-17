#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String eqt = "";

void setup(){
  Serial.begin(9600);

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
}


void loop(){
  lcd.setCursor(0,0);
  
  char key = keypad.getKey();// Read the key

  // Print if key pressed
  if (key){
    eqt.concat(key);
    Serial.print(key);
    lcd.print(eqt);

    if (key=='C'){
      lcd.clear();
      eqt = "";
    }

    if (key=='='){
      
      int sign = 0; 
      if(eqt.indexOf("+")>=0){
        sign = eqt.indexOf("+");
      } 
      if(eqt.indexOf("-")>=0){
        sign = eqt.indexOf("-");
      }
      if(eqt.indexOf("*")>=0){
        sign = eqt.indexOf("*");
      }
      if(eqt.indexOf("/")>=0){
        sign = eqt.indexOf("/");
      }

      String numA = eqt.substring(0,sign);
      String numB = eqt.substring(sign+1, eqt.length()-1);
      float a = numA.toFloat();
      float b = numB.toFloat();

      /*
      Serial.println("sign:"+sign);
      Serial.println("eqt:"+eqt);
      Serial.println("numA:"+numA);
      Serial.println("numB:"+numB);
      */

      float ans = 0;
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
      Serial.print(ans);
      Serial.println("");

      eqt.concat(ans);
      Serial.println("eqt new:"+eqt);
      lcd.print(ans);
    
    }


  }
}