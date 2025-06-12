#include <stdio.h>
#include <stdlib.h>

int main()
{
    float L1, L2, L3, L4, L5, L6;
    int CLA, CAN;
    int B1 = 0, B2 = 0, B3=0, B4=0, B5=0, B6=0;
    float MONTO, TOTAL =0;

    printf("Ingrese el precio de la localidad 1: ");
    scanf("%f", &L1);
    printf("Ingrese el precio de la localidad 2: ");
    scanf("%f", &L2);
    printf("Ingrese el precio de la localidad 3: ");
    scanf("%f", &L3);
    printf("Ingrese el precio de la localidad 4: ");
    scanf("%f", &L4);
    printf("Ingrese el precio de la localidad 5: ");
    scanf("%f", &L5);
    printf("Ingrese el precio de la localidad 6: ");
    scanf("%f", &L6);

    while(1){
        printf("\nTipo de localidad (1-6) y cantidad de boletos (0 0 para salir): ");
        scanf("%d %d", &CLA, &CAN);
        if (CLA == 0 && CAN == 0)
            break;
        switch (CLA){
        case 1: MONTO = L1 * CAN;
        B1 += CAN;
        break;

        case 2: MONTO = L2 * CAN;
        B2 += CAN;
        break;

        case 3: MONTO = L3 * CAN;
        B3 += CAN;
        break;

        case 4: MONTO = L4 * CAN;
        B4 += CAN;

        case 5:  MONTO = L5 * CAN;
        B5 += CAN;
        break;

        case 6: MONTO = L6 * CAN;
        B6 += CAN;
        break;

        default:
            printf("Tipo de localidad invalido.\n");
            continue;
        }
        printf("Monto de la venta: $%.2f\n", MONTO);
        TOTAL += MONTO;
    }
    printf("\nResumen de ventas:\n");
    printf("Localidad 1: %d boletos\n", B1);
    printf("Localidad 2: %d boletos\n", B2);
    printf("Localidad 3: %d boletos\n", B3);
    printf("Localidad 4: %d boletos\n", B4);
    printf("Localidad 5: %d boletos\n", B5);
    printf("Localidad 6: %d boletos\n", B6);
    printf("Recaudacion total: $%.2f\n", TOTAL);

    return 0;
}
