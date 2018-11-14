/**
 * This is the header file for the moving average class
 */

#include <queue>

using namespace std;

class Moving_Average {
	public:
		Moving_Average(unsigned int x);
		~Moving_Average();
		double addMeasurement(unsigned int measurement);
		
	private:
		queue<unsigned int> *q;
		unsigned int totalSum;
		unsigned int windowLength;
};
