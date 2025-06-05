#include <stdio.h>
#include <stdlib.h>
int primo(int n);

int main()
{ int A, B, I, MENOR, MAYOR;
printf("Ingresa dos numeros positivos: ");
scanf("%d %d", &A, &B);

if (A < B){
    MENOR = A;
    MAYOR = B;

} else {
  MENOR = B;
  MAYOR = A;
}
  printf("primos gemelos entre %d y %d:\n", MENOR, MAYOR);

  for (I = MENOR; I <= MAYOR - 2; I++){
    if (primo(I) && primo(I + 2)){
        printf("(%d, %d)\n", I, I + 2);

    }
  }
  return 0;


} int primo(int n) {
    int I;
    if (n < 2) return 0;
    for (I = 2; I < n; I++){
        if (n % I == 0)
            return 0;
    }
    return 1;
}
