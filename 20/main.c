#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, p, r;
    long result;
    printf("valores que cumplen la desigualdad:\n");

    for (t = 1; t <= 10; t ++){
        int t4 = t * t *t *t;

        for (p = 1; p<= 20; p++){
            int p3 = p * p * p;
             for(r =1; r<=5; r++){
             int r5 = r * r * r * r * r;
                result = 7 * t4 - 6 * p3 + 12 * r5;

                if(result < 5850){
                    printf("t = %d, p = %d, r = %d -> %ld\n", t, p, r, result);
                }
             }
        }
    }
    return 0;
}
