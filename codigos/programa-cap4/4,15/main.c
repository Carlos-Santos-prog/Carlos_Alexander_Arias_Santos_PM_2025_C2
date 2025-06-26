#include <stdio.h>
#include <stdlib.h>

/* productoria
el programa calcula la prodcutoria de los n primeros numeros naturales */

int Productoria(int);

int main()
{
    int NUM;

    do{
        printf("ingresa el numero del cual quieres calcular la productoria:  ");
        scanf("%d", &NUM);
    }
    while(NUM > 100 || NUM < 1);
    printf("\nLa productoria de %d es: %d", NUM, Productoria(NUM));
    return 0;
}

int Productoria(int N)
{
    int I, PRO = 1;
    for(I = 1; I <= N; I++)
        PRO *= I;
    return PRO;
}
