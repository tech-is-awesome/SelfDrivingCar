#include <Keypad.h>
#include <HCSR04.h>
#include <LiquidCrystal.h>

#define rs 0
#define en 1
#define d0 2
#define d1 3
#define d2 4
#define d3 5
#define d4 6
#define d5 7
#define d6 8
#define d7 9

const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte rowPins[rows] = {10, 11, 12, 13}; //connect to the row pinouts of the keypad
byte colPins[cols] = {14, 15, 16, 17}; //connect to the column pinouts of the keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);
float currentSpeed;
int maxSpeed = 100;
String password = "00000000"
String userid = "A111D";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Please enter your userid\n");
  String input = kpd.read();
  delay(5000);
  if (input == userid){
    lcd.clear();
    lcd.print("Enter Password:");
    input = kpd.read();
    delay(5000);
    if (input == password){
      lcd.clear();
      lcd.print("Login Succsessfull\nStarting System");
      // Startup code for Motor, Servo, Accelerometer, RFID and more 
      pinMode(18, OUTPUT); // Motor pin 1
      pinMode(19, OUTPUT); // Motor Pin 2     
      
    }
    else{
      lcd.clear();
      lcd.print("Login Failed")
      while(true);
    }
  }
  else{
    lcd.clear();
    lcd.print("Login Failed")
    while(true);
  }
}


void setspeed(String speed){

}

void mvfwd(String )



void loop() {
  lcg.clear();
  lcd.print("Enter verb ID");
  input = kpd.read();
  delay(5000);
  if (input = "000"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = kpd.read();
    delay(5000)
    mvfwd(input);
  }
  else if (input == "001"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = kpd.read();
    delay(5000);
    mvbkwd(input);
  }
  else if (input == "002"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = kpd.read();
    mvlft(input);
  }
  else if (input == "003"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = kpd.read;
    delay(5000);
    mvrght(input);
  }
  else if (input == "004"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID")
    input = kpd.read();
    delay(5000);
    setspeed(input);
  }
}
