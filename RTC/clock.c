
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

// Initialize RTC and LCD
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  // ESP32 I2C pins
  Wire.begin(21, 22);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Initialize RTC
  if (!rtc.begin()) {
    lcd.clear();
    lcd.print("RTC NOT FOUND!");
    while (1);
  }

  // Set RTC time if it is not running
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  // Display date on first row
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  print2digits(now.day());
  lcd.print("/");
  print2digits(now.month());
  lcd.print("/");
  lcd.print(now.year());

  // Display time on second row
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  print2digits(now.hour());
  lcd.print(":");
  print2digits(now.minute());
  lcd.print(":");
  print2digits(now.second());

  delay(1000);
}

// Print leading zero for numbers < 10
void print2digits(int number) {
  if (number < 10) {
    lcd.print("0");
  }
  lcd.print(number);
}
