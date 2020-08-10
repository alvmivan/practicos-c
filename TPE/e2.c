numer#include "BigNumber.h"
#include "List.h"
#include "Constants.h"
#include <stdio.h>


void printNumber(void * bigNumber)
{
    printBigNumber((BigNumber *) bigNumber);

    return NULL;
}

int main(int argc, char const *argv[])
{   
    
    List * list = newList();
    
    BigNumber * uno = createBigNumber();
    BigNumber * dos = createBigNumber();
    BigNumber * tres = createBigNumber();

    fillWithValue(uno,1);
    fillWithValue(dos,2);
    fillWithValue(tres,3);

    addLast(list, uno);
    addLast(list, dos);
    addLast(list, tres);

    foreach(list, &printNumber);
    
    
    printf("_");
    
    return 0;
}



