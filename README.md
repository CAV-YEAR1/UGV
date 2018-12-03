# Project Title

This repository contains the code for the UGV test setup. There will be a lead vehicle (target) and a follow vehicle (host). The target vehicle
is controlled by a Raspberry Pi implementing ESC and Servo control. The host vehicle is controlled by a nVidia Jetson TX2 and an Arduino Uno. The
host vehicle is integrated with multiple ultrasonic sensors and a single camera sensor. The ultrasonic sensors used are HC-SR04 and the camera is
the Stereolabs ZED camera.

## Getting Started

Use this code to run the target or host vehicle setup. To run this code, first clone the directory on to the device you wish to run it on:


```
git clone https://github.com/CAV-YEAR1/UGV.git
```

Then follow the instructions on the vehicle specific readme located in either the host or target vehicle sub-directories.

### Prerequisites

#### Software
* Python 2.7
* Cmake 3.5+
* Linux

#### Hardware
* Raspberry Pi
* nVidia Jetson TX2
* Arduino Uno
* Logic Level Converter
* HC-SR04 Ultrasonic Sensors
* Stereolabs ZED Camera

## Contributing

Modify code in a separate branch. All changes can only be merged to master after peer review and testing. Once complete submit pull request
to merge with master. For more details on which specific files may be changed check individual sub-directories. Please do not modify .gitignore
files. Build directories and executable files should not be committed.

## Version

0.0.1

## Authors

* **Sid**
* **Tom**
* **Graham**

## License

This code is for the cool kids only.
