
/*
DigiLog Clock Code
Microcontroller Wemos D1 mini (clone)
Make sure to have the CH340 driver installed
DS3231 library : https://github.com/NorthernWidget/DS3231/tree/master

*/

// include librairies
#include <DS3231.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
// init RTC variables
DS3231 rtc;
bool century = false;
bool h12Flag;
bool pmFlag;
byte hour;
byte disp1;
byte disp2;
// init driver variables
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
const int p0 = 105;
const int p90 = 320;
const int p180 = 525;

// FUNCTION
void safe_init(byte dispNum){
  // go to 0  all pointers seperately
  pwm.setPWM(2+4*(dispNum-1),0,p180);
  delay(500);
  pwm.setPWM(3+4*(dispNum-1),0,p0);
  delay(500);
  pwm.setPWM(1+4*(dispNum-1),0,p0);
  delay(500);
  pwm.setPWM(4+4*(dispNum-1),0,p90);
}

void safe_rest(byte dispNum){
  // go to 0  all pointers seperately
  pwm.setPWM(2+4*(dispNum-1),0,p90);
  delay(500);
  pwm.setPWM(3+4*(dispNum-1),0,p90);
  delay(500);
  pwm.setPWM(1+4*(dispNum-1),0,p90);
  delay(500);
  pwm.setPWM(4+4*(dispNum-1),0,p90);
}

void to_zero(byte digNum,byte dispNum){
  switch(digNum){
    case 2:
      // 2 -> 0
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(250);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      delay(750);
      break;
    case 3:
      // 3 -> 0
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      delay(250);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(750);
      break;
    case 5:
      // 5 -> 0
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      delay(250);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      delay(250);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(500);
      break;
  }
}

void show(byte digNum,byte dispNum){
  switch(digNum){
    case 0:
      // 9 -> 0
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(1000);
      break;
    case 1:
      // 0 -> 1
      pwm.setPWM(1+4*(dispNum-1),0,p180);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      pwm.setPWM(4+4*(dispNum-1),0,p0);
      delay(1000);
      break;
    case 2:
      // 1 -> 2
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      pwm.setPWM(4+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 3:
      // 2 -> 3
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(1000);
      break;
    case 4:
      // 3 ->4
      pwm.setPWM(1+4*(dispNum-1),0,p180);
      pwm.setPWM(2+4*(dispNum-1),0,p0);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      pwm.setPWM(4+4*(dispNum-1),0,p0);
      delay(1000);
      break;
    case 5:
      // 4 -> 5
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      pwm.setPWM(2+4*(dispNum-1),0,p0);
      pwm.setPWM(4+4*(dispNum-1),0,p180);
      delay(500);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      delay(500);
      break;
    case 6:
      // 5 -> 6
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(3+4*(dispNum-1),0,p180);
      pwm.setPWM(4+4*(dispNum-1),0,p180);
      delay(1000);
      break;
    case 7:
      // 6 -> 7
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p0);
      delay(250);
      pwm.setPWM(4+4*(dispNum-1),0,p0);
      delay(250);
      pwm.setPWM(1+4*(dispNum-1),0,p90);
      delay(500);
      break;
    case 8:
      // 7 -> 8
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p180);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(250);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      delay(750);
      break;
    case 9:
      // 8 -> 9
      pwm.setPWM(1+4*(dispNum-1),0,p0);
      pwm.setPWM(2+4*(dispNum-1),0,p90);
      pwm.setPWM(3+4*(dispNum-1),0,p90);
      pwm.setPWM(4+4*(dispNum-1),0,p90);
      delay(1000);
      break;
  }
}

void setup() {
  // setup d1 mini
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  // setup driver
  pwm.begin();
  pwm.setPWMFreq(50);
  // setup servo display
  safe_init(1);
  safe_init(2);
  delay(1000);
}

void loop() {
  // get time
  hour = rtc.getHour(h12Flag, pmFlag);
  Serial.print(hour); 
  Serial.print(" - ");
  // extract digits
  disp1 = hour%10;
  disp2 = floor(hour/10);
  Serial.print(disp2);
  Serial.print('-');
  Serial.print(disp1); 
  Serial.println();
  
  // show digits  
  if(hour == 0){
    to_zero(2,2);
    to_zero(3,1);
  } else {
    show(disp2,2);
    show(disp1,1);
  }
 
  // toggle LED
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(10*1000);
}
