#include <stdio.h>
#include <stdlib.h>

/* Combinacion de variables globales y locales, parametros por valor
y por referencia */
int A, B, C, D;     /* variables globales */

void funcion1(int *, int *);
/* prototipo de funcion . observa que los dos parametros soon por referencia */

int funcion2(int, int *);

int main(void)
{
    int a;
    a = 1;
    B = 2;
    C = 3;
    D = 4;
    printf("\n %d %d %d", a, B, C, D);
    funcion1(&B, &C);
    printf("\n &d %d %d", a, B, C, D);
    a = funcion2(C, &D);
    printf("\n %d %d %d", a, B, C, D);
    return 0;
}

void funcion1(int *B, int *C)
{
    int d;
    A = 5;
     d = 3;
    (*B)++;
    (*C) += 2;
    printf("\n %d %d %d", A, *B, *C, d);

}

int funcion2(int c, int *d)
{
    int b;
    A++;
    b = 7;
    c += 3;
    (*d) += 2;
    printf("\n %d %d %d", A, b, c, *d);
    return c;
}
