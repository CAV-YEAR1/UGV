#include <stdio.h>
#include <unistd.h> 	//Used for UART
#include <fcntl.h> 		//Used for UART
#include <termios.h>	//Used for UART

int main()
{


	int uart0_filestream = -1;

	uart0_filestream = open("/dev/ttyS0", O_WRONLY | O_NOCTTY | O_NONBLOCK);		//Open in non blocking read/write mode
	if (uart0_filestream == -1)
	{
		//ERROR - CAN'T OPEN SERIAL PORT
		printf("Error - Unable to open UART.  Ensure it is not in use by another application\n");
		return -1;
	}
	usleep(3500000); //wait for arduino to reboot
	if (!isatty(uart0_filestream)) {
		//error - not a TTY device
		printf("Error - not a TTY device");
		return -1;
	}
	struct termios options;
	//get the serial port settings
	tcgetattr(uart0_filestream, &options);
	//set baud rate for input and output to 9600
	cfsetispeed(&options, B9600);
	cfsetospeed(&options, B9600);
	//configure console flags
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	//set to cannonical mode
	options.c_lflag |= ICANON;
	//commit the settings
	tcsetattr(uart0_filestream, TCSANOW, &options);
	//prompt for int to send to arduino
	printf("Please enter an int to send to arduino: ");
	int send = 0;
	scanf("%d", &send);
	//send the int to arduino
	int sent = -1;
	for (int i = 0; i < 100; i++) {
		sent = write(uart0_filestream, &send, 1);
		if (sent <= 0) {
			printf("Nothing was sent to arduino!");
			return -1;
		}
	}
	//----- CLOSE THE UART -----
	close(uart0_filestream);
	
	return 0;
}
