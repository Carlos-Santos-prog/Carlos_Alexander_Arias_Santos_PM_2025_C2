#include <stdio.h>
#include <string.h>

/* Cuenta cadenas.
   El programa, al recibir dos cadenas de caracteres, calcula e imprime cuántas
   veces se encuentra la segunda cadena en la primera. */
int main(void)
{
    char cad1[50], cad2[50], cad0[50];
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    gets(cad1);
    printf("\nIngrese la cadena a buscar: ");
    gets(cad2);

    strcpy(cad0, cad1);
    /* Se copia la cadena original a cad0. */

    char *p = strstr(cad0, cad2);
    /* En p se asigna el apuntador a la primera ocurrencia de la cadena cad2.
       Si no existe se almacena NULL. */

    while (p != NULL)
    {
        i++;
        p = strstr(p + 1, cad2);
        /* Se modifica nuevamente la cadena, moviendo el apuntador una
           posicion. */
    }

    printf("\nEl número de veces que aparece la segunda cadena es: %d\n", i);

    return 0;
}
