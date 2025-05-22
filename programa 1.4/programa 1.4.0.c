#include <stdio.h>
/* Superficie del triangulo.
El programa, al recibir como datos la base y la altura de un triangulo,
calcula su superficie.

BAS, ALT Y SUP: variable de tipo real. */
void main(void)
{
    float BAS, ALT, SUP;
    printf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLa superficie del trianguloo es: %5.2f", SUP);

}
