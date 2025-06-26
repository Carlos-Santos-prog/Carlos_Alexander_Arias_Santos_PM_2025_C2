#include <stdio.h>

/* Lluvias.
   El programa, al recibir como dato un arreglo tridimensional que contiene
   informacion sobre lluvias, genera informacion estadistica. */
const int PRO = 24;
const int MES = 12;
const int ANO = 10;
void Lectura(float A[][MES][ANO], int F, int C, int P);
void Funcion1(float A[][MES][ANO], int F, int C, int P);
void Funcion2(float A[][MES][ANO], int F, int C, int P);
void Funcion3(float A[][MES][ANO], int F, int C, int P);

int main(void)
{
    float LLU[PRO][MES][ANO];

    Lectura(LLU, PRO, MES, ANO);
    Funcion1(LLU, PRO, MES, ANO);
    Funcion2(LLU, PRO, MES, ANO);
    Funcion3(LLU, 18, MES, 5);

    return 0;
}

void Lectura(float A[][MES][ANO], int F, int C, int P)
/* Lee un arreglo tridimensional de tipo real de F provincias,
   C meses y P anos. */
{
    int i, j, k;
    for (k = 0; k < P; k++)
        for (i = 0; i < F; i++)
            for (j = 0; j < C; j++)
            {
                printf("Ano: %d Provincia: %d Mes: %d: ", k + 1, i + 1, j + 1);
                scanf("%f", &A[i][j][k]);
            }
}

void Funcion1(float A[][MES][ANO], int F, int C, int P)
/* Provincia con mayor registro promedio en los ultimos P anos. */
{
    int i, j, k, idx = 0;
    float maxProm = -1.0f;
    for (i = 0; i < F; i++)
    {
        float sum = 0.0f;
        for (k = 0; k < P; k++)
            for (j = 0; j < C; j++)
                sum += A[i][j][k];
        float prom = sum / (P * C);
        if (prom > maxProm)
        {
            maxProm = prom;
            idx = i;
        }
    }
    printf("\nProvincia con mayor registro de lluvias: %d", idx + 1);
    printf("\nRegistro: %.2f", maxProm);
}

void Funcion2(float A[][MES][ANO], int F, int C, int P)
/* Provincia con menor registro promedio en el ultimo ano. */
{
    int i, j, idx = 0;
    float minProm = 1e9f;
    for (i = 0; i < F; i++)
    {
        float sum = 0.0f;
        for (j = 0; j < C; j++)
            sum += A[i][j][P - 1];
        float prom = sum / C;
        if (prom < minProm)
        {
            minProm = prom;
            idx = i;
        }
    }
    printf("\n\nProvincia con menor registro anual en el ultimo ano: %d", idx + 1);
    printf("\nRegistro anual: %.2f", minProm);
}

void Funcion3(float A[][MES][ANO], int F, int C, int P)
/* Mes con mayor registro de lluvias en la provincia F y ano P. */
{
    int j, idx = 0;
    float maxVal = -1.0f;
    for (j = 0; j < C; j++)
    {
        float val = A[F - 1][j][P - 1];
        if (val > maxVal)
        {
            maxVal = val;
            idx = j;
        }
    }
    printf("\n\nMes con mayor registro en provincia %d, ano %d: %d", F, P, idx + 1);
    printf("\nLluvias: %.2f", maxVal);
}
