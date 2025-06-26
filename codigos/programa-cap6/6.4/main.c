#include <stdio.h>

/* Simétrico.
   El programa, al recibir como dato un arreglo bidimensional cuadrado,
   determina si el mismo es simétrico. */
const int MAX = 100;
void Lectura(int A[][MAX], int T);
int Simetrico(int A[][MAX], int T);

int main(void)
{
    int MAT[MAX][MAX], N, RES;

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &N);
    }
    while (N > MAX || N < 1);

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es simétrico");
    else
        printf("\nEl arreglo bidimensional no es simétrico");

    return 0;
}

void Lectura(int A[][MAX], int T)
/* Lee un arreglo bidimensional cuadrado de T filas y T columnas. */
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        for (J = 0; J < T; J++)
        {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

int Simetrico(int A[][MAX], int T)
/* Devuelve 1 si el arreglo es simétrico, 0 en caso contrario. */
{
    int I = 0, J, F = 1;
    while (I < T && F)
    {
        J = 0;
        while (J < I && F)
        {
            if (A[I][J] == A[J][I])
                J++;
            else
                F = 0;
        }
        I++;
    }
    return F;
}
