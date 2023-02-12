#include "ShiftRegisterQ.h"


ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC)
{
    setPins(pinD, pinL, pinC);
    _orderBit = true;
    _displaysQuantity = 1;
}

ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC, bool bitO)
{
    setPins(pinD, pinL, pinC);
    _orderBit = bitO;
    _displaysQuantity = 1;
}

ShiftRegisterQ::ShiftRegisterQ(uint8_t pinD, uint8_t pinL, uint8_t pinC, bool bitO, uint8_t disQ)
{
    setPins(pinD, pinL, pinC);
    _orderBit = bitO;
    _displaysQuantity = disQ;
}

void ShiftRegisterQ::print(String * datos){
    uint8_t largoDatos = datos->length();
    uint8_t byteData;
    for(uint8_t i = 0; i < largoDatos; i++){
        char d = datos->charAt(i);
        if(d != '.' && d != ','){
            char ds = datos->charAt(i+1);
            if(ds != '.' && ds != ','){
                byteData = transChar(d);
            }else{
                byteData = transChar(d)+128;
            }
        }
        shiftOut(_pinData, _pinClock, _orderBit, byteData);
    }
    digitalWrite(_pinLatch, HIGH);
    digitalWrite(_pinLatch, LOW);
}

void ShiftRegisterQ::setPins(uint8_t pinD, uint8_t pinL, uint8_t pinC){
    _pinData    = pinD;
    _pinLatch   = pinL;
    _pinClock   = pinC;
    pinMode(_pinData, OUTPUT);
    pinMode(_pinClock, OUTPUT);
    pinMode(_pinLatch, OUTPUT);
}

uint8_t ShiftRegisterQ::transChar(char ch){
    uint8_t bits;
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
        default:   bits = 0;
    }
    return bits;
}