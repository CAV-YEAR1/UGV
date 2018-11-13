#include "I2C.hpp"

int main(int argc, char *argv[])
{
  IIC comm("../I2C-config.txt");
  comm.run();
  return 0;
}
