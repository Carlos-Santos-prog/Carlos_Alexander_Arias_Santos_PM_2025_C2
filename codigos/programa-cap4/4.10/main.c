#include <stdio.h>
#include <stdlib.h>

/*Multiplo
el programa al recibir como datos numeros enteros, determina si el segundo es multiplo del primero*/

int multiplo(int, int);

void main(void)
{
    int NU1, NU2, RES;
    printf("\nIngresa los dos numeros:  ");
    scanf("%d %d", &NU1, &NU2);
    RES = multiplo(NU1, NU2);

     if(RES)
        printf("\nEl segundo numero es multiplo del primero");
     else
        printf("\nEl segundo numero no es multiplo del primero");

}
int multiplo(int N1, int N2)
/* Esta funcion determina si N2 es multiplo de N1 */
{
    int RES;
    if ((N2 % N1) == 0)
        RES = 1;
    else
        RES = 0;
    return RES;
}
