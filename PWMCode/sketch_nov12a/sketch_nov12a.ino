#include "wire.h"
#include "sevo.h"

void setup()
{
  Serial.begin(9600);  // start serial for output
  while(!Serial);

  Wire.begin(0x04);        // join i2c bus (address optional for master)
  Wire.onRequest(requestEvent); // register event  
  Wire.onReceive(receiveEvent); // register event

  Serial.println("Started Wire");
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
