
/*
DigiDisk Clock Code
Microcontroller ATtiny402
Make sure to have the CH340 driver installed
*/

// include librairies
#include <Adafruit_PWMServoDriver.h>
#include <Rtc_Pcf8563.h>
#include <Wire.h>

// init driver 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// init servo positions
const int p0 = 105;
const int p90 = 320;
const int p180 = 525;
// init rtc
Rtc_Pcf8563 rtc;

// FUNCTION
void set_digit(byte digNum,byte dispNum){
  switch(digNum){
    case 0:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 1:
      pwm.setPWM(0+4*(dispNum-1),0,p180);
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      delay(1000);
      break;
    case 2:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p0);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 3:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      delay(1000);
      break;
    case 4:
      pwm.setPWM(0+4*(dispNum-1),0,p180);
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      delay(1000);
      break;
    case 5:
      pwm.setPWM(0+4*(dispNum-1),0,p0);
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      delay(1000);
      break;
    case 6:
      pwm.setPWM(0+4*(dispNum-1),0,p0);
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 7:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      delay(1000);
      break;
    case 8:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 9:
      pwm.setPWM(0+4*(dispNum-1),0,p90);
      pwm.setPWM(1+4*(dispNum-1),0,p00);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      delay(1000);
      break;
  }
}

void setup() {
  // setup Attiny402
  Serial.begin(9600);
  Wire.begin();
  // setup driver
  pwm.begin();
  pwm.setPWMFreq(50);
  // setup servo display
  set_digit(0,1);
  set_digit(0,2);
  delay(1000);
}

void loop() {
  // get time
  hour = rtc.getHour();
  // extract digits
  digit_disp1 = hour%10;
  digit_disp2 = floor(hour/10);
  Serial.print(disp2);
  Serial.print('-');
  Serial.print(disp1); 
  Serial.println();
  
  // show digits  
  set_digit(digit_disp1,1);
  set_digit(digit_disp2,2);
 
  // check time every 10 sseconds
  delay(10*1000);
}
