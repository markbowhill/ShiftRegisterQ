# ShiftRegisterQ

Librería Arduino ShiftRegisterQ para imprimir en pantallas Shift Register

![Release](https://img.shields.io/github/v/release/markbowhill/ShiftRegisterQ)

### Uso
- Incluir en el sketch
```cpp
#include <ShiftRegisterQ.h>          // https://github.com/markbowhill/ShitfRegisterQ
```

- Inicializa una instancia de la clase
```cpp
uint8_t pinD    = 4;    // //pin de datos
uint8_t pinC    = 5;    // pin de reloj
bool bitS       = 1;    // bit significatico (1 = Mas, 0 = Menos)
uint8_t dQ      = 11;   // cantidad de pantallas
ShiftRegisterQ shiftR(pinD, pinC, bitS, dQ);
```
- para mandar imprimir una cadena de caracteres
```cpp
String Data = "Hello world";
// Se pasa un puntero del string de datos
shiftR.setPins(&Data); 
```

- En el setup también puedes reconfigurar los pines
```cpp
shiftR.setPins(7, 8); // pin de datos, pin de reloj
```