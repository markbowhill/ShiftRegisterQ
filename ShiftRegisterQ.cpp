#include "ShiftRegisterQ.h"


ShiftRegisterQ::ShiftRegisterQ()
{
    initPins();
}

ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL)
{
    setPins(pinD, pinC, pinL);
}

ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL, uint8_t disT)
{
    setPins(pinD, pinC, pinL);
    setDisplay(disT);
}

ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinC, uint8_t pinL, uint8_t disT, uint16_t disQ)
{
    setPins(pinD, pinC, pinL);
    setDisplay(disT, disQ);
}

void ShiftRegisterQ::print(String * datos)
{
    uint8_t largoDatos = datos->length();
    uint8_t largoDatosSinPuntos = 0;
    for(uint8_t i = 0; i < largoDatos; i++){
        char d = datos->charAt(i);
        if(d != '.' && d != ','){
            largoDatosSinPuntos++;
        }
    }
    if(largoDatosSinPuntos <= _displaysQuantity){
        clearAll();
        uint16_t byteData;
        for(uint8_t i = 0; i < largoDatos; i++){
          char d  = datos->charAt(i);
          char ds = datos->charAt(i+1);
          if(d != '.' && d != ','){
            bool p = false;
            if(ds == '.' || ds == ','){
              p = true;
            }
           	sendOne(d, p);
          }
        }
        run();
    }else{
        for(uint8_t i = 0; i < largoDatos; i++){
            if(i < _displaysQuantity){
              clearAll();
            }
            for(uint8_t j = 0; j <= i; j++){
                char d  = datos->charAt(j);
              	char ds = datos->charAt(j+1);
                if(d != '.' && d != ','){
                  	bool p = false;
                  	if(ds == '.' || ds == ','){
                      p = true;
                  	}
                    sendOne(d, p);
                }
            }
          	run();
          	char lastChar = datos->charAt(i);
            if(lastChar != '.' && lastChar != ','){
              delay(_delayScroll);
            }
        }
    }
}

void ShiftRegisterQ::setPins(uint8_t pinD, uint8_t pinC, uint8_t pinL)
{
    _pinData    = pinD;
    _pinClock   = pinC;
    _pinLatch   = pinL;
    initPins();
}

void ShiftRegisterQ::setDisplay(uint8_t disT)
{
    _displayType        = disT;
}

void ShiftRegisterQ::setDisplay(uint8_t disT, uint16_t disQ)
{
    _displayType        = disT;
    _displaysQuantity   = disQ;
}

void ShiftRegisterQ::setDelayScroll(uint32_t delayScroll)
{
    _delayScroll = delayScroll;
}

void ShiftRegisterQ::clearAll()
{
    for(uint16_t i = 1; i <= _displaysQuantity; i++){
        sendOne(' ', false);
    }
    run();
}

void ShiftRegisterQ::sendOne(char d, bool p)
{
    uint16_t byteData = transChar(d);
    if(p){
      byteData += transChar('.');
    }
    shiftOut(_pinData, _pinClock, _orderBit, byteData);
}

void ShiftRegisterQ::initPins()
{
    pinMode(_pinData, OUTPUT);
    pinMode(_pinClock, OUTPUT);
    pinMode(_pinLatch, OUTPUT);
    digitalWrite(_pinData, LOW);
    digitalWrite(_pinClock, LOW);
    digitalWrite(_pinLatch, LOW);
}

void ShiftRegisterQ::run()
{
    digitalWrite(_pinLatch, HIGH);
    digitalWrite(_pinLatch, LOW);
}

uint16_t ShiftRegisterQ::transChar(char ch)
{
    uint16_t bits;
    if(_displayType == 7){
        switch(ch){
            case '0':  bits = 1 + 2 + 4 + 8 + 16 + 32;        break;
            case '1':  bits = 2 + 4;                          break;
            case '2':  bits = 1 + 2 + 8 + 16 + 64;            break;
            case '3':  bits = 1 + 2 + 4 + 8 + 64;             break;
            case '4':  bits = 2 + 4 + 32 + 64;                break;
            case '5':  bits = 1 + 4 + 8 + 32 + 64;            break;
            case '6':  bits = 1 + 4 + 8 + 16 + 32 + 64;       break;
            case '7':  bits = 1 + 2 + 4;                      break;
            case '8':  bits = 1 + 2 + 4 + 8 + 16 + 32 + 64;   break;
            case '9':  bits = 1 + 2 + 4 + 8 + 32 + 64;        break;
            case 'A':  bits = 1 + 2 + 4 + 16 + 32 + 64;       break;
            case 'B':  bits = 4 + 8 + 16 + 32 + 64;           break;
            case 'C':  bits = 1 + 8 + 16 + 32;                break;
            case 'D':  bits = 2 + 4 + 8 + 16 + 64;            break;
            case 'E':  bits = 1 + 8 + 16 + 32 + 64;           break;
            case 'F':  bits = 1 + 16 + 32 + 64;               break;
            //case 'G':  bits = 0;                              break;
            case 'H':  bits = 2 + 4 + 16 + 32 + 64;           break;
            case 'I':  bits = 16 + 32;                        break;
            case 'J':  bits = 2 + 4 + 8 + 16;                 break;
            //case 'K':  bits = 0;                              break;
            case 'L':  bits = 8 + 16 + 32;                    break;
            //case 'M':  bits = 0;                              break;
            case 'N':  bits = 1 + 2 + 4 + 16 + 32;            break;
            //case 'Ñ':  bits = 0;                              break;
            case 'O':  bits = 1 + 2 + 4 + 8 + 16 + 32;        break;
            case 'P':  bits = 1 + 2 + 16 + 32 + 64;           break;
            //case 'Q':  bits = 0;                              break;
            //case 'R':  bits = 0;                              break;
            //case 'S':  bits = 0;                              break;
            //case 'T':  bits = 0;                              break;
            //case 'U':  bits = 0;                              break;
            //case 'V':  bits = 0;                              break;
            //case 'W':  bits = 0;                              break;
            //case 'X':  bits = 0;                              break;
            case 'Y':  bits = 2 + 4 + 8 + +32 + 64;           break;
            //case 'Z':  bits = 0;                              break;
            case 'a':  bits = 1 + 2 + 4 + 16 + 32 + 64;       break;
            case 'b':  bits = 4 + 8 + 16 + 32 + 64;           break;
            case 'c':  bits = 1 + 8 + 16 + 32;                break;
            case 'd':  bits = 2 + 4 + 8 + 16 + 64;            break;
            case 'e':  bits = 1 + 8 + 16 + 32 + 64;           break;
            case 'f':  bits = 1 + 16 + 32 + 64;               break;
            //case 'g':  bits = 0;                              break;
            case 'h':  bits = 2 + 4 + 16 + 32 + 64;           break;
            case 'i':  bits = 16 + 32;                        break;
            case 'j':  bits = 2 + 4 + 8 + 16;                 break;
            //case 'k':  bits = 0;                              break;
            case 'l':  bits = 8 + 16 + 32;                    break;
            //case 'm':  bits = 0;                              break;
            case 'n':  bits = 1 + 2 + 4 + 16 + 32;            break;
            //case 'ñ':  bits = 0;                              break;
            case 'o':  bits = 1 + 2 + 4 + 8 + 16 + 32;        break;
            case 'p':  bits = 1 + 2 + 16 + 32 + 64;           break;
            //case 'q':  bits = 0;                              break;
            //case 'r':  bits = 0;                              break;
            //case 's':  bits = 0;                              break;
            //case 't':  bits = 0;                              break;
            //case 'u':  bits = 0;                              break;
            //case 'v':  bits = 0;                              break;
            //case 'w':  bits = 0;                              break;
            //case 'x':  bits = 0;                              break;
            case 'y':  bits = 2 + 4 + 8 + +32 + 64;           break;
            //case 'z':  bits = 0;                              break;
            case '-':  bits = 64;                             break;
            case '_':  bits = 8;                              break;
            case ' ':  bits = 0;                              break;
            case '.':  bits = 128;                            break;
            case ',':  bits = 128;                            break;
            default:   bits = 0;
        }
    }
    if(_displayType == 15){

    }
    if(_displayType == 16){

    }
    return bits;
}