#include <iostream>
//#include "/home/nvidia/Documents/UGV/Follow_Vehicle/PWMCode/Jetson/PWM.hpp"
#include "PWM.hpp"
using namespace std;


bool isNumber(string s) {
		return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

int main(void)
{
	cout << "UGV Control\n";
	
	PWM pwm("/home/nvidia/Documents/UGV/Follow_Vehicle/PWMCode/Jetson/PWM-config.txt");
	pwm.setup();
	
    string input;
    
    while (true) {
		cin >> input;
		
		if (input == "Q" || input == "q") {
			break;
		}	
		else if (isNumber(input)) {
			//int speed = std::stoi(input);
		}
	}
	
	cout << "Goodbye\n";
}


