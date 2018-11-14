# Project Title

This repository contains the code for the UGV test setup. There will be a lead vehicle (target) and a follow vehicle (host). The target vehicle
is controlled by a Raspberry Pi implementing ESC and Servo control. The host vehicle is controlled by a nVidia Jetson TX2 and an Arduino Uno. The
host vehicle is integrated with multiple ultrasonic sensors and a single camera sensor. The ultrasonic sensors used are HC-SR04 and the camera is
the Stereolabs ZED camera.

## Getting Started

Use this code to run the target or host vehicle setup. To run this code, first clone the directory on to the device you wish to run it on:

'''
git clone https://github.com/CAV-YEAR1/UGV.git
'''

Then follow the instructions on the vehicle specific readme located in either the host or target vehicle sub-directories.

### Prerequisites
Python 2.7


## Running the tests
The program shows all the readings of PWM and ESC on the GUI. And also shows which buttns are pressed on the terminal.

Plug in right wires
Run the code
To calibrate, unplug and plug it back
Press buttons for the movement

## Deployment
Run the program with
python UGV_GUI.py



## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Sid**

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
