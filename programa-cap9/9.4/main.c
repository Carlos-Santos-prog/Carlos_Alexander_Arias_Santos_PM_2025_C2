#include <stdio.h>

/* Archivos y cadenas de caracteres.
   El programa lee cadenas de caracteres de un archivo. */
int main(void)
{
    char cad[50];
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL)
    /* Se abre el archivo para lectura y se verifica si se abrió correctamente. */
    {
        while (!feof(ap))
        /* Mientras no se detecte el fin de archivo se siguen leyendo cadenas de
         caracteres. */
        {
            fgets(cad, 50, ap);
            /* Observa que la instrucción para leer cadenas requiere de tres
             argumentos. */
            puts(cad);       /* Despliega la cadena en la pantalla. */
        }
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");

    return 0;
}
