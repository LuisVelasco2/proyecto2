# documentación

```angular2html
interfaz


#ifndef INTCELL_H
#define INTCELL_H

class IntCell 
public:
    IntCell() = default;
    IntCell(int newValue = 0);
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    ~IntCell() = default;

    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;
    IntCell &operator=(int rhs);
    IntCell &operator+(const IntCell &rhs);
    IntCell &operator+(int rhs);
    IntCell &operator-(const IntCell &rhs);
    IntCell &operator-(int rhs);

    int getValue() const;
    void setValue(int newValue);

private:
    int storedValue;
    int storedValue2;
    int storedValue3;
;

#endif  // INTCELL_H

```
> empezezando con este codigo que habla empieza hablando, que si no esta definido intcell.h, lo vas a definir
> y luego empieza abrir una clase Intcell y en la seccion publica,
> hablan sobre como los constructores definen, por ejemplo
> habla el primero que Construye un IntCell .
>generando y compilando
> y luego la linea de abajo copia el constructor con el mismo valor hasta que un destructor termine lo que hay dentro del constructor
> y luego el de abajo tambien es un contrusctor que requiere un valor para empezar a construirse en este caso el 0
> en la siguiente linea hay un puntero que coipia todo lo que escriba el otro constructor
> y en la siguiente line ahay otro puntero que muestra lo que copia del otro puntero
> y en la siguiente linea hay un destrucotr cual indica que otra  cosa mas abajo de este no se copie en el constructor
> y luego en las siguientes lineas hablan do operadores que  lo hacen es sobre escribir informacion si es que habia y si 
> no pondran informacion ahi y luego declaran rhs y luego terminan la declaracion
> y luego tienen el get value donde obtiene la informacion y luego la ponen
> y luego ahora pasamos en seccion privada que deberiamos llamar el nombre para convocarlas de nuevo
> y luego declara storedValue esperando tener informacion
> y luego termina la definicion endif


```angular2html
Implementación

#include "IntCell.h"

IntCell::IntCell(int newValue) : storedValue(newValue) 

IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) 

IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) 

IntCell &IntCell::operator=(const IntCell &rhs) 
    if (this != &rhs) 
        storedValue = rhs.storedValue;
    
    return *this;


IntCell &IntCell::operator=(IntCell &&rhs) noexcept 
    if (this != &rhs) 
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    
    return *this;


IntCell &IntCell::operator=(int rhs) 
    storedValue = rhs;
    return *this;


IntCell &IntCell::operator+(const IntCell &rhs) 
    storedValue = storedValue + rhs.storedValue;
    return *this;


IntCell &IntCell::operator+(int rhs) 
    storedValue = storedValue + rhs;
    return *this;


IntCell &IntCell::operator-(const IntCell &rhs) 
    storedValue = storedValue - rhs.storedValue;
    return *this;


IntCell &IntCell::operator-(int rhs) 
    storedValue = storedValue - rhs;
    return *this;


int IntCell::getValue() const 
    return storedValue;


void IntCell::setValue(int newValue) 
    storedValue = newValue;




```

> empieza esta clase siendo el ".h", y luego hablan de como declararan constructores
> y como algunos leen el resultado con punteros y otros leen el resultado de estos y luego hay un operador
> que ayuda a sobre escribir intcell y otro que ayuda a sobre escribir el rhs
> y luego la informacion se juntara junto con rhs y storedvalue 
> en los ultimos operadores, no guardaran informacion si no que lo quitaran lo que sobre escribieron
> y en el penultimo codigo, obtinees los mismos valores que obtuvo el storedvalue y en el ultimo codigo
> pones lo que obtuviste  de informacion en el storedValue

