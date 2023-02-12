//Compatible with the Arduino IDE 1.0
#include <ShiftRegisterQ.h>


ShiftRegisterQ shiftR();

void setup()
{
    uint8_t pinData = 4;
    uint8_t pinClock = 5;
    uint8_t pinLatch = 6;
    shiftR.setPins(pinData, pinClock, pinLatch, displayType, displaysQuantity); //Cambiar los pins de comunicación con el shift register
    
    uint8_t displayType = 7; // 7, 15 y 16 segmentos
    uint8_t displaysQuantity = 12;
    shiftR.setDisplay(displayType, displaysQuantity);
    
    String Data = "Hello world";
    shiftR.print(&Data);
}

void loop()
{
}