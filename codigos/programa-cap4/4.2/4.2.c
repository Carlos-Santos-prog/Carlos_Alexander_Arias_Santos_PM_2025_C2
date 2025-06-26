#include <stdio.h>
#include <stdlib.h>
/* Cubo-2.
El programa calcula el cubo de los 10 primeros numeros naturales con la ayuda de una funcion. */

int cubo(void); /*Prototipo de funcion. */
int I;          /* Variable global. */

void main(void)
{
   int CUB;
   for (I = 1; I<= 10; I++)
   {
       CUB = cubo();  /* Llamada a la funcion cubo. */
       printf("\nEl cubo de %d es:  %d", I, CUB);
   }
}
int cubo(void)  /* Declaracion de la funcion. */
/* La funcion calcula el cubo de la variable local I. */
{
    int I = 2;   /* variable local entera I con el mismoo nombre que la variable global. */
    return(I*I*I);
}
