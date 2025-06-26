#include <stdio.h>
#include <stdlib.h>

/* paso de una funcion como parametro por referencia */

int Suma(int X, int Y)
/* La funcion suma regresa la suma de los parametros de tipo entero X y Y */
{
    return X+Y;

}

int Resta(int X, int Y)
{
    return X-Y;
}
int Control(int (*apf) (int, int), int X, int Y)
{
    int RES;
    RES = (*apf)(X,Y);
    return (RES);
}
void main(void)
{
    int R1, R2;
    R1 = Control(Suma, 15, 5); /* se pasa como parametro la funcion suma */
    R2 = Control(Resta, 10, 4); /* se pasa como parametro la funcion resta */
    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);
}
