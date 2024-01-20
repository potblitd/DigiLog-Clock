### Idea
This updated version of the DigiLog clock called 'DigiDisk' is meant to improve the previous design but also change a few aspects to meet the following requirements :

+ Use cheap and easily available components
+ Simple setup with as little parts as possible
+ Modular to add more 2-digit assemblies
+ Use overlapping disks to avoid collision of sharp edges and accelerate digit transitions
+ Ditch the WiFi, embrace minimal MCUs
+ Fully assembled PCB (no modules)

### Design
Having overlapping disks with marked pointers instead of bar elements involved changing the 4 axes positions and pointers arrangement, and set the disk layer order to draw all 10 digits. With the code names, each digit can be defined by its disks positions. Since the rotating elements are overlapping each other, there is no need to plan the sequence diagram as done for the first version. 

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
+ 4 x MG90S servo motor

### Schematics
The system is powered through a USB-C port (min 2W) and its status is indicated by a blue LED. The RTC chip does not have an auxilliary power source so the time must be re-set in case the USB cable is unplugged. To potentially attach another 2 or more digits, the power rail, ground and I2C signals are broken out through a 2.54mm header so that the additional PCBs only need the PWM controller circuit. The communication with multiple PCA9685 chips is then feasible by setting different adresses through the DIP switch. Here, no USB programming has been integrated for this design due to space constraint. To flash the ATtiny MCU, an IC test clip is needed in combination with a general TTL serial adapter. The servo motors have been upgraded to the MG90S as their motion is more smooth and precise without a dramatic price increase.

<p align="center">
  <img src="images/schematics.png" width="800" />
</p>

### Display
With the axes position slightly changed from the previous version, the servo also needed to be adjusted but the idea remains the same. In this configuration, two digits must be separated by at least 20mm.

<p align="center">
  <img src="images/servo-arragement.svg" height="250" />
</p>

### PCB
The board not only integrates all the electronic components, but also includes the mounting holes for the servo motors. In this way, no additonal mounting plates must be manufactured. However, this layout greatly limits the space for more PWM signal breakouts or components for USB programming. 

<p align="center">
  <img src="images/pcb-front" height="250" />
  <img src="images/pcb-back" height="250" />
  <img src="images/pcb-mounted" height="250" />
  <img src="images/pcb-assembly" height="250" />
</p>

### Mechanical parts
Since the PCB acts as the mounting plate, only the rotating disks and the front plate must be manufactured. The simplest way here is to use paper, as its thickness is negligeable, elimitating the need to install spacers for the different disk layers heights. 


### Assembly

<p align="center">
  <img src="images/assembly-front.png" height="250" />
  <img src="images/assembly-back.png" height="250" />
</p>

### Code
As mentioned before, the design does not feature an internal programmer and thus, a modified TTL serial adapter must be connected to the ATtiny402 to programm it with the [python UPDI driver](https://github.com/mraardvark/pyupdi).


### Cost
The PCB with all the components costed about 28 RMB (3.93 USD) and with the servo motors it is 66.28 RMB (9.30 USD). Since the disks and front plate were made out of paper, the final price with the mounting screws and nuts is around 70 RMB (9.82 USD).



