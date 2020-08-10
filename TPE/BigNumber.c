#include <stdio.h>
#include <stdlib.h>
#include "BigNumber.h"

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

// requires lhs, rhs and result valid pointers
void add(BigNumber * lhs, BigNumber * rhs, BigNumber * result)
{
    // para ir guardando lo que me llevo
    digit carryOver = 0;
    
    for (int i = 0; i < DecimalsCount; ++i)
    {
        // computo una suma preliminar agregando el carry over de la operación anterior
        digit firstAddition = lhs->decimals[i] + rhs->decimals[i] + carryOver;
        // solo asigno el dígito menos significativo
        result->decimals[i] = firstAddition % 10;
        // me fijo si hay carry over
        carryOver = firstAddition / 10;
    }
    //aca puedo chequear carryOver y largar un error si no es 0 porque "revalsó"
}


// le asigna el valor de value al numero, requiere un puntero válido
void fillWithValue(BigNumber * number, int value)
{    
    for (int i = 0; i < DecimalsCount; ++i)
    {
        number->decimals[i] = value % 10;
        value /= 10;
        // no corto en value == 0, asi lo lleno de ceros a propósito
    }
}



// retorna un puntero ya alocado a un numero grande equivalente a cero listo para usarse
BigNumber * create()
{
    BigNumber * number = (BigNumber *) malloc(sizeof(BigNumber)); 
    fillWithValue(number, 0);// lo lleno de ceros
    return number;
}

// libera la memoria de un puntero previamente alocado si es un puntero válido
void dispose(BigNumber * number)
{
    if(number)
        free(number);
}

// imprime el valor del número y un enter
// requiere un puntero válido
void print(BigNumber * number)
{
    // un flag para evitar imprimir los 0's no significativos
    int printing = 0;
    for (int i = DecimalsCount-1; i >= 0; --i)
    {
        digit digit = number->decimals[i];
        // si estaba imprimiendo o si tengo un dígito para imprimir (para no descartar los 0's del medio )
        printing = printing | digit;
        // me salteo los 0's no significativos
        if(printing) 
        {
            printf("%d" , digit);
        }        
    }
    //imprimo un enter al final
    printf("\n");
}

#endif