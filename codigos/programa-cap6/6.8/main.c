#include <stdio.h>

/* Traspuesta.
   El programa calcula la traspuesta de una matriz. */
const int MAX = 50;
void Lectura(int A[][MAX], int F, int C);
void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C);
void Imprime(int A[][MAX], int F, int C);

int main(void)
{
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;

    do
    {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &FIL);
    }
    while (FIL > MAX || FIL < 1);

    do
    {
        printf("Ingrese el numero de columnas de la matriz: ");
        scanf("%d", &COL);
    }
    while (COL > MAX || COL < 1);

    Lectura(MAT, FIL, COL);
    Traspuesta(MAT, TRA, FIL, COL);
    Imprime(TRA, COL, FIL);

    return 0;
}

void Lectura(int A[][MAX], int F, int C)
/* Lee una matriz de tipo entero de F filas y C columnas. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C)
/* Calcula la traspuesta de M1 y la almacena en M2. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            M2[J][I] = M1[I][J];
        }
    }
}

void Imprime(int A[][MAX], int F, int C)
/* Imprime una matriz de tipo entero de F filas y C columnas. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("\nElemento %d %d: %d", I + 1, J + 1, A[I][J]);
        }
    }
}
