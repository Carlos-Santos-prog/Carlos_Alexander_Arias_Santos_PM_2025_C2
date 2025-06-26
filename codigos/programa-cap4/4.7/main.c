#include <stdio.h>
#include <stdlib.h>

/* Prueba de parametros por valor */

int f1(int); /* Prototipo de funcion. el parametro es por valor y de tipo entero*/

int main(void)
{
    int I, K = 1;

    for (I = 1; I <= 15; I++)
    {
        printf("\n\nValor de K antes de llamar a la funcion:    %d", ++K);
        printf("\nValor de K despues de llamar a la funcion:  %d", f1(K));
        /*Llamada a la funcion f1. Se pasa una copia de la variable K. */

    }
    return 0;
}
int f1(int R)
{
    R += R;
    return R;
}
