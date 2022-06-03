#include <LiquidCrystal.h>
#define BUTTON_ON 1
#define BUTTON_OFF 0
#define MORSE_TIME_UNIT 100 // A single morse time unit         

const int pushButton = 6;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int previousButtonState;
long currentStateBegan = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pushButton, INPUT);
  previousButtonState = digitalRead(pushButton);
}

void loop() {
  int buttonState = digitalRead(pushButton);

  if (previousButtonState != buttonState) {
    lcd.clear();
    if (buttonState == BUTTON_ON) {
      writeTop("Counting!");
    } else {
      writeTop("Milliseconds:");
      char count[40];
      sprintf(count,"%lu", currentStateDuration());
      writeBottom(count);
    }
    
    currentStateBegan = millis();
    previousButtonState = buttonState;
  }
}

long currentStateDuration() {
  return millis() - currentStateBegan;
}

void writeTop(String message) {
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void writeBottom(String message) {
  lcd.setCursor(0, 1);
  lcd.print(message);
}