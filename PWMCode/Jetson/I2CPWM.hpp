#ifndef _I2CPWM_HPP_
#define _I2CPWM_HPP_

#include <iostream>
#include <linux/types.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <utime.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include <exception>
#include <string>
#include <iosfwd>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cctype>
#include <string.h>
#include <time.h>

#include <errno.h>
#include <fcntl.h>
#include <poll.h>

#include <getopt.h>
#include <sys/ioctl.h>

#include <linux/i2c-dev.h>

class PWM {

private:
  int device1Handle;
  int readBytes;
  char buffer[7];
  int device1I2CAddress;
  int slave;

public:
  PWM(int address);
  bool commSetup();
  bool sendData();
  bool getData();
  void close();
  void run();

};

#endif
