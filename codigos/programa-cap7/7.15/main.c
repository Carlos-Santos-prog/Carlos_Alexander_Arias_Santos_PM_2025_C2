#include <stdio.h>
#include <ctype.h>

/* Decodifica.
   El programa decodifica una cadena de caracteres compuesta por dígitos y
   letras. Cada dígito indica cuántas veces se repite la letra que le sigue. */
void interpreta(char *cadena);  /* Prototipo de función. */

int main(void)
{
    char cad[50];

    /* Leer la línea de texto */
    printf("Ingrese la cadena de caracteres: ");
    if (fgets(cad, sizeof(cad), stdin) == NULL)
        return 1;  /* Salir si hay error de lectura */

    interpreta(cad);

    return 0;
}

void interpreta(char *cadena)
/* Esta función recorre la cadena; cuando encuentra un dígito n seguido de
   una letra L, imprime L n veces. */
{
    int i = 0, j, rep;

    while (cadena[i] != '\0')
    {
        /* Si el caracter actual es un dígito... */
        if (isdigit((unsigned char)cadena[i]))
        {
            /* Convertir el carácter dígito a número entero */
            rep = cadena[i] - '0';

            /* Si el siguiente carácter es una letra, repetirla rep veces */
            if (isalpha((unsigned char)cadena[i + 1]))
            {
                for (j = 0; j < rep; j++)
                {
                    putchar(cadena[i + 1]);
                }
            }
        }
        i++;
    }

    putchar('\n');  /* Salto de línea al final */
}
