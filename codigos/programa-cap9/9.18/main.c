#include <stdio.h>

/* Mezcla.
   El programa mezcla, respetando el orden, dos archivos que se encuentran
   ordenados en forma ascendente considerando la matrícula de los alumnos. */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2);

int main(void)
{
    FILE *ar, *ar1, *ar2;

    ar  = fopen("arc9.dat",  "r");
    ar1 = fopen("arc10.dat", "r");
    ar2 = fopen("arc11.dat", "w");

    if (ar != NULL && ar1 != NULL && ar2 != NULL)
    {
        mezcla(ar, ar1, ar2);
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
        printf("No se pueden abrir los archivos\n");

    return 0;
}

/* Esta función mezcla, respetando el orden, dos archivos que se encuentran
   ordenados en función de la matrícula. */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    int mat, mat1, i;
    int leido_ar, leido_ar1;
    float ca[3], ca1[3];

    /* Leer primer registro de ambos archivos */
    leido_ar = fscanf(ar,  "%d", &mat);
    if (leido_ar == 1)
        for (i = 0; i < 3; i++)
            fscanf(ar, "%f", &ca[i]);

    leido_ar1 = fscanf(ar1, "%d", &mat1);
    if (leido_ar1 == 1)
        for (i = 0; i < 3; i++)
            fscanf(ar1, "%f", &ca1[i]);

    /* Mezclar hasta que uno de los archivos llegue a su fin */
    while (leido_ar == 1 && leido_ar1 == 1)
    {
        if (mat < mat1)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca[i]);
            fputs("\n", ar2);

            leido_ar = fscanf(ar, "%d", &mat);
            if (leido_ar == 1)
                for (i = 0; i < 3; i++)
                    fscanf(ar, "%f", &ca[i]);
        }
        else
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca1[i]);
            fputs("\n", ar2);

            leido_ar1 = fscanf(ar1, "%d", &mat1);
            if (leido_ar1 == 1)
                for (i = 0; i < 3; i++)
                    fscanf(ar1, "%f", &ca1[i]);
        }
    }

    /* Si quedan registros en el primer archivo */
    while (leido_ar == 1)
    {
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca[i]);
        fputs("\n", ar2);

        leido_ar = fscanf(ar, "%d", &mat);
        if (leido_ar == 1)
            for (i = 0; i < 3; i++)
                fscanf(ar, "%f", &ca[i]);
    }

    /* Si quedan registros en el segundo archivo */
    while (leido_ar1 == 1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca1[i]);
        fputs("\n", ar2);

        leido_ar1 = fscanf(ar1, "%d", &mat1);
        if (leido_ar1 == 1)
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &ca1[i]);
    }
}
