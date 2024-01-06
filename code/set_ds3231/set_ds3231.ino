
/*
DigiLog Clock Code
Microcontroller Wemos D1 mini (clone)
Make sure to have the CH340 driver installed
*/

// include librairies
#include <DS3231.h>
#include <Wire.h>

DS3231 rtc;
bool century = false;
bool h12Flag;
bool pmFlag;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  rtc.setClockMode(false);  // set to 24h
  // write current date
  rtc.setYear(24);
  rtc.setMonth(1);
  rtc.setDate(6);
  // write current time
  rtc.setHour(21);
  rtc.setMinute(47);
  rtc.setSecond(30);
  // turnoff led - done
  digitalWrite(LED_BUILTIN, LOW); 

}

void loop() {


}
