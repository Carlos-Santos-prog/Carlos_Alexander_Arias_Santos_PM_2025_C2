#include <stdio.h>
#include <stdlib.h>

/* Cubo-3
el programa calcula el cubo de los 10 primeros numeros naturales con la
ayuda de una funcion y utilizando parametro por valor.*/

int cubo(int);  /* Prototipo de funcion. el parametro es de tipo entero */

void main(void)
{
    int I = 0;
    for(I = 1; I <= 10; I++)
        printf("\nEl cubo de I es: %d", cubo(I));

    /* Llamada a la funcion cubo. El paso del parametro es por valor. */

}

int cubo(int K)
/* La funcion calcula el cubo del parametro k.*/
{
    return(K*K*K);
}
