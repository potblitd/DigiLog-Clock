// include librairies
#include <Rtc_Pcf8563.h>
#include <Wire.h>
// init rtc
Rtc_Pcf8563 rtc;

void setup() {
  // setup Attiny402
  Serial.begin(9600);
  Wire.begin();
  // setup rtc
  rtc.initClock();
  //day, weekday, month, century, year
  rtc.setDate(27, 6, 2, 20, 24);
  //hour, minute, second
  rtc.setTime(15, 56, 0);
}

void loop() {
}
