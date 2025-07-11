#include <stdio.h>

/* Archivos con variables enteras y reales.
   El programa lee de un archivo el número de alumnos (N), la matrícula y las cinco
   calificaciones de cada uno, e imprime en pantalla la matrícula y el promedio de cada alumno. */
void main(void)
{
    int i, j, n, mat;
    float cal, suma;
    FILE *ar;

    if ((ar = fopen("arc8.txt", "r")) != NULL)
    /* Se abre el archivo para lectura y se verifica si se abrió correctamente. */
    {
        fscanf(ar, "%d", &n);  /* Se lee el número de alumnos en el archivo. */

        for (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat); /* Se lee la matrícula de cada alumno. */
            suma = 0;

            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal); /* Se lee cada calificación. Se asigna a la variable cal. */
                suma += cal;    /* Se acumulan las calificaciones. */
            }

            printf("Matrícula %d: Promedio %.2f\n", mat, suma / 5);
            /* Se imprime la matrícula y el promedio de cada alumno. */
        }

        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}
