#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i, num, cue = 0;
    int arre[100];
    for(i = 0; i < 100; i++)
    {
        printf("ingrese el elemento %d del arreglo: ", i+1);
        scanf("%d", &arre[i]);

    }
    printf("\n\ningrese el numero que se va a buscar en el arreglo: ");
    scanf("%d", &num);
    for(i = 0; i < 100; i++)
        if (arre[i] == num)


        cue++;
    printf("\n\nel %d se encuentra %d veces en el arreglo", num, cue);
}
