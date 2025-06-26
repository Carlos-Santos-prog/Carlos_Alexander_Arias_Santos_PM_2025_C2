4.1


#include <stdio.h>  // Necesario para printf

// Prototipo de función
int cubo(int x);

int main(void)
{
    int i, cub;
    for (i = 1; i <= 10; i++)
    {
        cub = cubo(i);
        printf("El cubo de %d es: %d\n", i, cub);
    }

    return 0;  // Buenas prácticas: retornar 0 en main
}

// Definición de la función
int cubo(int x)
{
    return x * x * x;
}
