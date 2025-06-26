#include <stdio.h>
#include <stdlib.h>

/* Conflicto de variables con el mismo nombre */

void f1(void); /*Prototipo de funcion */
     /*Variable global */
int K_GLOBAL = 5;

void main(void)
{
    int I;
    for(I = 1; I <= 3; I++)
        f1();
}
void f1(void)
/* La funcion utiliza tanto la variable local I como la variable global I. */
{
    int K = 2;  /*Variable local */
    K += K;
    printf("\nEl valor de la variable local es: %d", K);
    K_GLOBAL = K_GLOBAL + K;    /* Uso de ambas variables. */
    printf("\nEl valor de la variable global es: %d", K_GLOBAL);
}
