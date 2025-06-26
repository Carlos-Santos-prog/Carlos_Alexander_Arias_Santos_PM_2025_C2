#include <stdio.h>

int main(void)
{
    /* Asignación de cadenas literales y arreglos de caracteres */
    char *cad0   = "Buenos dias";           /* Apuntador a cadena literal */
    char cad1[20] = "Hola";                 /* Arreglo con espacio para 20 caracteres */
    char cad2[]   = "Mexico";               /* Arreglo dimensionado automáticamente */
    char cad3[]   = {'B','i','e','n','v','e','n','i','d','o','\0'};  /* Inicialización manual */

    /* Arreglos para lectura de cadenas */
    char cad4[20];
    char cad5[20];
    char cad6[20];

    char p;     /* Variable temporal para getchar */
    int i = 0;  /* Índice para cad6 */

    /* Mostrar cad0 con puts */
    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    /* Mostrar cad1 con printf y %s */
    printf("\nLa cadena cad1 es: %s\n", cad1);

    /* Mostrar cad2 con puts */
    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    /* Mostrar cad3 con puts */
    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    /* Leer una línea completa con gets */
    printf("\nIngrese una linea de texto (gets):\n");
    gets(cad4);               /* gets lee hasta '\n' */
    printf("La cadena cad4 es: ");
    puts(cad4);

    /* Leer una palabra con scanf */
    fflush(stdin);            /* Limpiar buffer */
    printf("\nIngrese una palabra (scanf):\n");
    scanf("%19s", cad5);      /* %19s para evitar overflow */
    printf("La cadena cad5 es: %s\n", cad5);

    /* Leer línea caracter por caracter con getchar */
    fflush(stdin);
    printf("\nIngrese una linea de texto (getchar):\n");
    while ((p = getchar()) != '\n' && i < 19) {
        cad6[i++] = p;        /* Almacenar cada caracter */
    }
    cad6[i] = '\0';           /* Terminar con '\0' */
    printf("La cadena cad6 es: ");
    puts(cad6);

    return 0;
}
