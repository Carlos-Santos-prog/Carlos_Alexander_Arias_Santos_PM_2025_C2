#include <stdio.h>
#include <stdlib.h>

/* Lluvias
 el prograa permite calcular el promedio mensual de las lluvias caidas en 3
 regiones importantes del pais. determina tambien cual es la region
 con mayor promedio de lluvia anual. */

 void mayor(float, float, float);

 int main(void)
 {
     int I;
     float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
     for(I = 1; I <= 12; I++)
     {
         printf("\n\ningresa las lluvias del mes %d", I);
         printf("\nreligiones golfo, pacifico y caribe: ");
         scanf("%f %f %f", &GOL, &PAC, &CAR);
         AGOL += GOL;
         APAC += PAC;
         ACAR += CAR;

    }
    printf("\n\npromedio de lluvias region golfoo: %6.2f", (AGOL / 12));
    printf("\n\npromedio de lluvias region golfoo: %6.2f", (APAC / 12));
    printf("\n\npromedio de lluvias region golfoo: %6.2f", (ACAR / 12));
    mayor(AGOL, APAC, ACAR);
    return 0;
 }

 void mayor(float R1, float R2, float R3)
 {
     if (R1 > R2)
        if (R1 > R3)
        printf("\nRegion con mayor promedio: region golfo. promedio:  %6.2f", R1 / 12);
     else
        printf("\nRegion con mayor promedio: region caribe. promedio: %6.2f", R3 / 12);
     else
        if (R2 > R3)
        printf("\nRegion con mayor promedio: region pacifico. promedio: %6.2f", R2 / 12);
     else
        printf("\nRegion con mayor promedio: region caribe. promedio: %6.2f", R3 / 12);

 }
