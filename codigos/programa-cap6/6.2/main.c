#include <stdio.h>

/* Suma matrices.
   El programa, al recibir como datos dos arreglos bidimensionales del mismo
   tamaño, calcula la suma de ambos y la almacena en un tercer arreglo
   bidimensional. */
const int MAX = 50;

/* Prototipo de funciones. */
void Lectura(int A[][MAX], int F, int C);
void Suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C);
void Imprime(int A[][MAX], int F, int C);

int main(void)
{
    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
    int FIL, COL;

    do
    {
        printf("Ingrese el numero de filas de los arreglos: ");
        scanf("%d", &FIL);
    }
    while (FIL > MAX || FIL < 1);

    do
    {
        printf("Ingrese el numero de columnas de los arreglos: ");
        scanf("%d", &COL);
    }
    while (COL > MAX || COL < 1);

    printf("\nLectura del Arreglo MA\n");
    Lectura(MA, FIL, COL);

    printf("\nLectura del Arreglo MB\n");
    Lectura(MB, FIL, COL);

    Suma(MA, MB, MC, FIL, COL);

    printf("\nImpresion del Arreglo MC\n");
    Imprime(MC, FIL, COL);

    return 0;
}

void Lectura(int A[][MAX], int F, int C)
/* La funcion Lectura se utiliza para leer un arreglo bidimensional entero de F
   filas y C columnas. */
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

void Suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C)
/* La funcion Suma se utiliza para sumar los arreglos y almacenar el resultado
   en un tercer arreglo bidimensional. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            M3[I][J] = M1[I][J] + M2[I][J];
        }
    }
}

void Imprime(int A[][MAX], int F, int C)
/* La funcion Imprime se utiliza para escribir un arreglo bidimensional de tipo
   entero de F filas y C columnas. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("\nElemento %d %d: %d", I, J, A[I][J]);
        }
    }
}
