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
  rtc.setDate(24, 3, 1, 20, 24);
  //hr, min, sec
  rtc.setTime(9, 9, 0);

}

void loop() {
  Serial.print(rtc.formatTime());
  Serial.print("\r\n");
  Serial.print(rtc.formatDate());
  Serial.print("\r\n");
  delay(1000);
}
