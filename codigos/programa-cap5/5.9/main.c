#include <stdio.h>

/* Búsqueda secuencial en arreglos desordenados. */
const int MAX = 100;
void Lectura(int A[], int T);                /* Prototipos de funciones. */
int Busca(int A[], int T, int K);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posicion %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La funcion Lectura se utiliza para leer un arreglo unidimensional de T
   elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int K)
/* Esta funcion localiza en el arreglo un elemento determinado. Si el elemento
   es encontrado, regresa la posicion correspondiente. En caso contrario, regresa
   0. */
{
    int I = 0, BAN = 0, RES;

    while (I < T && !BAN)
    {
        if (A[I] == K)
            BAN = 1;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;  /* Ajuste para que las posiciones comiencen en 1 */
    else
        RES = 0;

    return RES;
}
