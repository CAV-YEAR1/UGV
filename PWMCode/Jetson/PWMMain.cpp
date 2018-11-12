#include "I2CPWM.hpp"

int main(int argc, char *argv[])
{
  PWM p(0x04);
  p.run();
  return 0;
}
