### Idea
This updated version of the DigiLog clock called 'DigiDisk' is meant to improve the previous design but also change a few aspects to meet the following requirements :

+ Use cheap and easily available components
+ Simple setup with as little parts as possible
+ Modular to add more 2-digit assemblies
+ Use overlapping disks to avoid collision of sharp edges and accelerate digit transitions
+ Ditch the WiFi, embrace minimal MCUs
+ Fully assembled PCB (no modules)

### Design
Having overlapping disks with marked pointers instead of bar elements involved changing the axis position and pointers arrangement, and set the disk layer order to draw all 10 digits. With the code names, each digit can be defined by its disks positions. 

<p align="center">
  <img src="images/positions.svg" width="600" /> <br/><br/>
  <img src="images/digits.svg" width="600" />
</p>

## Implementation
### Components

+ ATtiny402 microcontroller
+ PCF8563 real-time clock
+ PCA9685 PWM driver
+ 4 x SG90 servo motor

### Schematics

### PCB

### Display


<p align="center">
  <img src="images/servo-arragement.svg" height="250" />
</p>

### Mechanical parts




### Assembly


### Cost



