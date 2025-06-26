#include <stdio.h>
#include <string.h>

void intercambia(char FRA[][30], int n);  /* Prototipo de función. */

int main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea de texto número %d: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);  /* Se lee cada línea de texto dentro del ciclo. */
    }

    printf("\n\n");
    intercambia(FRA, n);

    for (i = 0; i < n; i++)
    {
        printf("Impresión de la línea de texto %d: ", i + 1);
        puts(FRA[i]);
    }

    return 0;
}

void intercambia(char FRA[][30], int n)
/* Esta función intercambia las filas del arreglo. */
{
    int i, j;
    char cad[30];

    j = n - 1;
    for (i = 0; i < n / 2; i++)
    {
        strcpy(cad,     FRA[i]);  /* Guardar la fila i en cad */
        strcpy(FRA[i],  FRA[j]);  /* Mover la fila j a la posición i */
        strcpy(FRA[j],  cad);     /* Copiar cad (antigua fila i) a la posición j */
        j--;                      /* Decrementar j para apuntar a la siguiente fila desde el final */
    }
}
