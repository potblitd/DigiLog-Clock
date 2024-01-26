// include librairies
#include "PCA9685.h"
#include <Rtc_Pcf8563.h>
#include <Wire.h>

// init driver 
PCA9685 pwm;
// init rtc and varibales
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

// digit function
void set_digit(byte digit, byte disp){
  switch(digit){
    case 0:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      delay(1000);
      break;
    case 1:
      pwm.setChannelPWM(0+4*(disp-1), p180);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      delay(1000);
      break;
    case 2:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p0);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      delay(1000);
      break;
    case 3:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      delay(1000);
      break;
    case 4:
      pwm.setChannelPWM(0+4*(disp-1), p180);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      delay(1000);
      break;
    case 5:
      pwm.setChannelPWM(0+4*(disp-1), p0);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      delay(1000);
      break;
    case 6:
      pwm.setChannelPWM(0+4*(disp-1), p0);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      delay(1000);
      break;
    case 7:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p90);
      pwm.setChannelPWM(2+4*(disp-1), p180);
      pwm.setChannelPWM(3+4*(disp-1), p0);
      delay(1000);
      break;
    case 8:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p180);
      delay(1000);
      break;
    case 9:
      pwm.setChannelPWM(0+4*(disp-1), p90);
      pwm.setChannelPWM(1+4*(disp-1), p0);
      pwm.setChannelPWM(2+4*(disp-1), p90);
      pwm.setChannelPWM(3+4*(disp-1), p90);
      delay(1000);
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
  minute = rtc.getMinute();
  // show digits
  //set_digit(minute%10,1);
  //set_digit(floor(minute/10),2);
  //set_digit(hour%10,3);
  //set_digit(floor(hour/10),4);

  for (int i = 0; i <= 9; i++) {
    set_digit(i,1);
    delay(1000);
  }
  
}
