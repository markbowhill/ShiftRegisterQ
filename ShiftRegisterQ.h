#include <inttypes.h>
#include "Print.h"
#include "Arduino.h"
#include "Wire.h"

class ShiftRegisterQ {
  public:
    ShiftRegisterQ();
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL, uint8_t disT);
    ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL, uint8_t disT, uint16_t disQ);
    void print(String*);
    void setPins(uint8_t, uint8_t, uint8_t);
    void setDisplay(uint8_t);
    void setDisplay(uint8_t, uint16_t);
    void setDelayScroll(uint32_t);
    void clearAll();
    
  private:
    void      sendOne(char, bool);
    void      run();
    uint16_t  transChar(char);
    uint8_t   _pinData = 7;
    uint8_t   _pinClock = 9;
    uint8_t   _pinLatch = 8;
    uint8_t   _displayType = 7;
    uint16_t  _displaysQuantity = 1;
    bool      _orderBit = true; // default MSBFIRST
    uint32_t  _delayScroll = 200;
};