#include <SoftwareSerial.h>

const byte rx = 0;
const byte tx = 1;

SoftwareSerial input(rx, tx);

void setup() {
  // put your setup code here, to run once:
  input.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!input.isListening()) {
    Serial.print("Not listening!");
  }
  if (input.available() > 0) {
    char rec = input.read();
    Serial.println(rec);
  }
}
