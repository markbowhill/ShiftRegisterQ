//Compatible with the Arduino IDE 1.0
//Library version:1.0.3-beta
#include <ShiftRegisterQ.h>

uint8_t pinData = 5;
uint8_t pinClock = 6;
bool pinMS = 1;
uint8_t displaysQuantity = 11;

ShiftRegisterQ shiftR(pinData, pinClock, pinMS, displaysQuantity);  //configurar los pins, el pin significativo y la cantidad de pantallas

void setup()
{
    String Data = "Hello world";
    shiftR.print(&Data);

    newPinData = 7;
    newPinClock = 8;
    shiftR.setPins(newPinData, newPinClock); //Cambiar los pins de comunicación con el shift register
    shiftR.print(&Data);
}

void loop()
{
}