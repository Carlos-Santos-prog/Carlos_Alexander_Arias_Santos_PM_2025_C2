#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int x = 3, y = 7, z[5] = {2, 4, 6, 8, 10};
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);
    int *ix;
    ix = &x;
    y = *ix;
    *ix = 1;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    ix = &z[2];
    y = *ix;
    *ix = 15;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    x = *ix + 5;
    *ix = *ix - 5;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    ++*ix;
    *ix += 1;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    x = *(ix + 1);
    y = *ix;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);


    ix = ix + 1;
    y = *ix;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    ix = ix + 4;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);

    ix = &x;
    ix = ix + 1;
    x = *ix;
    printf("\nx = %d \t y = %d \t z[0] = %d \t z[1] = %d \t z[2] = %d \t z[3] = %d \t z[4] = %d", x, y, z[0],z[1],z[2],z[3],z[4]);



}
