#include <stdio.h>
#include <string.h>

/* Reemplaza palabras.
   El programa lee cadenas de caracteres de un archivo y cada vez que
   encuentra la palabra México escrita en forma incorrecta —la primera con
   minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
   archivo. */
void cambia(FILE *ap1, FILE *ap2);

int main(void)
{
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");    /* Se abre el archivo arc.txt para lectura. */
    ap = fopen("arc1.txt", "w");   /* Se abre el archivo arc1.txt para escritura. */

    if (ar != NULL && ap != NULL)
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
        printf("No se pueden abrir los archivos\n");

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
/* Esta función reemplaza en cada línea la palabra "méxico" escrita
   con minúscula —la primera letra— por su forma correcta ("México")
   y escribe la línea corregida en el archivo ap2. */
{
    char cad[256], cad1[256], aux[256];
    char *cad2;
    int i, j, k;

    while (fgets(cad, sizeof cad, ap1) != NULL)
    {
        /* Copiamos la línea original a cad1 para trabajar sobre ella */
        strcpy(cad1, cad);

        /* Buscamos la subcadena "méxico" */
        cad2 = strstr(cad1, "méxico");

        while (cad2 != NULL)
        {
            /* Cambiamos la primera letra por mayúscula */
            cad2[0] = 'M';

            /* Calculamos longitudes para reconstruir la cadena */
            i = strlen(cad1);
            j = strlen(cad2);
            k = i - j;  /* número de caracteres antes de "México" */

            if (k > 0)
            {
                /* Copiamos el prefijo previo a "México" */
                strncpy(aux, cad1, k);
                aux[k] = '\0';

                /* Concatena desde "México" hasta el final */
                strcat(aux, cad2);

                /* Restauramos en cad1 */
                strcpy(cad1, aux);
            }
            else
            {
                /* Si "méxico" está al inicio, copiamos sólo desde cad2 */
                strcpy(cad1, cad2);
            }

            /* Continuamos buscando más ocurrencias */
            cad2 = strstr(cad1 + k + 1, "méxico");
        }

        /* Escribimos la línea corregida en el segundo archivo */
        fputs(cad1, ap2);
    }
}
