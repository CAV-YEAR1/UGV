#include "PWM.hpp"

int main(int argc, char * argv[])
{
  PWM p("../PWM-config.txt");
  p.loop();
  return 0;
}
