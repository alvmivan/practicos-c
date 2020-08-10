
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
void add(BigNumber * lhs, BigNumber * rhs, BigNumber * result);

// le asigna el valor de value al numero, requiere un puntero válido
void fillWithValue(BigNumber * number, int value);

// retorna un puntero ya alocado a un numero grande equivalente a cero listo para usarse
BigNumber * createBigNumber();
// libera la memoria de un puntero previamente alocado si es un puntero válido
void dispose(BigNumber * number);

// imprime el valor del número y un enter
// requiere un puntero válido
void printBigNumber(BigNumber * number);

