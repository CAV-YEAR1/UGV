/*
=================================================================================
 Name        : i2c-arduino.c
 Version     : 1.0

================================================================================
This code sends i2c messages from the jetson to Arduino and recieves a message
as well. Do not modify code unless you know what you're doing.
================================================================================
*/

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
//#include <linux/i2c.h>

int device1Handle;
int readBytes;
char buffer[7];


// function for testing command
void get_data(int handle, char slave)
{
	char command[3] = {'c', 'a', 'v'};

	std::cout << "sending to slave " << slave << std::endl;
	readBytes = write(handle, command, 3);

	// give arduino some reaction time
	usleep(100000); // 100ms

	// read success
	readBytes = read(handle, buffer, 6);

	if (readBytes != 6)
		std::cout << "Error: Invalid receive!" << std::endl;
	else
        std::cout << "Response: " << buffer << std::endl;
}

int main (void)
{
	// print infos
	printf("Jetson TX2 I2C Arduino\n");
	printf("===================================\n");

	// initialize buffer
	buffer[0] = 0x00;

	// address of i2c Arduino device 1
	int device1I2CAddress = 0x04;  // (0x01 = 42)

    	//std::string i2c_port = "/dev/i2c-0"; //GEN1_I2C
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

    	for(int i=0; i<10; i++) {
        	get_data(device1Handle, 0);
		usleep(1000000); // 1s
    	}

	// close connection and return
	close(device1Handle);
	return 0;
}
