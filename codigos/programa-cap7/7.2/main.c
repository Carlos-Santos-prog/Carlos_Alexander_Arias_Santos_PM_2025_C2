#include <stdio.h>
#include <ctype.h>

/* Funciones para el manejo de caracteres de la biblioteca ctype.h */
int main(void)
{
    char p1;

    /* Verificar si un caracter es un digito */
    printf("\nIngrese un caracter para analizar si este es un digito: ");
    p1 = getchar();                  /* Leer caracter con getchar */
    if (isdigit(p1))                 /* isdigit regresa no cero si es digito */
        printf("%c es un digito\n", p1);
    else
        printf("%c no es un digito\n", p1);
    fflush(stdin);                   /* Limpiar buffer de entrada */

    /* Verificar si un caracter es una letra */
    printf("\nIngrese un caracter para examinar si este es una letra: ");
    p1 = getchar();
    if (isalpha(p1))                 /* isalpha regresa no cero si es letra */
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);
    fflush(stdin);

    /* Verificar si una letra es minuscula */
    printf("\nIngrese un caracter para examinar si este es una letra minuscula: ");
    p1 = getchar();
    if (isalpha(p1))
    {
        if (islower(p1))             /* islower regresa no cero si es minuscula */
            printf("%c es una letra minuscula\n", p1);
        else
            printf("%c no es una letra minuscula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }
    fflush(stdin);

    /* Convertir una letra mayuscula a minuscula */
    printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
    p1 = getchar();
    if (isalpha(p1))
    {
        if (isupper(p1))             /* isupper regresa no cero si es mayuscula */
            printf("%c fue convertida de mayuscula a minuscula\n", tolower(p1));
        else
            printf("%c es una letra minuscula\n", p1);
    }
    else
    {
        printf("%c no es una letra\n", p1);
    }

    return 0;                        /* Termina programa correctamente */
}
