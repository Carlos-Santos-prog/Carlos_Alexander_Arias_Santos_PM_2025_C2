#include <stdio.h>

/* Incrementa salarios.
   El programa incrementa el salario de los empleados de una empresa
   si sus ventas son superiores al millón de pesos anuales. */
typedef struct {
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *ap);  /* Prototipo de función. */

int main(void)
{
    FILE *ar;

    /* Abrimos el archivo para lectura y escritura binaria */
    if ((ar = fopen("ad5.dat", "r+b")) != NULL)
    {
        incrementa(ar);
        fclose(ar);
    }
    else
        printf("\nEl archivo no se puede abrir\n");

    return 0;
}

/* Esta función incrementa el salario de todos aquellos empleados
   que hayan tenido ventas anuales por más de $1,000,000 y actualiza
   el archivo correspondiente. */
void incrementa(FILE *ap)
{
    empleado emple;
    size_t t = sizeof(emple);  /* Tamaño de la estructura en bytes */
    long bloque;
    float sum;
    int j;

    /* Primera lectura del registro */
    fread(&emple, sizeof(emple), 1, ap);

    while (!feof(ap))
    {
        /* Posición del registro actual en bloques de registros */
        bloque = ftell(ap) / t;

        /* Calculamos las ventas anuales */
        sum = 0;
        for (j = 0; j < 12; j++)
            sum += emple.ventas[j];

        if (sum > 1000000)
        {
            /* Incrementa el salario en 10% */
            emple.salario *= 1.10f;

            /* Reposiciona para escribir el registro actualizado */
            fseek(ap, (bloque - 1) * t, SEEK_SET);
            fwrite(&emple, sizeof(emple), 1, ap);

            /* Reposiciona para continuar leyendo el siguiente registro */
            fseek(ap, bloque * t, SEEK_SET);
        }

        /* Leer el siguiente registro */
        fread(&emple, sizeof(emple), 1, ap);
    }
}
