#include <stdio.h>

/* Alumnos.
   El programa pregunta al usuario el número de registro que desea
   modificar, obtiene el nuevo promedio del alumno y modifica tanto el
   registro como el archivo correspondiente. */

typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *); /* Prototipo de función. */

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+")) != NULL)
    {
        modifica(ar);
        fclose(ar);
    }
    else
        printf("\nEl archivo no se puede abrir\n");

    return 0;
}

/* Esta función se utiliza para modificar el promedio de un alumno. */
void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el número de registro que desea modificar: ");
    /* Observa que en C el primer registro está en la posición cero,
       por lo tanto, para modificar el registro n debes buscar en (n – 1). */
    scanf("%d", &d);

    /* Posiciona el apuntador al inicio del registro deseado */
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    /* Lee el registro existente */
    fread(&alu, sizeof(alumno), 1, ap);

    printf("Matrícula: %d\n", alu.matricula);
    printf("Nombre   : %s\n", alu.nombre);
    printf("Carrera  : %d\n", alu.carrera);
    printf("Promedio actual: %.2f\n", alu.promedio);

    /* Solicita el nuevo promedio */
    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);

    /* Reposiciona para sobreescribir el mismo registro */
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    /* Escribe el registro modificado */
    fwrite(&alu, sizeof(alumno), 1, ap);

    printf("\nPromedio actualizado correctamente.\n");
}
