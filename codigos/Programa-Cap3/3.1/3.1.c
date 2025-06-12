#include <stdio.h>
#include <stdlib.h>

/* Nomina.
El programa, al recibir los salarios de 15
profesores, obtiene el total de la nomina de la
universidad.

I: variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main(void)
{
   int I;
   float SAL, NOM, total_imp;
   total_imp = 0;
   NOM = 0;
   for(I=1; I<=3; I++)
    {
        printf("\nIngrese el salario del profesor %d:\t", I);
        scanf("%f", &SAL);
        printf("\SALARIO IMPUESTO: %.2f\n", SAL*0.12);
         total_imp += SAL*0.12;
 NOM += SAL;
    }
     printf("\nEl total de la nomina es: %.2f",total_imp);
    printf("\nEl total de la nomina es: %.2f", NOM);

   }
