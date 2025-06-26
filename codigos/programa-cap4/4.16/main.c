#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Temperaturas.
el programa recibe como datos 24 numeros reales que representa las temperaturas
en el exterior en un periodo de 24 horas. calcula el promedio del dia y las temperatura maxima y minima
con la hora en que se registraron */

void Acutem(float);
void Maxima(float, int);
void Minima(float, int);

float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX ;
int HMIN;

void main(void)
{
    float TEM;
    int I;
    for(I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);

    }
    printf("\nPromedio del dia: %5.2f", (ACT / 24));
    printf("\nPromedio del dia: %5.2f \tHora: %d", MAX, HMAX);
    printf("\nPromedio del dia: %5.2f  \tHora: %d", MIN, HMIN);

}
void Acutem(float T)
{
    ACT += T;
}

void Maxima(float T, int H)
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;

    }
}

void Minima(float T, int H)
{
    if(MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
