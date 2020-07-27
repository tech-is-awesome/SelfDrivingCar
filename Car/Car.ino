#include <HCSR04.h>
#include <SPI.h>
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
#define motor1 18
#define motor2 19


LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);
float currentSpeed;
int maxSpeed = 100;
String password = "00000000";
String userid = "A111D";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Please enter your userid\n");
  String input = Serial.read();
  
  if (input == userid){
    lcd.clear();
    lcd.print("Enter Password:");
    input = Serial.read();
    
    if (input == password){
      lcd.clear();
      lcd.print("Login Succsessfull\nStarting System");
      // Startup code for Motor, Servo, Accelerometer, RFID and more 
      pinMode(motor1, OUTPUT); // Motor pin 1
      pinMode(motor2, OUTPUT); // Motor Pin 2     
      
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

void mvfwd(String length){
  int len = int(length);
  int lenmv = 0;
  //move forward x length
  while(len != lenmv){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
}

void mvbkwd(String length){
  int len = int(length);
  int lenmv = 0;
  //move forward x length
  while(len != lenmv){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
  }
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
}


void loop() {
  lcg.clear();
  lcd.print("Enter verb ID");
  input = Serial.read();
  
  if (input = "000"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = Serial.read();
    mvfwd(input);
  }
  else if (input == "001"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = Serial.read();
    mvbkwd(input);
  }
  else if (input == "002"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = Serial.read();
    mvlft(input);
  }
  else if (input == "003"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID");
    input = Serial.Read;
    mvrght(input);
  }
  else if (input == "004"){
    lcd.clear();
    lcd.print("verb received\nenter noun ID")
    input = Serial.read();
    setspeed(input);
  }
}
