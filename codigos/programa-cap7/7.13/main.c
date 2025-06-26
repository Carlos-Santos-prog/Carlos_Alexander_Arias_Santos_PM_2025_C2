 #include <stdio.h>
 /* Calcula longitud.
 El programa calcula la longitud de la cadena sin utilizar la función strlen. */
 intcuenta(char *);             /* Prototipo de función. */
 void main(void)
 {
 inti;
 charcad[50];
 printf(”\nIngrese la cadena de caracteres: ”);
 gets(cad);
 i = cuenta(cad);
 printf(”\nLongitud de la cadena: %d”, i);
 }
 intcuenta(char *cadena)
 /* La función calcula la longitud de la cadena. */
 {
 int c = 0;
 while(!cadena[c] == ‘\0’)
 c++;
 return (c);
 }
