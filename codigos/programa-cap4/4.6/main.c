#include <stdio.h>
#include <stdlib.h>

/* Prueba de parametros por referencia */

int f1 (int *R) ;

/* Prototipo de funcion. El parametro es de tipo entero y por referencia
observa el uso del operador de indireccion */

int main(void)
{
    int I, K = 4;
    for(I=1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
        printf("\nValor de K despues de llamar a la funcion: %d", f1(&K));
        /* Llamada a la funcion f1. Se pasa la direccion de la variable K,
        por medio del operador de direccion: &. */

    }
    return 0;
}
int f1(int *R)
/* La funcion f1 recibe un parametro por referencia. Cada vez que el
parametro se utiliza en la funcion debe ir procedido por el operador de indireccion */
{
    *R += *R;
    return *R;
}
