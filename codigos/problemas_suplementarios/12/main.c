#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N, NUM, I, CONTAR;
    int primero = 1;
   printf("Ingrese el numero entero: ");
   scanf("%d", &NUM);

   for (N = 2; N < NUM; N++){
    CONTAR = 0;

    for (I = 1; I <= N; I++){
        if (N % I == 0) {
            CONTAR ++;
        }
    }
    if (CONTAR == 2) {
            if (!primero){
            printf(", ");
            }
        printf("%d", N);
        primero = 0;
    }
   }
   printf("\n");
   return 0;
}
