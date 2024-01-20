
/*
DigiDisk Clock Code
Microcontroller ATtiny402
Make sure to have the CH340 driver installed
*/

// include librairies
#include "PCA9685.h"

#include <Rtc_Pcf8563.h>
#include <Wire.h>

// init driver 
PCA9685 pwm;
// init rtc
Rtc_Pcf8563 rtc;
byte hour;
byte minute;
byte digit_disp1_hour;
byte digit_disp2_hour;
byte digit_disp1_minute;
byte digit_disp2_minute;
// init servo positions
const int p0 = 105;
const int p90 = 310;
const int p180 = 525;

// FUNCTION
void set_digit(byte digNum,byte dispNum){
  switch(digNum){
    case 0:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p180);
      pwm.setChannelPWM(3+4*(dispNum-1), p180);
      delay(1000);
      break;
    case 1:
      pwm.setChannelPWM(0+4*(dispNum-1), p180);
      pwm.setChannelPWM(1+4*(dispNum-1), p90);
      pwm.setChannelPWM(2+4*(dispNum-1), p180);
      pwm.setChannelPWM(3+4*(dispNum-1), p0);
      delay(1000);
      break;
    case 2:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p90);
      pwm.setChannelPWM(2+4*(dispNum-1), p0);
      pwm.setChannelPWM(3+4*(dispNum-1), p180);
      delay(1000);
      break;
    case 3:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p90);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p90);
      delay(1000);
      break;
    case 4:
      pwm.setChannelPWM(0+4*(dispNum-1), p180);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p0);
      delay(1000);
      break;
    case 5:
      pwm.setChannelPWM(0+4*(dispNum-1), p0);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p90);
      delay(1000);
      break;
    case 6:
      pwm.setChannelPWM(0+4*(dispNum-1), p0);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p180);
      delay(1000);
      break;
    case 7:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p90);
      pwm.setChannelPWM(2+4*(dispNum-1), p180);
      pwm.setChannelPWM(3+4*(dispNum-1), p0);
      delay(1000);
      break;
    case 8:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p180);
      delay(1000);
      break;
    case 9:
      pwm.setChannelPWM(0+4*(dispNum-1), p90);
      pwm.setChannelPWM(1+4*(dispNum-1), p0);
      pwm.setChannelPWM(2+4*(dispNum-1), p90);
      pwm.setChannelPWM(3+4*(dispNum-1), p90);
      delay(1000);
      break;
  }
}

void setup() {
  // setup Attiny402
  Wire.begin();
  // setup driver
  pwm.resetDevices();
  pwm.init();
  pwm.setPWMFrequency(50);
  // setup servo display
  set_digit(0,1);
  set_digit(0,2);
  set_digit(0,3);
  set_digit(0,4);
  delay(1000);
}

void loop() {
  // get time
  hour = rtc.getHour();
  minute = rtc.getMinute();
  // extract digits
  digit_disp1_minute = minute%10;
  digit_disp2_minute = floor(minute/10);
  digit_disp1_hour = hour%10;
  digit_disp2_hour = floor(hour/10);
  
  // show digits
  set_digit(digit_disp1_minute,1);
 
  // check time every second
  delay(1000);
}
