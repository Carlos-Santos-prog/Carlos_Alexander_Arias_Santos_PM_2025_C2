#include <stdio.h>

/* Ordena de menor a mayor.
   El programa ordena de menor a mayor en función de la matrícula,
   creando un nuevo archivo de acceso directo compuesto por estructuras
   y ordenado de mayor a menor. */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;  /* Declaración de la estructura alumno. */

void ordena(FILE *ap1, FILE *ap2);    /* Prototipo de función. */

int main(void)
{
    FILE *ar1, *ar2;

    ar1 = fopen("ad5.dat", "rb");   /* Abrir archivo de origen en modo binario */
    ar2 = fopen("ad6.dat", "wb");   /* Crear archivo destino en modo binario */

    if (ar1 != NULL && ar2 != NULL)
        ordena(ar1, ar2);
    else
        printf("\nEl o los archivos no se pudieron abrir\n");

    if (ar1) fclose(ar1);
    if (ar2) fclose(ar2);
    return 0;
}

void ordena(FILE *ap1, FILE *ap2)
/* Esta función ordena de menor a mayor un archivo compuesto por estructuras,
   en función de su matrícula, y genera un nuevo archivo en orden inverso (de
   mayor a menor) recorriendo los registros al revés. */
{
    alumno alu;
    size_t t = sizeof(alumno);
    long n, i;

    /* Obtener número de registros */
    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / t;
    rewind(ap1);

    /* Leer y copiar registros en orden inverso */
    for (i = n - 1; i >= 0; i--)
    {
        fseek(ap1, i * t, SEEK_SET);
        fread(&alu, t, 1, ap1);
        fwrite(&alu, t, 1, ap2);
    }
}
