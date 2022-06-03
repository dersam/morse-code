#include <LiquidCrystal.h>
#define BUTTON_ON 1
#define BUTTON_OFF 0

const int pushButton = 6;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const String onState = "sam";
const String offState = "kirk";
int previousButtonState;
long onStateBegan = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pushButton, INPUT);
  previousButtonState = digitalRead(pushButton);
}

void loop() {
  int buttonState = digitalRead(pushButton);

  if (previousButtonState != buttonState) {
    lcd.clear();
    buttonState == BUTTON_ON ? writeTop(onState) : writeTop(offState);
    previousButtonState = buttonState;
  }
}

void writeTop(String message) {
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void writeBottom(String message) {
  lcd.setCursor(0, 1);
  lcd.print(message);
}