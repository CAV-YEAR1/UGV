#include "I2C.hpp"

IIC::IIC(std::string file) : filename(file) {}

bool IIC::commSetup() {

  std::ifstream in(filename);
  if(!in.is_open()) {
    std::cout<<"Error: Invalid file name"<<std::endl;
    return false;
  }

  std::string line;
  std::getline(in, line);
  while(!in.fail()) {
    if(line[0] != '#') {
      config.push_back(line);
      std::getline(in, line);
    }
  }

 	std::string i2c_port = config[0];
  std::stringstream ss;
  ss << std::hex << config[1];
  ss >> device1I2CAddress;
  slave = stoi(config[4]);
  sendLength = stoi(config[2]);
  receiveLength = stoi(config[3]);

  // initialize buffer
  buffer = new char[receiveLength + 1];
  buffer[0] = 0x00;

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

  return true;

}

bool IIC::sendData(std::string message) {
  if(message.length() != sendLength) {
    std::cout<<"Error: Invalid message length"<<std::endl;
    return false;
  }
  message.c_str();

	std::cout << "sending to slave " << slave << std::endl;
	readBytes = write(device1Handle, message.c_str(), sendLength);

  return true;
}

bool IIC::getData() {
  readBytes = read(device1Handle, buffer, receiveLength);

	if (readBytes != receiveLength) {
    std::cout << "Error: Invalid receive!" << std::endl;
    return false;
  }
	else
    std::cout << "Response: " << buffer << std::endl;

  return true;
}

void IIC::clean() {
  close(device1Handle);
}

void IIC::run() {
  if(!commSetup()) return;
  for(int i = 0; i< 10; ++i) {
    if(!sendData("000000")) return;
    usleep(100000);
    getData();
    usleep(1000000);
  }
  clean();
}
