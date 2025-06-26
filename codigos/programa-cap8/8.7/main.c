#include <stdio.h>
#include <string.h>

/* Escuela.
   El programa genera información importante de los alumnos de una escuela. */

/* Estructura para materia y promedio */
typedef struct {
    char mat[20];   /* Nombre de la materia */
    int  pro;       /* Promedio obtenido */
} matpro;

/* Estructura para alumno, que contiene matrícula, nombre y array de 5 matpro */
typedef struct {
    int     matri;      /* Matrícula del alumno */
    char    nom[20];    /* Nombre del alumno */
    matpro  cal[5];     /* Arreglo de 5 materias con su promedio */
} alumno;

/* Prototipos de funciones */
void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

int main(void)
{
    alumno ALU[50];  /* Arreglo de hasta 50 alumnos */
    int TAM;

    /* Leer tamaño del arreglo */
    do {
        printf("Ingrese el tamaño del arreglo (1-50): ");
        scanf("%d", &TAM);
    } while (TAM < 1 || TAM > 50);

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);

    return 0;
}

void Lectura(alumno A[], int T)
/* Lee T alumnos, cada uno con matrícula, nombre y 5 materias con promedio */
{
    for (int I = 0; I < T; I++) {
        printf("\n--- Datos del alumno %d ---\n", I + 1);

        /* Matrícula */
        printf("Ingrese la matrícula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);

        /* Nombre */
        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nom);

        /* Materias y promedios */
        for (int J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            gets(A[I].cal[J].mat);

            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T)
/* Para cada alumno imprime matrícula y promedio general (promedio de 5 materias) */
{
    for (int I = 0; I < T; I++) {
        float SUM = 0.0f;
        for (int J = 0; J < 5; J++) {
            SUM += A[I].cal[J].pro;
        }
        float PROM = SUM / 5.0f;
        printf("\nMatrícula del alumno: %d\tPromedio general: %.2f\n",
               A[I].matri, PROM);
    }
}

void F2(alumno A[], int T)
/* Lista las matrículas de los alumnos cuya calificación en la 3ª materia > 9 */
{
    printf("\nAlumnos con calificación > 9 en la tercera materia:\n");
    for (int I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9) {
            printf("  Matrícula: %d\n", A[I].matri);
        }
    }
}

void F3(alumno A[], int T)
/* Calcula el promedio general de la cuarta materia para todo el grupo */
{
    float SUM = 0.0f;
    for (int I = 0; I < T; I++) {
        SUM += A[I].cal[3].pro;
    }
    float PROM = SUM / T;
    printf("\nPromedio del grupo en la cuarta materia: %.2f\n", PROM);
}
