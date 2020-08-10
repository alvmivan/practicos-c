#include <stdio.h>
#include <stdlib.h>

#define DecimalsCount 100

//lo pongo en un typedef por si quiero cambiarlo para optimizar memoria
// (recordatorio, cambiar también el caracter de printf)
typedef int digit;

//defino mi estructura utilizando un arreglo de digitos
// decidí dejarle un array estático, ya que ese es el tamaño que conservará
typedef struct bignum
{
    digit decimals[DecimalsCount];    
}BigNumber;




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



int main(int argc, char const *argv[])
{   
    
    BigNumber stack12;
    BigNumber * number12 = &stack12;

    fillWithValue(number12, 12);
    
    BigNumber * number95 = create();
    fillWithValue(number95, 95);

    BigNumber * number107 = create();
    add(number12, number95, number107);

    printf("should print 95 \n");
    print(number95);  
    printf("should print 12 \n");
    print(number12);  
    printf("should print 107 \n");
    print(number107);    

    dispose(number107);
    dispose(number95);
    //dispose(number12) // no es dinámico, se borra solo al concluir su scope

    return 0;
}



