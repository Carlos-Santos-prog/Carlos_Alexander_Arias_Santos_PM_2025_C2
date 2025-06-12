#include <stdio.h>
#include <stdlib.h>

int main()
{ int I, N, TOTAL;
  printf("numero entero que desea multiplicar:  ", N);
  scanf("%d", &N);

  printf("TABLA DE MULTIPLICAR %d:\n", N);

  for(I=1; I<=10; I++)
{
  printf("%d x %d = %d\n", N,I , N*I);
  TOTAL+= N*I;
}
  printf("TOTAL DE LOS NUMEROS MULTIPLICADOS %d: ", TOTAL);

}
