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
uint8_t pinData     = 7;        // OPCIONAL - pin de datos (default 7)
uint8_t pinClock    = 9;        // OPCIONAL - pin de reloj (default 9)
uint8_t pinLatch    = 8;        // OPCIONAL - pin de latch (default 8)
uint8_t displayT    = 7;        // OPCIONAL - tipo/segmentos de pantalla (default: pantalla 7 segmentos)
uint8_t displaysQ   = 11;       // OPCIONAL - cantidad de pantallas (default: 1)
```

- Inicializa una instancia de la clase con todos los parámetros por defecto
```cpp
ShiftRegisterQ shiftR();
```

ó

- Inicializa una instancia de la clase especificando los pines
```cpp
ShiftRegisterQ shiftR(pinData, pinClock, pinLatch);
```

ó

- Inicializa una instancia de la clase especificando pines y tipo de pantalla
```cpp
ShiftRegisterQ shiftR(pinData, pinClock, pinLatch, displayT);
```

ó

- Inicializa una instancia de la clase especificando pines, tipo de pantalla y cantidad
```cpp
ShiftRegisterQ shiftR(pinData, pinClock, pinLatch, displayT, displaysQ);
```

- Manda imprimir una cadena de caracteres
```cpp
String Data = "Hello world";
// Se pasa un puntero del string de datos
shiftR.print(&Data); 
```

- En el setup también puedes reconfigurar los pines
```cpp
shiftR.setPins(4, 5, 6); // 4->pin de datos, 5->pin de reloj, 6->pin de latch
```

- También puedes reconfigurar la pantalla
```cpp
shiftR.setDisplay(16); // 16->pantalla de 16 segmentos
```

ó

```cpp
shiftR.setDisplay(16, 5); // 16->pantalla de 16 segmentos, 5->cantidad pantallas
```

- Para cambiar la velocidad del scroll en textos largos
```cpp
shiftR.setDelayScroll(150); // 150 milisegundos por ejemplo (default: 200)
```

- Para limpiar todas las pantallas
```cpp
shiftR.clearAll();
```