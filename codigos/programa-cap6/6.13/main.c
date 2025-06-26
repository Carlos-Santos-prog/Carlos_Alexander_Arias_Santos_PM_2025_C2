#include <stdio.h>

/* Empresa textil.
   El programa, al recibir un arreglo tridimensional que contiene informacion
   sobre las ventas mensuales de tres departamentos en los ultimos ocho anos,
   genera informacion estadistica valiosa para la empresa. */
const int MES = 12;
const int DEP = 3;
const int ANO = 8;

/* Prototipos de funciones. */
void Lectura(float A[][DEP][ANO], int F, int C, int P);
void Funcion1(float A[][DEP][ANO], int F, int C, int P);
void Funcion2(float A[][DEP][ANO], int F, int C, int P);
void Funcion3(float A[][DEP][ANO], int F, int C, int P);

int main(void)
{
    float PRO[MES][DEP][ANO];

    Lectura(PRO, MES, DEP, ANO);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, ANO);
    Funcion3(PRO, MES, DEP, ANO);

    return 0;
}

void Lectura(float A[][DEP][ANO], int F, int C, int P)
/* Lee un arreglo tridimensional de tipo real de F filas, C columnas y P planos. */
{
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
            {
                printf("Ano: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][DEP][ANO], int F, int C, int P)
/* Obtiene las ventas totales de la empresa en el segundo ano. */
{
    int I, J;
    float SUM = 0.0f;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];
    printf("\n\nVentas totales de la empresa en el segundo ano: %.2f", SUM);
}

void Funcion2(float A[][DEP][ANO], int F, int C, int P)
/* Obtiene el departamento que tuvo las mayores ventas en el ultimo ano. */
{
    int I, J;
    float SUM1 = 0.0f, SUM2 = 0.0f, SUM3 = 0.0f;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
        {
            switch (J)
            {
                case 0: SUM1 += A[I][J][P - 1]; break;
                case 1: SUM2 += A[I][J][P - 1]; break;
                case 2: SUM3 += A[I][J][P - 1]; break;
            }
        }
    if (SUM1 > SUM2 && SUM1 > SUM3)
    {
        printf("\n\nDepartamento con mayores ventas en el ultimo ano: Hilos");
        printf("  Ventas: %.2f", SUM1);
    }
    else if (SUM2 > SUM3)
    {
        printf("\n\nDepartamento con mayores ventas en el ultimo ano: Lanas");
        printf("  Ventas: %.2f", SUM2);
    }
    else
    {
        printf("\n\nDepartamento con mayores ventas en el ultimo ano: Licra");
        printf("  Ventas: %.2f", SUM3);
    }
}

void Funcion3(float A[][DEP][ANO], int F, int C, int P)
/* Obtiene el departamento, mes y ano con la mayor venta e imprime el monto. */
{
    int K, I, J, DE = 0, ME = 0, AN = 0;
    float VEN = -1.0f;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
                if (A[I][J][K] > VEN)
                {
                    VEN = A[I][J][K];
                    DE = J;
                    ME = I;
                    AN = K;
                }
    printf("\n\nDepartamento: %d\tMes: %d\tAno: %d", DE + 1, ME + 1, AN + 1);
    printf("\tVentas: %.2f", VEN);
}
