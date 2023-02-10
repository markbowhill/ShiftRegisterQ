//Compatible with the Arduino IDE 1.0
//Library version:0.0.1-beta
#include <ShiftRegisterR.h>

uint8_t pinData = 5
uint8_t pinClock = 6;
bool pinMS = 1;
uint8_t dQuantity = 5;

ShiftRegister lcdR(pinData, pinClock, pinMS, dQuantity);  // set the Display with propieties and quantity

void setup()
{
    String Data = "Hello";
    lcdR.print(&Data);
}

void loop()
{
}