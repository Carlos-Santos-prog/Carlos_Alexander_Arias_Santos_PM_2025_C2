#include <stdio.h>
#include <ctype.h>

/* Cuenta letras minúsculas y mayúsculas.
   El programa, al recibir como dato una frase, determina el número de letras
   minúsculas y mayúsculas que existen en la frase, y calcula la longitud de la
   cadena sin utilizar la función strlen. */

/* Problema PR7.5
   Escriba un programa en C que, al recibir como dato una cadena de caracteres,
   determine la longitud de la misma sin utilizar la función strlen. */

int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;
    int longitud = 0;

    /* Leer la cadena de caracteres (máximo 50) */
    printf("\nIngrese la cadena de caracteres (máximo 50 caracteres): ");
    gets(cad);

    /* Recorrer la cadena hasta el carácter nulo */
    while (cad[i] != '\0')
    {
        /* Contar letras minúsculas */
        if (islower(cad[i]))
            mi++;
        /* Contar letras mayúsculas */
        else if (isupper(cad[i]))
            ma++;

        /* Incrementar la longitud */
        longitud++;
        i++;
    }

    /* Mostrar resultados */
    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
    printf("\nLongitud de la cadena: %d\n", longitud);

    return 0;
}
