//for testing the distance class
#include "distance.h"

using namespace std;

int main(int argc, char* argv[]) {
	gpioUnexport(gpio392);
	gpioUnexport(gpio394);
	Distance* sense = new Distance(gpio392, gpio394);
	for (int i = 0; i < 10000; i++) {
		double measure = sense->getMeasurement();
		if (measure > 0) {
			cout << "Measurement is: " << measure << endl; 
		}
	}
	return 0;
}

