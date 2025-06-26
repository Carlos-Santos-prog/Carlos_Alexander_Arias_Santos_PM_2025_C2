#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el número de minúsculas y mayúsculas
   que hay en cada cadena. */
void minymay(char *cad);  /* Prototipo de función. */

int main(void)
{
    int i, n;
    char FRA[20][50];
    /* Observa cómo se declara el arreglo unidimensional de cadena de
       caracteres. */

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* Para cada fila se lee la cadena correspondiente. */
        printf("Ingrese la línea %d de texto: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);
    }

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;
}

void minymay(char *cadena)
/* Esta función se utiliza para calcular el número de minúsculas
   y mayúsculas que hay en cada cadena. */
{
    int i = 0, mi = 0, ma = 0;
    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }
    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
