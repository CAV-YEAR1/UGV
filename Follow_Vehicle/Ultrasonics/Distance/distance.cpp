//This holds code for getting current distance to objects
//arranged in a c++ class for ease of use
#include "distance.hpp"

using namespace std;

//for correctly setting terminal mode
int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

//constructor for this class
Distance::Distance(jetsonGPIO trig, jetsonGPIO echo) {
	//configure the sensor
	sensor = new HCSR04(trig, echo);
	sensor->exportGPIO();
	sensor->setDirection();
	//average over 5 measurements
	avg = new Moving_Average(10);
}

//destructor for this class
Distance::~Distance() {
	sensor->unexportGPIO();
}

//method for gettng the distance in centimeters
//will return -1.0 for error 
//will return -2.0 if no echo recieved
double Distance::getMeasurement() {
	if (getkey() != 27) {
		unsigned int duration = sensor->pingMedian(5);
		cout << "Duration: " << duration << endl;
		if (duration != NO_ECHO) {
			//return measurement
			return avg->addMeasurement(duration / 58.0);
		}
		return -2.0;
		//sleep 10 millisecond to avoid interference
		usleep(10000);
	}
	return -1.0;
}




