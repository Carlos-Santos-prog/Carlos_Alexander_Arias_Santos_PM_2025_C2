#include <stdio.h>

/* Alumnos.
   El programa actualiza el promedio de un alumno en un archivo de acceso directo. */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;  /* Declaración de la estructura alumno. */

void modificarPromedio(FILE *);   /* Prototipo de función. */

int main(void)
{
    FILE *ar;

    /* Abrimos el archivo en modo lectura/escritura binaria */
    if ((ar = fopen("ad1.dat", "r+b")) != NULL)
    {
        modificarPromedio(ar);
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo\n");

    return 0;
}

/* Esta función pide al usuario el número de registro a modificar, mueve el apuntador con fseek,
lee el registro, solicita el nuevo  promedio, y luego sobreescribe el bloque con fwrite. */
void modificarPromedio(FILE *ap)
{
    alumno alu;
    int numRegistro;
    long desplaz;

    /* ¿Qué registro desea modificar? (1 = primer bloque, 2 = segundo, ...) */
    printf("Ingrese el número de registro del alumno a modificar: ");
    scanf("%d", &numRegistro);

    /* Calculamos el desplazamiento en bytes */
    desplaz = (numRegistro - 1) * sizeof(alumno);

    /* Posicionamos el apuntador al inicio del registro */
    fseek(ap, desplaz, SEEK_SET);

    /* Leemos el registro existente */
    fread(&alu, sizeof(alumno), 1, ap);

    /* Mostramos datos actuales */
    printf("\nDatos del registro %d:\n", numRegistro);
    printf("Matrícula: %d\n", alu.matricula);
    printf("Nombre   : %s\n", alu.nombre);
    printf("Carrera  : %d\n", alu.carrera);
    printf("Promedio : %.2f\n", alu.promedio);

    /* Solicitamos nuevo promedio */
    printf("\nIngrese el nuevo promedio: ");
    scanf("%f", &alu.promedio);

    /* Volvemos a posicionar el apuntador para sobreescribir */
    fseek(ap, desplaz, SEEK_SET);

    /* Escribimos el registro modificado */
    fwrite(&alu, sizeof(alumno), 1, ap);

    printf("\nPromedio actualizado correctamente.\n");
}
