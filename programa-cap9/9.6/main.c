#include <stdio.h>

/* Archivos con variables enteras y reales.
   El programa lee datos de alumnos almacenados en un archivo y escribe la
   matrícula y el promedio de cada alumno. */


void procesarAlumnos(FILE *ap);

int main(void)
{
    FILE *ap;

    if ((ap = fopen("arc9.txt", "r")) != NULL)
    /* Se abre el archivo para lectura y se verifica si se abrió correctamente. */
    {
        procesarAlumnos(ap);
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");

    return 0;
}

/* Lee del archivo el número de alumnos (n), luego matrícula y cinco
   calificaciones de cada uno, e imprime matrícula y promedio. */
void procesarAlumnos(FILE *ap)
{
    int i, j, n, mat;
    float cal, pro;

    fscanf(ap, "%d", &n); /* Se lee el valor de n. */
    for (i = 0; i < n; i++)
    {
        fscanf(ap, "%d", &mat); /* Se lee la matrícula de cada alumno. */
        printf("%d\t", mat);
        pro = 0;
        for (j = 0; j < 5; j++)
        {
            fscanf(ap, "%f", &cal);/* Se leen las cinco calificaciones
                                          del alumno. */
            pro += cal;
        }
        printf("\t %.2f\n", pro / 5);   /* Se escribe el promedio de cada alumno. */
    }
}
