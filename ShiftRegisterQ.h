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
    void print(String * datos);
    void setPins(uint8_t pinD, uint8_t pinC, uint8_t pinL);
    void setDisplay(uint8_t disT, uint16_t disQ);
    void setDelayScroll(uint16_t);
    void clearAll();
    
  private:
    void      sendOne(char, bool);
    void      run();
    uint16_t  transChar(char ch);
    uint8_t   _pinData;
    uint8_t   _pinClock;
    uint8_t   _pinLatch;
    uint8_t   _displayType;
    uint16_t  _displaysQuantity;
    bool      _orderBit = true; // default MSBFIRST
    uint16_t  _delayScroll = 500;
};