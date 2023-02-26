//Compatible with the Arduino IDE 1.0
#include <ShiftRegisterQ.h>

uint8_t pinData = 5;
uint8_t pinClock = 6;
uint8_t pinLatch = 7;
uint8_t displayType = 7; // 7, 15 ó 16 segmentos
uint8_t displaysQuantity = 11;

ShiftRegisterQ shiftR(pinData, pinClock, pinLatch, displayType, displaysQuantity);  //configurar los pins y el tipo y cantidad de pantallas

void setup()
{
    String Data = "Hello world";
    shiftR.print(&Data);

    shiftR.clearAll(); //limpia toda/s las pantallas
}

void loop()
{
}