#include <inttypes.h>
#include "Print.h"
#include "Arduino.h"
#include "Wire.h"

class ShiftRegisterQ {
  public:
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC, bool bitS);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC, bool bitS, uint8_t pantQ);
    void print(String * datos);
    void setPins(uint8_t pinD, uint8_t pinC);
    
  private:
    uint8_t transChar(char ch);
    uint8_t displaysQuantity;
    uint8_t pinData;
    uint8_t pinClock;
    bool significantBit;
};