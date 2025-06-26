#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio.
   El programa, al recibir como datos varias cadenas de caracteres que
   contienen reales, los suma y obtiene el promedio de los mismos. */
int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0f;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();

    while (c == 'S')
    {
        printf("\nIngrese la cadena de caracteres: ");
        fflush(stdin);
        gets(cad);
        /* gets lee una línea de texto hasta '\n' y la almacena en cad */

        i++;
        sum += atof(cad);
        /* La función atof convierte una cadena de caracteres que contiene números
           reales a un valor de tipo double. Si la cadena no contiene números o
           comienza con otro caracter, regresa 0 o el valor queda indefinido. */

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
    }

    printf("\nSuma:      %.2f", sum);
    printf("\nPromedio:  %.2f", sum / i);

    return 0;
}
