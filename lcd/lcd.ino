#include <NewPing.h>

#include <LiquidCrystal.h>
#define ECHO_PIN 7 //Defining pins
#define TRIG_PIN 6
#define MAX_DIST 300
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); //Defining newping object (The HC-SR04)

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
   lcd.clear(); //Clear screen
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  unsigned int uS1 = sonar.ping_in(); //Ping in inches
  unsigned int uS2 = sonar.ping_cm(); // Ping in cm
  lcd.clear(); //Clearing screen
  lcd.setCursor(2,0); //Setting cursor
  lcd.print("Ping: "); //Printing text
  lcd.print(uS2);
  lcd.print(" cm");
  lcd.setCursor(2,1);
  lcd.print("Ping: ");
  lcd.print(uS1);
  lcd.print(" in");
  lcd.setCursor(1,0);
  delay(500); //Change this to the update time you want, I just used 1000 ms
}

