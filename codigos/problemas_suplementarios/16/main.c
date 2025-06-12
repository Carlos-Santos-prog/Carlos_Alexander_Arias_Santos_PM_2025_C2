#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x;
    printf("Ingresa un numero entero positivo: ");
    scanf("%d",  &n);

    for (i = 1; i <= n; i++){
        for (x = 1; x <= i; x++){
            printf("%d ", x);
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--){
        for (x = 1; x <= i; x++){
            printf("%d  ", x);
        }
        printf("\n");
    }
    return 0;
}
