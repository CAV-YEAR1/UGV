#include "../PWMCode/Jetson/PWM.hpp"

#define LEFT 150
#define STRAIGHT 90
#define RIGHT 30

int main(int argc, char * argv[])
{
  PWM p("../PWM-config.txt");
  if(!p.setup()) {
    std::cout<<"Error: PWM setup failed"<<std::endl;
    return 0;
  }

  std::string input;
  for(;;) {
    getline(std::cin, input);
    if(input.find_first_of("0123456789") != std::string::npos)
    {
      if(!p.setSpeed(std::stoi(input))) {
        p.off();
        return 0;
      }
    }
    else if(input == "l") {
      if(!p.setSteering(LEFT)) {
        p.off();
        return 0;
      }
    }
    else if(input == "r") {
      if(!p.setSteering(RIGHT)) {
        p.off();
        return 0;
      }
    }
    else if(input == "s") {
      if(!p.setSteering(STRAIGHT)) {
        p.off();
        return 0;
      }
    }
    else if(input == "q") {
      p.off();
      std::cout<<"Exiting Program"<<std::endl;
      return 0;
    }
    else {
      std::cout<<"Invalid Command"<<std::endl;
    }
  }
  return 0;
}
