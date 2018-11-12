#include "I2CPWM.hpp"

void PWM::PWM(int address) : device1I2CAddress(address), slave(0) {}

bool PWM::commSetup() {
  // initialize buffer
  buffer[0] = 0x00;

 	std::string i2c_port = "/dev/i2c-1"; //GEN2_I2C

	// open device on /dev/i2c-1
	if ((device1Handle = open(i2c_port.c_str(), O_RDWR)) < 0) {
		printf("Error: Couldn't open device! %d\n", device1Handle);
		return 1;
	}

	// connect to arduino as i2c slave
	if (ioctl(device1Handle, I2C_SLAVE, device1I2CAddress) < 0) {
		printf("Error: Couldn't find arduino on address!\n");
		return 1;
	}

}

bool PWM::sendData() {
  char command[3] = {'c', 'a', 'v'};

	std::cout << "sending to slave " << slave << std::endl;
	readBytes = write(device1Handle, command, 3);
}

bool PWM::getData() {
  readBytes = read(handle, buffer, 4);

	if (readBytes != 4)
    std::cout << "Error: Invalid receive!" << std::endl;
	else
    std::cout << "Response: " << buffer << std::endl;
}

void PWM::close() {
  close(device1Handle);
}

void PWM::run() {
  commSetup();
  for(int i = 0; i< 10, ++i)
  sendData();
  usleep(100000);
  getData();
  usleep(1000000);
  close();
}
