#include <stdio.h>

/* Funciones para el manejo de caracteres de la biblioteca stdio.h */
int main(void)
{
    char p1, p2, p3 = '$';  /* p1 y p2 para lectura de entrada, p3 inicializado con '$' */

    /* Leer un caracter con getchar y mostrarlo con putchar */
    printf("\nIngrese un caracter: ");
    p1 = getchar();         /* Captura el caracter ingresado */
    putchar(p1);            /* Imprime el caracter capturado */
    printf("\n");

    /* Limpiar el búfer de entrada antes de la siguiente lectura */
    fflush(stdin);

    /* Mostrar el caracter almacenado en p3 */
    printf("\nEl caracter p3 es: ");
    putchar(p3);            /* Imprime el valor literal '$' */
    printf("\n");

    /* Leer un segundo caracter usando scanf("%c") */
    printf("\nIngrese otro caracter: ");
    fflush(stdin);          /* Limpiar el búfer de entrada nuevamente */
    scanf("%c", &p2);       /* Captura el siguiente caracter en p2 */
    printf("%c\n", p2);     /* Imprime el caracter almacenado en p2 */

    return 0;               /* Indica terminación exitosa del programa */
}
