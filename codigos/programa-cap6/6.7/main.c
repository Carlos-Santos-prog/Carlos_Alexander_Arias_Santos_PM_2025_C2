#include <stdio.h>

/* Fábrica de lácteos.
   El programa, al recibir como datos las ventas mensuales de diferentes
   productos, obtiene información estadística valiosa para la empresa. */
void Lectura1(int A[][12], int F, int C);
void Lectura2(float A[], int N);
void Funcion1(int A[][12], int F, int C, float COS[], float VEN[]);
void Funcion2(float VEN[], int N);
void Funcion3(float VEN[], int N);

int main(void)
{
    int FAB[15][12] = {0};   /* Inicialización en 0 del arreglo FAB */
    float COS[15], VEN[15];

    Lectura1(FAB, 15, 12);
    Lectura2(COS, 15);
    Funcion1(FAB, 15, 12, COS, VEN);
    Funcion2(VEN, 15);
    Funcion3(VEN, 15);

    return 0;
}

void Lectura1(int A[][12], int F, int C)
/* Almacena las ventas mensuales por producto.
   El fin de datos está dado por mes = producto = cantidad = -1. */
{
    int MES, PRO, CAN;
    printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1)
    {
        if (MES >= 1 && MES <= 12 && PRO >= 1 && PRO <= 15)
            A[PRO - 1][MES - 1] += CAN;

        printf("Ingrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N)
/* Lee los precios de venta de los diferentes productos. */
{
    int I;
    for (I = 0; I < N; I++)
    {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][12], int F, int C, float COS[], float VEN[])
/* Calcula el monto de venta anual de cada producto y lo imprime. */
{
    int I, J, SUM;
    printf("\n");
    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];
        VEN[I] = COS[I] * SUM;
        printf("Total de ventas del producto %d: %8.2f\n", I + 1, VEN[I]);
    }
}

void Funcion2(float VEN[], int N)
/* Calcula el monto total de ventas de la fábrica y lo imprime. */
{
    int I;
    float SUM = 0.0f;
    for (I = 0; I < N; I++)
        SUM += VEN[I];
    printf("\nTotal de ventas de la fabrica: %.2f\n", SUM);
}

void Funcion3(float VEN[], int N)
/* Determina el producto más vendido y el monto de sus ventas. */
{
    int I, TPR = 0;
    float MAXV = VEN[0];
    for (I = 1; I < N; I++)
    {
        if (VEN[I] > MAXV)
        {
            MAXV = VEN[I];
            TPR = I;
        }
    }
    printf("\nProducto mas vendido: %d   Ventas: %.2f\n", TPR + 1, MAXV);
}
