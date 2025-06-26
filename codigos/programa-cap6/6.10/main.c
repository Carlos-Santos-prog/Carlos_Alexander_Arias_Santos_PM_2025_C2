#include <stdio.h>

const int MAX = 50;
void Cuadrado(int A[][MAX], int N);
void Imprime(int A[][MAX], int N);

int main(void)
{
    int CMA[MAX][MAX], TAM;

    do
    {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1 || (TAM % 2 == 0));

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N)
{
    int I, FIL = 0, COL = N / 2, NUM, MAXNUM = N * N;
    for (I = 1; I <= MAXNUM; I++)
    {
        A[FIL][COL] = I;
        if (I % N != 0)
        {
            FIL = (FIL - 1 + N) % N;
            COL = (COL + 1) % N;
        }
        else
        {
            FIL = (FIL + 1) % N;
        }
    }
}

void Imprime(int A[][MAX], int N)
{
    int I, J;
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            printf("%4d", A[I][J]);
        }
        printf("\n");
    }
}

