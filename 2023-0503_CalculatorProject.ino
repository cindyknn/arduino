#include <LedControl.h>
#include "binary.h"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LedControl lc=LedControl(10,12,11,0);
byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','?'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String eqt = "";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.init();
  lcd.clear();         
  lcd.backlight();

  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}


void loop() {
  // put your main code here, to run repeatedly:
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

    if (key=='?'){
      
      int sign = 0; 
      if(hasCharac("+")){
        sign = eqt.indexOf("+");
      } 
      if(hasCharac("-")){
        sign = eqt.indexOf("-");
      }
      if(hasCharac("*")){
        sign = eqt.indexOf("*");
      }

      int equal = eqt.indexOf("=");

      String numA = eqt.substring(0,sign);
      String numB = eqt.substring(sign+1, equal);
      String user = eqt.substring(equal+1, eqt.length()-1);
      int a = numA.toInt();
      int b = numB.toInt();
      int use = user.toInt();

      int ans = 0;
      if(hasCharac("+")){
        ans = a + b;
      }
      if(hasCharac("-")){
        ans = a - b;
      }
      if(hasCharac("*")){
        ans = a * b;
      }

      lcd.setCursor(0,1);
      lcd.print("Answer: ");
      lcd.print(ans);

      bool check;
      if(ans==use){
        check = true;
        lc.setRow(0,0,hf[0]);
        lc.setRow(0,1,hf[1]);
        lc.setRow(0,2,hf[2]);
        lc.setRow(0,3,hf[3]);
        lc.setRow(0,4,hf[4]);
        lc.setRow(0,5,hf[5]);
        lc.setRow(0,6,hf[6]);
        lc.setRow(0,7,hf[7]);
        delay(3000);
        lc.clearDisplay(0);
      }else{
        check = false;
        lc.setRow(0,0,sf[0]);
        lc.setRow(0,1,sf[1]);
        lc.setRow(0,2,sf[2]);
        lc.setRow(0,3,sf[3]);
        lc.setRow(0,4,sf[4]);
        lc.setRow(0,5,sf[5]);
        lc.setRow(0,6,sf[6]);
        lc.setRow(0,7,sf[7]);
        delay(3000);
        lc.clearDisplay(0);
      }

      Serial.println(ans);
      Serial.println(check);
      Serial.println("");
    
    }
  }
}

bool hasCharac(String charac){
  if(eqt.indexOf(charac)>=0){
    return true;
  }else{
    return false;
  }
}
