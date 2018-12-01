#include <iostream>
#include <string>
#include "../../PWMCode/Jetson/PWM.hpp"
using namespace std;


bool isNumber(string s) {
		return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

int main(void)
{
	cout << "UGV Control\n";
	
	PWM pwm("../PWMCode/Jetson/PWM-config.txt");
	
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


