### Idea
This updated version of the DigiLog clock called 'DigiDisk' is meant to improve the previous design but also change a few aspects to meet the following requirements :

+ Use cheap and easily available components
+ Simple setup with as little parts as possible
+ Modular to add more 2-digit assemblies
+ Use overlapping disks to avoid collision of sharp edges and accelerate digit transitions
+ Ditch the WiFi, embrace minimal MCUs
+ Fully assembled PCB (no modules)

### Design
Having overlapping disks with marked pointers instead of bar elements involved changing the axis position and pointers arrangement, and set the disk layer order to draw all 10 digits. With the code names, each digit can be defined by its disks positions. Since the rotating elements are overlapping each other, there is no need to plan the sequence diagram as done for the first version. 

<p align="center">
  <img src="images/positions.svg" width="500" /> <br/><br/>
  <img align="middle" src="images/digits.svg" width="600" />
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <img align="middle" src="images/digidisk-animation.gif" width="200" />
</p>

## Implementation
### Components
The servo motors are driver by the PCA9685 PWM controller used previously and the time is fetched from the common PCF8563 real-time clock. As the microcontroller of the system only needs to write and read with the two other chips through I2C, the ATtiny402 is very suitable (and my fav). 

+ ATtiny402 microcontroller
+ PCF8563 real-time clock
+ PCA9685 PWM driver
+ 4 x SG90 servo motor

### Schematics
The system is powered through a USB-C port (min 2W) and its status is indicated by a blue LED. The RTC chip does not have an auxilliary power source so the time must be re-set in case the USB cable is unplugged. To potentially attach another 2 or more digits, the power rail, ground and I2C signals are broken out through a 2.54mm header so that the additional PCBs only need the PWM controller circuit. The communication with multiple PCA9685 chips is then feasible by setting different adresses through the DIP switch. Finally, no USB programming has been implemented for this design due to space constraint. To flash the ATtiny MCU, an IC test clip is needed in combination with a general TTL serial adapter.

<p align="center">
  <img src="images/schematics.png" height="300" />
</p>

### PCB

### Display


<p align="center">
  <img src="images/servo-arragement.svg" height="250" />
</p>

### Mechanical parts




### Assembly

### Code
As mentioned before, the design does not feature an internal programmer and thus, a modified TTL serial adapter must be connected to the ATtiny402 to programm it with the [python UPDI driver](https://github.com/mraardvark/pyupdi).


### Cost



