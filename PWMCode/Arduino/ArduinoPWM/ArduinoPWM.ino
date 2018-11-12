#include "Wire.h"
#include "Servo.h"

#define START_SPEED 100
#define START_STEERING 90

typedef struct
{
    Servo   Motor; 
    int     Pin;   // Indicates the Pin this motor is connected to
} MotorDef;


typedef struct
{
    Servo   Motor; 
    int     Pin;   // Indicates the Pin this motor is connected to
} ServoDef;

MotorDef RCMotor;

ServoDef SteeringServo;

typedef struct
{
  int Speed;
  int Steering;
} RCParameters;

RCParameters currentRC;

void commSetup()
{
  Wire.begin(0x04);             // join i2c bus (address optional for master)
  Wire.onRequest(requestEvent); // register event  
  Wire.onReceive(receiveEvent); // register event

  Serial.println("Started Wire");
}

void PWMSetup()
{
  // Required for I/O from Serial monitor
  Serial.println("Setup: Serial port communication at 9600bps");
  // Attach motors to pins
  
  RCMotor.Pin =  9;       //ESC for motor connects to pin 9 (can be changed)
  SteeringServo.Pin = 10; //Servo for steering connects to pin 10 (can be changed)
  int pin = RCMotor.Pin;
  RCMotor.Motor.attach(pin);
  pin = SteeringServo.Pin;
  SteeringServo.Motor.attach(pin);  

  currentRC.Speed = START_SPEED;
  currentRC.Steering = START_STEERING;
}

void setup() 
{
  Serial.begin(9600);  // start serial for output
  while(!Serial);
  commSetup();         //run I2C setup code
  PWMSetup();          //run PWM setup code

}

void loop() {
  Run();    //run PWM Code
  delay(100);
}

void requestEvent()
{
  String sp = String(currentRC.Speed, DEC);
  if(sp.length()<3) sp = String("0" + sp);
  String st = String(currentRC.Steering, DEC);
  if(st.length()<3) sp = String("0" + st);
  String s = sp + st;
  Wire.write(s.c_str()); // respond with message of 6 bytes

  Serial.println("Slave 1 Sent");
}

void receiveEvent(int howMany)
{
  Serial.println("Received data");
    
  String s = "";
  while(Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    s += c;
    //Serial.print(c);    // print the character
  }

  String sp = s.substring(0,3);
  String st = s.substring(3);

  currentRC.Speed = sp.toInt();
  currentRC.Steering = st.toInt();
  
  Serial.print("Slave 1 Rx: ");
  Serial.println(s);
}

void Run()
{
  RCMotor.Motor.write(currentRC.Speed);
  SteeringServo.Motor.write(currentRC.Steering);
}
