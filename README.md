# ShiftRegisterQ

Librería Arduino ShiftRegisterQ para imprimir en pantallas Shift Register

### Uso
- Incluir en el sketch
```cpp
#include <ShiftRegisterQ.h>          // https://github.com/markbowhill/ShitfRegisterQ
```

- Inicializa una instancia de la clase
```cpp
ShiftRegisterQ shiftR(4, 5, 1, 11); //pin de datos, pin de reloj, bit significatico (1 = Mas, 0 = Menos), cantidad de pantallas
```
- para mandar imprimir una cadena de caracteres
```cpp
String Data = "Hello world";
shiftR.setPins(7, 8); //pin de datos, pin de reloj
```

- En el setup también puedes reconfigurar los pines
```cpp
shiftR.setPins(7, 8);
```