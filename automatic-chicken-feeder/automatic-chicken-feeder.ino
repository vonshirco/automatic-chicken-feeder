//Project Overview

//Definig Libraries
#include <DS3231.h> //For RTC Module
#include <Servo.h> //For Servor Motor
#include <LiquidCrystal.h> //For 16*2 LCD
#include <Keypad.h> //For 4*4 Matrix Keypad

//Defining the keymap for the 4*4 matrix keypad and assigning the Arduino pins for the Row and Columns of keypad.
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5};
byte colPins[COLS] = { 6, 7, 8, 9};

//Creating the keypad 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Assigning A4 and A5 Arduino pins to connect with SCL and SDA pins of DS3231.
DS3231 rtc(A4, A5);
Servo servo_test; //Initialize a servo object for the connected servo
LiquidCrystal lcd(A0, A1, A2, 11, 12, 13); //Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

//Declaring the t1 to t6, key, and array r[6], and the feed
int t1, t2, t3, t4, t5, t6;
boolean feed = true;
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

}
