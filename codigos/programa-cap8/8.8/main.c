#include <stdio.h>
#include <string.h>

/* Hospital.
   El programa genera información acerca de los pacientes de un hospital. */

/* Estructura para domicilio del paciente */
typedef struct {
    char cal[20];   /* Calle */
    int  num;       /* Número */
    char col[20];   /* Colonia */
    char cp[5];     /* Código Postal */
    char ciu[20];   /* Ciudad */
} domicilio;

/* Estructura para paciente */
typedef struct {
    char      nom[20];   /* Nombre y apellido */
    int       edad;      /* Edad */
    char      sexo;      /* Sexo: 'F' o 'M' */
    int       con;       /* Condición: 1..5 */
    domicilio dom;       /* Domicilio (estructura anidada) */
    char      tel[10];   /* Teléfono */
} paciente;

/* Prototipos de funciones */
void Lectura(paciente A[], int T);
void F1(paciente A[], int T);
void F2(paciente A[], int T);
void F3(paciente A[], int T);

int main(void)
{
    paciente HOSPITAL[100];  /* Arreglo de hasta 100 pacientes */
    int TAM;

    /* Leer número de pacientes */
    do {
        printf("Ingrese el número de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM < 1 || TAM > 100);

    fflush(stdin);
    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T)
/* Lee T elementos del arreglo de tipo paciente */
{
    for (int i = 0; i < T; i++) {
        printf("\n\t\tPaciente %d\n", i + 1);
        fflush(stdin);

        printf("Nombre: ");
        gets(A[i].nom);

        printf("Edad: ");
        scanf("%d", &A[i].edad);

        printf("Sexo (F/M): ");
        fflush(stdin);
        scanf("%c", &A[i].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[i].con);

        fflush(stdin);
        printf("\tCalle: ");
        gets(A[i].dom.cal);

        printf("\tNúmero: ");
        scanf("%d", &A[i].dom.num);

        fflush(stdin);
        printf("\tColonia: ");
        gets(A[i].dom.col);

        printf("\tCódigo Postal: ");
        gets(A[i].dom.cp);

        printf("\tCiudad: ");
        gets(A[i].dom.ciu);

        printf("Teléfono: ");
        gets(A[i].tel);
    }
}

void F1(paciente A[], int T)
/* Calcula e imprime el porcentaje de hombres y mujeres ingresados */
{
    int fem = 0, mas = 0;
    for (int i = 0; i < T; i++) {
        if (A[i].sexo == 'F') fem++;
        else if (A[i].sexo == 'M') mas++;
    }
    int tot = fem + mas;
    printf("\nPorcentaje de Hombres: %.2f%%", (float)mas / tot * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)fem / tot * 100);
}

void F2(paciente A[], int T)
/* Cuenta e imprime cuántos pacientes hay en cada categoría de condición */
{
    int c1=0, c2=0, c3=0, c4=0, c5=0;
    for (int i = 0; i < T; i++) {
        switch (A[i].con) {
            case 1: c1++; break;
            case 2: c2++; break;
            case 3: c3++; break;
            case 4: c4++; break;
            case 5: c5++; break;
        }
    }
    printf("\nNúmero pacientes en condición 1: %d", c1);
    printf("\nNúmero pacientes en condición 2: %d", c2);
    printf("\nNúmero pacientes en condición 3: %d", c3);
    printf("\nNúmero pacientes en condición 4: %d", c4);
    printf("\nNúmero pacientes en condición 5: %d", c5);
}

void F3(paciente A[], int T)
/* Muestra nombre y teléfono de los pacientes en condición de máxima gravedad (5) */
{
    printf("\nPacientes ingresados en estado de gravedad 5:");
    for (int i = 0; i < T; i++) {
        if (A[i].con == 5) {
            printf("\nNombre: %s\tTeléfono: %s", A[i].nom, A[i].tel);
        }
    }
    printf("\n");
}
