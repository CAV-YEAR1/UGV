 #include <Wire.h>

void setup()
{
  Serial.begin(9600);  // start serial for output
  while(!Serial);

  Wire.begin(0x04);        // join i2c bus (address optional for master)
  Wire.onRequest(requestEvent); // register event  
  Wire.onReceive(receiveEvent); // register event

  Serial.println("Started Wire");
}

void loop()
{
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  Wire.write("HEVT"); // respond with message of 4 bytes

  Serial.println("Slave 1 Sent");
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  Serial.println("Received data");
    
  String s = "";
  while(Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    s += c;
    //Serial.print(c);         // print the character
  }
  
  Serial.print("Slave 1 Rx: ");
  Serial.println(s);
}
