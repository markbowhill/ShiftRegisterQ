#include <inttypes.h>
#include "Print.h"
#include "Arduino.h"
#include "Wire.h"

class ShiftRegisterQ {
  public:
    ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC, bool bitO);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC, bool bitO, uint8_t pantQ);
    void print(String * datos);
    void setPins(uint8_t pinD, uint8_t pinC);
    
  private:
    uint8_t   transChar(char ch);
    uint8_t   _displaysQuantity;
    uint8_t   _pinData;
    uint8_t   _pinClock;
    uint8_t   _pinLatch;
    bool      _orderBit;
};