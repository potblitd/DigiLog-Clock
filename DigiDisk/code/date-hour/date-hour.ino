// include librairies
#include "PCA9685.h"
#include <Rtc_Pcf8563.h>
#include <Wire.h>

// init driver 
PCA9685 pwm;
// init rtc and varibales
Rtc_Pcf8563 rtc;
byte hour;
byte day;
// init servo positions
const int p0 = 105;
const int p90 = 310;
const int p180 = 525;

// digit function
void set_digit(byte digit, byte disp){
  switch(digit){
    case 0:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      break;
    case 1:
      pwm.setChannelPWM(0+4*(disp-1), p180);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      break;
    case 2:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p0);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      break;
    case 3:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      break;
    case 4:
      pwm.setChannelPWM(0+4*(disp-1), p180);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      break;
    case 5:
      pwm.setChannelPWM(0+4*(disp-1), p0);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      break;
    case 6:
      pwm.setChannelPWM(0+4*(disp-1), p0);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      break;
    case 7:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      break;
    case 8:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      break;
    case 9:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      break;
  }
}

void setup() {
  // setup i2c
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
  day = rtc.getDay();
  // show digits
  set_digit(hour%10,1);
  set_digit(floor(hour/10),2);
  set_digit(day%10,3);
  set_digit(floor(day/10),4);

  delay(1000);
  
}
