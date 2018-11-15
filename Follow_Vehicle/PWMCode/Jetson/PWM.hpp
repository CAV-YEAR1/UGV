#ifndef _PWM_HPP_
#define _PWM_HPP_

#include "../../I2C_Code/Jetson/I2C.hpp"

typedef enum {CALIBRATE, THROTTLE, RUN} Mode;

class PWM {

private:
  IIC * comm;
  int minSpeed;
  int maxSpeed;
  int startSpeed;
  int minSteering;
  int maxSteering;
  int centerSteering;
  std::string filename;
  std::string controlFile;
  Mode currentMode;
  std::vector<std::string> config;

public:
  PWM(std::string file);
  ~PWM();
  bool setup();
  bool setPWM(int value);
  bool setPWM(std::string value);
  //bool getPWM(int value);
  void calibrate();
  void setThrottle();
  void run();
  void loop();
  bool off();
};

#endif
