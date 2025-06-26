#include <stdio.h>

/* Casa de bolsa.
   El programa, al recibir como datos los precios mensuales de sus
   cinco fondos de inversion, ademas del precio de las acciones al 31 de diciembre
   del 2003, genera informacion estadistica importante para la empresa. */
void LecturaM(float A[][12], int F, int C);
void LecturaV(float A[], int N);
void F1(float M[][12], int F, int C, float PRE[], float REN[]);
void F2(float M[][12], int F, int C);
void F3(float REN[], int F);

int main(void)
{
    float FON[5][12], PRE[5], REN[5];

    LecturaM(FON, 5, 12);
    LecturaV(PRE, 5);
    F1(FON, 5, 12, PRE, REN);
    F2(FON, 5, 12);
    F3(REN, 5);

    return 0;
}

void LecturaM(float A[][12], int F, int C)
/* Lee precio mensual de cada fondo de inversion. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("Precio fondo %d mes %d: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
    }
}

void LecturaV(float A[], int N)
/* Lee el precio de las acciones al 31 de diciembre de 2003. */
{
    int I;
    for (I = 0; I < N; I++)
    {
        printf("Precio fondo %d al 31/12/2003: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void F1(float M[][12], int F, int C, float PRE[], float REN[])
/* Calcula el rendimiento anual de cada fondo de inversion. */
{
    int I;
    printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS:\n");
    for (I = 0; I < F; I++)
    {
        REN[I] = (M[I][C-1] - PRE[I]) / PRE[I] * 100.0f;
        printf("Fondo %d: %6.2f%%\n", I + 1, REN[I]);
    }
}

void F2(float M[][12], int F, int C)
/* Calcula el promedio anualizado de las acciones de cada fondo. */
{
    int I, J;
    float SUM, PRO;
    printf("\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS:\n");
    for (I = 0; I < F; I++)
    {
        SUM = 0.0f;
        for (J = 0; J < C; J++)
            SUM += M[I][J];
        PRO = SUM / C;
        printf("Fondo %d: %6.2f\n", I + 1, PRO);
    }
}

void F3(float REN[], int F)
/* Determina el fondo con mejor y peor rendimiento anual. */
{
    int I, best = 0, worst = 0;
    float ME = REN[0], PE = REN[0];
    for (I = 1; I < F; I++)
    {
        if (REN[I] > ME)
        {
            ME = REN[I];
            best = I;
        }
        if (REN[I] < PE)
        {
            PE = REN[I];
            worst = I;
        }
    }
    printf("\nMEJOR Y PEOR FONDO DE INVERSION:\n");
    printf("Mejor fondo: %d  Rendimiento: %6.2f%%\n", best + 1, ME);
    printf("Peor fondo: %d  Rendimiento: %6.2f%%\n", worst + 1, PE);
}
