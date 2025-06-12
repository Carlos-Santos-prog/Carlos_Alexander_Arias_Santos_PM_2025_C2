#include <stdio.h>
#include <math.h>
/* Pares e impares.
El programma, al recibir como datos N numeros enteros, obtiene la suma  de  los numeros
pares y calcula el proomedio de los impares.

I,N NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;
    printf("Ingrese el numero de datos que se van a procesar:\t");
    scanf("%d", &N);
    if (N > 0)
    {
        for (I= 1; I <= N; I++)
        {
            printf("\nIngrese el numero %d: ", I);
            scanf("%d", &NUM);
            if(NUM)
                if(pow(-1, NUM)>0)
                SPA = SPA + NUM;
            else{
                SIM = SIM + NUM;
                CIM++;
            }
        }
        printf("\n La suma de los numeros pares es:  %d", SPA);
         printf ("\n El promedio de numeros impares es:  %5.2f", (float)(SIM / CIM));


    }
    else
        printf("\n El valor de N es incorrectoo");
}
