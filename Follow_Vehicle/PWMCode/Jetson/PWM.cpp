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
  comm -> commSetup();
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
  return true;

}

bool PWM::setPWM() {
  std::string sp = std::to_string(currentSpeed);
  while(sp.length() < 3) sp = '0' + sp;
  std::string st = std::to_string(currentSteering);
  while(st.length() < 3) st = '0' + st;
  std::string message = sp + sp;
  std::cout<<message<<"\tSpeed: "<<currentSpeed<<"\tSteering: "<<currentSteering<<std::endl;
  if(!comm -> sendData(message)) return false;

  return true;
}

bool PWM::setSpeed(int value) {
  if(value < 0 || value > 180) {
    std::cout<<"Error: Invalid Speed"<<std::endl;
    return false;
  }
  currentSpeed = value;
  setPWM();
}

bool PWM::setSteering(int value) {
  if(value < 0 || value > 180) {
    std::cout<<"Error: Invalid Speed"<<std::endl;
    return false;
  }
  currentSteering = value;
  setPWM();
}

//bool PWM::getPWM(int value);
void PWM::calibrate() {
  std::string input;
  std::string message;
  std::cout<<"Entering Calibration mode, press any key or type \"quit\" to exit"<<std::endl;
  currentSpeed = maxSpeed;
  if(!setPWM()) {
    std::cout<<"Error: Invalid maximum value"<<std::endl;
    return;
  }
  std::cin>>input;
  if(input == "quit") return;
  currentSpeed = minSpeed;
  if(!setPWM()) {
    std::cout<<"Error: Invalid minimum value"<<std::endl;
    return;
  }
  std::cout<<"Press any key or type \"quit\" to exit"<<std::endl;
  std::cin>>input;
  if(input == "quit") return;
  message = maxSpeed;
  if(!setPWM()) {
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
      currentSpeed = std::stoi(message.substr(0,3));
      currentSteering = std::stoi(message.substr(2,3));
      setPWM();
      usleep(std::stoi(message.substr(6,message.back()))*1000000);
      message.clear();
    }
  }
  off();
}

void PWM::loop() {
  if(!setup()) return;
  if(currentMode == CALIBRATE) calibrate();
  else if(currentMode == THROTTLE) setThrottle();
  else if(currentMode == RUN) run();
}

bool PWM::off() {
  currentSpeed = minSpeed;
  currentSteering = centerSteering;
  setPWM();
  return true;
}
