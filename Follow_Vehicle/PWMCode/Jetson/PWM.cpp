#include "PWM.hpp"

PWM::PWM(std::string file) : filename(file) {}

PWM::~PWM() {
  delete comm;
}

bool PWM::setup() {
  std::ifstream in(filename);
  if(!in.is_open()) {
    std::cout<<"Error: Invalid file name"<<std::endl;
    return false;
  }

  std::string line;
  while(std::getline(in, line)) {
    if(line[0] != '#') {
      config.push_back(line);
    }
  }

  comm = new IIC(config[0]);
  maxSpeed = std::stoi(config[1]);
  minSpeed = std::stoi(config[2]);
  startSpeed = std::stoi(config[3]);
  maxSteering = std::stoi(config[4]);
  minSteering = std::stoi(config[5]);
  centerSteering = std::stoi(config[6]);

  if(config[7] == "CAL") currentMode = CALIBRATE;
  else if(config[7] == "THR") currentMode = THROTTLE;
  else if(config[7] == "RUN") currentMode = RUN;
  else {
    std::cout<<"Invalid Mode"<<std::endl;
    return false;
  }

  controlFile = config[8];

}

bool PWM::setPWM(int value) {
  std::string message = std::to_string(value);
  if(!comm -> sendData(message)) return false;
}

bool PWM::setPWM(std::string value) {
  if(!comm -> sendData(value)) return false;
}

//bool PWM::getPWM(int value);
void PWM::calibrate() {
  std::string input;
  std::string message;
  std::cout<<"Entering Calibration mode, press any key or type \"quit\" to exit"<<std::endl;
  message = std::to_string(maxSpeed) + "000";
  if(!setPWM(message)) {
    std::cout<<"Error: Invalid maximum value"<<std::endl;
    return;
  }
  std::cin>>input;
  if(input == "quit") return;
  message = std::to_string(minSpeed) + "000";
  if(!setPWM(message)) {
    std::cout<<"Error: Invalid minimum value"<<std::endl;
    return;
  }
  std::cout<<"Press any key or type \"quit\" to exit"<<std::endl;
  std::cin>>input;
  if(input == "quit") return;
  message = std::to_string(maxSpeed) + "000";
  if(!setPWM(message)) {
    std::cout<<"Error: Invalid maximum value"<<std::endl;
    return;
  }
  usleep(2000000); //wait 2 seconds
  std::cout<<"Calibrating ESC complete."<<std::endl;
  off();

}

void PWM::setThrottle() {
  //set throttle range mode
}

void PWM::run() {
  std::string message;

  std::ifstream in(controlFile);
  if(!in.is_open()) {
    std::cout<<"Error: Invalid control file name"<<std::endl;
    return;
  }

  int duration;
  std::string input;
  while(std::getline(in, input)) {
    if(input[0] != '#') {
    std::stringstream ss(input);
      while(std::getline(ss, input, ',')) {
        message += input;
      }
    }
    setPWM(message.substr(0,6));
    usleep(std::stoi(message.substr(6,message.back())));
  }
  off();
}

void PWM::loop() {
  if(currentMode == CALIBRATE) calibrate();
  else if(currentMode == THROTTLE) setThrottle();
  else if(currentMode == RUN) run();
}

bool PWM::off() {
  std::string message = std::to_string(minSteering) + std::to_string(centerSteering);
  setPWM(message);
  return true;
}
