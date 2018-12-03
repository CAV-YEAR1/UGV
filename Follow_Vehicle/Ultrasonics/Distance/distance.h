//header file for distance class
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include <jetsonGPIO.h>
#include <hcsr04.h>
#include "moving_average.h"

using namespace std;

class Distance {
    public:
	Distance(jetsonGPIO trig, jetsonGPIO echo);
	~Distance();
	double getMeasurement();

    private:
	HCSR04* sensor;
	Moving_Average* avg;
};


