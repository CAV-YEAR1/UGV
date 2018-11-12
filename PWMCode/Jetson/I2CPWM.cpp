#include "I2CPWM.hpp"

PWM::PWM(int address) : device1I2CAddress(address), slave(0) {}

bool PWM::commSetup() {
  // initialize buffer
  buffer[0] = 0x00;

 	std::string i2c_port = "/dev/i2c-1"; //GEN2_I2C

	// open device on /dev/i2c-1
	if ((device1Handle = open(i2c_port.c_str(), O_RDWR)) < 0) {
		printf("Error: Couldn't open device! %d\n", device1Handle);
		return false;
	}

	// connect to arduino as i2c slave
	if (ioctl(device1Handle, I2C_SLAVE, device1I2CAddress) < 0) {
		printf("Error: Couldn't find arduino on address!\n");
		return false;
	}

}

bool PWM::sendData() {
  char command[3] = {'c', 'a', 'v'};

	std::cout << "sending to slave " << slave << std::endl;
	readBytes = write(device1Handle, command, 3);

  return true;
}

bool PWM::getData() {
  readBytes = read(device1Handle, buffer, 6);

	if (readBytes != 6) {
    std::cout << "Error: Invalid receive!" << std::endl;
    return false;
  }
	else
    std::cout << "Response: " << buffer << std::endl;

  return true;
}

void PWM::clean() {
  close(device1Handle);
}

void PWM::run() {
  if(!commSetup()) return;
  for(int i = 0; i< 10; ++i) {
    sendData();
    usleep(100000);
    getData();
    usleep(1000000);
  }
  clean();
}
