#include "moving_average.hpp"

/**
 * Create a new moving average object in your code. The number in the 
 * constructor is how many measurements this class will average over.
 * 
 * When the sensor gets a reading, add it with addMeasurement() and that 
 * method will return the current average;
 */

using namespace std;

Moving_Average::Moving_Average(unsigned int x) {
	q = new queue<unsigned int>;
	windowLength = x;
	totalSum = 0;
}

Moving_Average::~Moving_Average() {
	delete q;
}

double Moving_Average::addMeasurement(double measurement) {
	q->push(measurement);
	totalSum += measurement;
	
	if (q->size() > windowLength) {
		totalSum -= q->front();
		q->pop();
	}
	
	return (double)totalSum / (double) q->size();
}
