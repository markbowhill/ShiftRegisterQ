//Compatible with the Arduino IDE 1.0
#include <ShiftRegisterQ.h>

uint8_t pinData = 5;
uint8_t pinLatch = 6;
uint8_t pinClock = 7;
bool pinMS = 1;
uint8_t displaysQuantity = 11;

ShiftRegisterQ shiftR(pinData, pinLatch, pinClock, pinMS, displaysQuantity);  //configurar los pins, el pin significativo y la cantidad de pantallas

void setup()
{
    String Data = "Hello world";
    shiftR.print(&Data);

    newPinData = 8;
    newPinData = 9;
    newPinClock = 10;
    shiftR.setPins(newPinData, newPinLatch, newPinClock); //Cambiar los pins de comunicación con el shift register
    shiftR.print(&Data);
}

void loop()
{
}