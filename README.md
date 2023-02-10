# ShiftRegisterQ

Librería Arduino ShiftRegisterQ para imprimir en pantallas Shift Register

![Release](https://img.shields.io/github/v/release/markbowhill/ShiftRegisterQ)

### Uso
- Incluir en el sketch
```cpp
#include <ShiftRegisterQ.h>          // https://github.com/markbowhill/ShitfRegisterQ
```
- Creamos unas variables para almacenar los datos necesario
```cpp
uint8_t pinData     = 4;        // pin de datos
uint8_t pinClock    = 5;        // pin de reloj
bool bitOrder       = true;     // bit significatico (true = MSBFIRST, false = LSBFIRST)
uint8_t displaysQ   = 11;       // cantidad de pantallas
```
- Inicializa una instancia de la clase
```cpp
ShiftRegisterQ shiftR(pinData, pinClock, bitOrder, displaysQ);
```
- Manda imprimir una cadena de caracteres
```cpp
String Data = "Hello world";
// Se pasa un puntero del string de datos
shiftR.print(&Data); 
```

- En el setup también puedes reconfigurar los pines
```cpp
shiftR.setPins(7, 8); // pin de datos, pin de reloj
```