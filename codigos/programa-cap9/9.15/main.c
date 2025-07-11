#include <stdio.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas.
   El programa, al recibir como dato un archivo formado por cadenas de
   caracteres, determina el número de letras minúsculas y mayúsculas que hay
   en el archivo. */
void minymay(FILE *);             /* Prototipo de función. */

int main(void)
{
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo\n");

    return 0;
}

void minymay(FILE *ap1)
/* Esta función se utiliza para leer cadenas de caracteres de un archivo
   y contar el número de letras minúsculas y mayúsculas que existen en el
   archivo. */
{
    char cad[30];
    int i, mi = 0, ma = 0;

    /* Leer línea por línea */
    while (fgets(cad, sizeof cad, ap1) != NULL)
    {
        i = 0;
        /* Recorrer cada carácter de la línea */
        while (cad[i] != '\0')
        {
            if (islower((unsigned char)cad[i]))
                mi++;
            else if (isupper((unsigned char)cad[i]))
                ma++;
            i++;
        }
    }

    printf("\nNúmero de letras minúsculas: %d\n", mi);
    printf("Número de letras mayúsculas: %d\n", ma);
}
