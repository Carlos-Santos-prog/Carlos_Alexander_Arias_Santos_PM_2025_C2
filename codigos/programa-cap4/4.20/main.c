#include <stdio.h>
#include <stdlib.h>

int f1(int, int *);
int a =3;
int b = 7;
int c = 4;
int d = 2;

void main(void)
{
    a = f1(c, &d);
    printf("\n%d %d %d %d", a, b, c, d);
    c = 3;
    c = f1(a, &c);
    printf("\n%d %d %d %d", a, b, c, d);

}

int f1(int x, int *y)
{
    int a;
    a = x * *y;
    c++;
    b += *y;
    printf("\n%d %d %d %d", a, b, c, d);
    *y--;
    return c;
}
