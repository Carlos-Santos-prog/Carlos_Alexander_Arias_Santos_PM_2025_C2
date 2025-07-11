#include <stdio.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas.
   El programa, al recibir como dato un archivo formado por cadenas de caracteres,
   determina el número de letras minúsculas y mayúsculas que hay en el archivo. */
void minymay(FILE *); /* Prototipo de función. */

int main(void)
{
    int p;
    FILE *ar;

    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(ar);
        /* Se llama a la función minymay. Se pasa el archivo ar como parámetro. */
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");

    return 0;
}

void minymay(FILE *arc)
/* Esta función cuenta el número de minúsculas y mayúsculas que hay en el
   archivo. */
{
    int min = 0, may = 0;
    int p;

    while ((p = fgetc(arc)) != EOF)
    {
        /* Se utiliza fgetc() para leer cada carácter del archivo. */
        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }

    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
}
