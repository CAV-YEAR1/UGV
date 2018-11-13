# Project Title

UGV for Testing puposes based on Jetson Car model - FRONT

## Getting Started

This project is developed for tesing purposes. We have a rapberry pi with rasbian installed. Download Python 2.7 in not aleady installed.
The ultrasonics folder holds the implementation for reading ultrasonic sensor data

### Prerequisites
Python 2.7
gcc 5.4.0

## Running the tests
The program shows all the readings of PWM and ESC on the GUI. And also shows which buttns are pressed on the terminal.

Plug in right wires
Run the code
To calibrate, unplug and plug it back
Press buttons for the movement

The ultrasonics folder shows readings of two ultrasonic sensors operating from the same trigger

configure the sensors with the jetson as shown in the wiring diagram **FIXME - wiring diagram need to be updated for 2 Sensors
Run make file in the example folder to construct the executable
run executable as root user

## Deployment
Run the program with
python UGV_GUI.py

For ultrasonics:
See the [usablePorts.txt] file for info on which GPIO ports can be used and info on each port being used function
This file also contains information on how the original code from JetsonHacks was modified to support 2 ultrasonics

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Sid** 
* **Tom**
* **Graham**
See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


