#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Expresion.
el programa escribe los valores de T, P y Q que sastifacen una determinada expresion. */

int expresion(int, int, int);

int main(void)
{
    int exp, t = 0, p = 0, q = 0;
    exp = expresion(t, p, q);

    while (exp < 5500)
    {
        while (exp < 5500)
        {
            printf("\n t: %d, p: %d, q: %d, resultado: %d", t, p, q, exp);
            q++;
            exp = expresion(t, p, q);

        }
        p++;
        q = 0;
        exp = expresion(t, p, q);
    }
    t++
    p = 0;
    q = 0;
    exp = expresion(t, p, q);
    return 0;
}

int expresion(int t, int p, int q)
{
    int RES;
    RES = 15 * pow(t, 4) + 12 * pow(p, 5) + pow(q, 6);
    return RES;
}
