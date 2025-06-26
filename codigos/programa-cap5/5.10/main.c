#include <stdio.h>

/* Búsqueda secuencial en arreglos ordenados en forma creciente. */
const int MAX = 100;
void Lectura(int A[], int T);    /* Prototipos de funciones. */
int Busca(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);
    /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);
    /* Se llama a la función que busca en el arreglo. */

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T
   elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Problemas resueltos 197, 5 */

int Busca(int A[], int T, int E)
/* Esta función se utiliza para localizar el elemento E en el arreglo
   unidimensional A. Si se encuentra, la función regresa la posición
   correspondiente. En caso contrario regresa 0. */
{
    int I = 0;
    while (I < T && E >= A[I])
    {
        if (A[I] == E)
            return I + 1;  /* Ajuste para que las posiciones comiencen en 1 */
        I++;
    }
    return 0;
}
