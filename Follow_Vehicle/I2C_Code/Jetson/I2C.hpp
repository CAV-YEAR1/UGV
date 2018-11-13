#ifndef _I2C_HPP_
#define _I2C_HPP_

#include <iostream>
#include <linux/types.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <utime.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include <string>
#include <iosfwd>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cctype>
#include <string.h>
#include <time.h>
#include <vector>

#include <errno.h>
#include <fcntl.h>
#include <poll.h>

#include <getopt.h>
#include <sys/ioctl.h>

#include <linux/i2c-dev.h>

class IIC {

private:
  std::string filename;
  int device1Handle;
  int readBytes;
  char * buffer;
  int device1I2CAddress;
  int slave;
  int sendLength;
  int receiveLength;
  std::vector<std::string> config;

public:
  IIC(std::string file);
  bool commSetup();
  bool sendData(std::string message);
  bool getData();
  void clean();
  void run();

};

#endif
