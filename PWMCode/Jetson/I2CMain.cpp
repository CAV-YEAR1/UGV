#include "I2CPWM.hpp"

int main(int argc, char *argv[])
{
  PWM p("../I2C-config.txt");
  p.run();
  return 0;
}
