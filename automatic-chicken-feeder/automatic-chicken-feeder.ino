//Project Overview

//Definig Libraries
#include <DS3231.h> //For RTC Module
#include <Servo.h> //For Servor Motor
#include <LiquidCrystal.h> //For 16*2 LCD
#include <Keypad.h> //For 4*4 Matrix Keypad

const byte ROWS = 4; //Four rows
const byte COLS = 4; //Three columns

//Defining the keymap for the 4*4 matrix keypad and assigning the Arduino pins for the Row and Columns of keypad.
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5}; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins
byte colPins[COLS] = { 6, 7, 8, 9}; // Connect keypad COL0, COL1 and COL2 to these Arduino pins

//Creating the keypad 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Assigning A4 and A5 Arduino pins to connect with SCL and SDA pins of DS3231.
DS3231 rtc(A4, A5);
Servo servo_test; //Initialize a servo object for the connected servo
LiquidCrystal lcd(A0, A1, A2, 11, 12, 13); //Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

//Declaring the t1 to t6, key, and array r[6], and the feed
int angle = 0;
int potentio = A0; // initialize the A0analog pin for potentiometer
int t1, t2, t3, t4, t5, t6;
boolean feed = true; // condition for alarm
  char key;
  int r[6];

void setup() {
  // put your setup code here, to run once:
  servo_test.attach(10); //Attach the signal pin of servo to pin9 of arduino
  rtc.begin();
  lcd.begin(16,2);
  servo_test.write(55);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  int buttonPress;
  buttonPress = digitalRead(A3);
  
  if (buttonPress == 1)
    setFeedingTime();
    //Serial.println(buttonPress);

    lcd.print("Time: ");
    String t = "";
  
  t = rtc.getTimerStr();
  t1 = t.charAt(0)-48;
  t2 = t.charAt(1)-48;
  t3 = t.charAt(3)-48;
  t4 = t.charAt(4)-48;
  t5 = t.charAt(6)-48;
  t6 = t.charAt(7)-48;
  
  lcd.print(rtc.getTimerStr());
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  lcd.print(rtc.getDateStr());
  
  if (t1==r[0] && t2==r[1] && t3==r[2] && t4==r[3] && t5<1 && t6<3 && feed==true) {
    servo_test.write(100); //Rotate the servo to the specified angle
    delay(400);
    servor_test.write(55);
    feed=false;
  }
  
}

/*In this function code, After pressing the pushbutton we are able to
enter the pet feeding time, then we have to Press ‘D’ to save that time. When the saved time 
matches with real time then servo start rotating.*/

void setFeedinTime() {
  feed = true;
  int i=0;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Feeding Time");
  lcd.clear();
  lcd.print("HH:MM");
  lcd.setCursor(0,1);
  
  while(1){
    key = kpd.getKey();
    char j;
    
  if (key != NO_KEY){
    lcd.setCursor(j,1);
    lcd.print(key);
    r[i] = key-48;
    i++;
    j++;
    
    if (j==2){
      lcd.print(":");
      j++;
    }
    delay(500);
  }
  
 if (key == 'D'){
   key = 0;
   break;
 }
  
}




