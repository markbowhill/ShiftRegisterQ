//Compatible with the Arduino IDE 1.0
#include <ShiftRegisterQ.h>

uint8_t pinData = 4;
uint8_t pinClock = 5;
uint8_t pinLatch = 6;
uint8_t displayType = 7; // 7, 15 y 16 segmentos
uint8_t displaysQuantity = 12;

ShiftRegisterQ shiftR(pinData, pinClock, pinLatch, displayType, displaysQuantity);  //configurar los pins, el pin significativo y el tipo y cantidad de pantallas

void setup()
{
    String Data = "Hello world";
    shiftR.print(&Data);

    int newDelay = 150;

    shiftR.setDelayScroll(newDelay); //Cambia el tiempo en milisegundos del delay del scroll
    shiftR.print(&Data);
}

void loop()
{
}