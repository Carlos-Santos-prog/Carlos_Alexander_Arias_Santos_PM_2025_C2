#include <stdio.h>

/* Cuenta caracteres.
   El programa, al recibir como datos una cadena de caracteres y un caracter,
   cuenta cuántas veces se encuentra el caracter en la cadena. */
int cuenta(char *, char);  /* Prototipo de función. */

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    fflush(stdin);

    printf("\nIngrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);

    printf("\n\n%c se encuentra %d veces en la cadena %s", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
/* Esta función se utiliza para obtener el número de veces que se encuentra
   el caracter en la cadena. */
{
    int i = 0, r = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return r;
}

