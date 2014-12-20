#include <Wire.h>            // handles our I2C communication
#include <math.h>

const byte buttonPin = 2;

const byte I2Caddress = 14;   // The I2C address this arduino will go by

void setup() 
{
  Wire.begin(I2Caddress);            // join i2c bus with address 14
  Wire.onRequest(requestEvent);      // When there is a request, call this function
  pinMode(buttonPin,INPUT);
}

void loop()
{
  // Nothing goes in here, unless you want this arduino to do something at the same time.
}

void requestEvent() 
{  
  byte f = digitalRead(buttonPin);
  Wire.write(f);  // Write the pin state to the bus
}
