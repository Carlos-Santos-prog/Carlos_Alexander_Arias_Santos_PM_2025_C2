#include <stdio.h>
#include <stdlib.h>

int main()
{
int n, i, x, esp;
printf("Ingresa uu numero entero positivo: ");
scanf("%d", &n);

for(i = 1; i <= n; i++)
{
    for(x = 1; x <= n - i; x++){
        printf("  ");
    }
    for(x = 1; x <= i; x++){
        printf("%d ", x);

    }
    for(x = i - 1; x >= 1; x--){
        printf("%d ", x);
    }
    printf("\n");
} return 0;
    }

