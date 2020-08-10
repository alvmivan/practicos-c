#include "BigNumber.h"

int main(int argc, char const *argv[])
{   
    
    BigNumber stack12;
    BigNumber * number12 = &stack12;

    fillWithValue(number12, 12);
    
    BigNumber * number95 = createBigNumber();
    fillWithValue(number95, 95);

    BigNumber * number107 = createBigNumber();
    add(number12, number95, number107);

    printf("should print 95 \n");
    printBigNumber(number95);  
    printf("should print 12 \n");
    printBigNumber(number12);  
    printf("should print 107 \n");
    printBigNumber(number107);    

    dispose(number107);
    dispose(number95);
    //dispose(number12) // no es dinámico, se borra solo al concluir su scope

    return 0;
}



