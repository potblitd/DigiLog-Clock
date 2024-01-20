/*
DigiDisk Clock Code
Microcontroller ATtiny402
Make sure to have the CH340 driver installed
*/

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
  rtc.setDate(20, 6, 1, 20, 24);
  //hr, min, sec
  rtc.setTime(11, 00, 0);

}

void loop() {
  // both format functions call the internal getTime() so that the 
  // formatted strings are at the current time/date.
  Serial.print(rtc.formatTime());
  Serial.print("\r\n");
  Serial.print(rtc.formatDate());
  Serial.print("\r\n");
  delay(1000);
}
