#include <stdio.h>
#include <stdlib.h>

int main()
{     int N;
    float v1_total = 0, v2_total = 0, v3_total = 0, v4_total = 0;
    float v1, v2, v3, v4, total_anual;
     printf("Ingrese el numero de años: ", N);
     scanf("%d", &N);

     for(int I =1 ; I <=N; I++){
     printf("\nAnos %d:\n", I);

     printf("Litros de vino tipo 1: ");
     scanf("%f", &v1);

     printf("litros de vino tipo 2: ");
     scanf("%f", &v2);

     printf("litros de vino tipo 3: ");
     scanf("%f", &v3);

     printf("litros de vino tipo 4: ");
     scanf("%f", &v4);

     v1_total += v1;
     v2_total += v2;
     v3_total += v3;
     v4_total += v4;

     total_anual = v1 + v2 + v3 + v4;
     printf("Total producido en el ano %d: %.2f litros\n", I, total_anual);
     }
     printf("\nTotal producido por tipo de vino en todoos los anos:\n");
     printf("Tipo 1: %.2f litros\n", v1_total);
     printf("Tipo 2: %.2f litros\n", v2_total);
     printf("Tipo 3: %.2f litroos\n", v3_total);
     printf("Tipo 4: %.2f litros\n", v4_total);
      return 0;
}

