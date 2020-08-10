#include <stdio.h>
#include <stdlib.h>

#define DecimalsCount 100

typedef int digit;
typedef struct bignum
{
    digit decimals[DecimalsCount];    
} BigNumber;


// requires lhs, rhs and result valid pointers
void add(BigNumber * lhs, BigNumber * rhs, BigNumber * result)
{
    digit carryOver = 0;
    for (int i = 0; i < DecimalsCount; ++i)
    {
        digit firstAddition = lhs->decimals[i] + rhs->decimals[i] + carryOver;
        result->decimals[i] = firstAddition % 10;
        carryOver = firstAddition / 10;
    }
    //aca puedo chequear carryOver y largar un error si no es 0 porque "revalsó"
}


// sets a value to our big number
void fillWithValue(BigNumber * number, int value)
{    
    for (int i = 0; i < DecimalsCount; ++i)
    {
        number->decimals[i] = value % 10;
        value /= 10;
        // no corto en value == 0, asi lo lleno de ceros a propósito
    }
}


// create a new bigNumber usign memory allocation
BigNumber * create()
{
    BigNumber * number = (BigNumber *) malloc(sizeof(BigNumber)); 
    fillWithValue(number, 0);// lo lleno de ceros
    return number;
}

void dispose(BigNumber * number)
{
    if(number)
        free(number);
}

void print(BigNumber * number)
{
    int printing = 0;
    for (int i = DecimalsCount-1; i >= 0; --i)
    {
        digit digit = number->decimals[i];
        printing = printing | digit;
        if(printing)
        {
            printf("%d" , digit);
        }
        
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{
    
    
    BigNumber * number12 = create();
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


    return 0;
}



