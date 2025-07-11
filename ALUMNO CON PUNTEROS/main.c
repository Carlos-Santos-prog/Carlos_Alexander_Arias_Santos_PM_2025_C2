#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "alumnos.dat"

/* Estructura alumno */
typedef struct {
    int  matricula;
    char nombre[50];
    float promedio;
} Alumno;

/* Prototipos */
void grabarAlumnos();
void leerAlumnos();

int main(void) {
    int opcion;

    do {
        printf("\n=== GESTION DINAMICA DE ALUMNOS ===\n");
        printf("1. Grabar alumnos en disco\n");
        printf("2. Leer alumnos desde disco\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            continue;
        }
        getchar();  // limpia '\n'

        switch (opcion) {
            case 1:
                grabarAlumnos();
                break;
            case 2:
                leerAlumnos();
                break;
            case 3:
                printf("Terminando programa.\n");
                break;
            default:
                printf("Opcion invalida. Intenta de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}

/* Graba en disco un numero dinamico de alumnos */
void grabarAlumnos() {
    int n;
    printf("Cuantos alumnos deseas grabar? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Cantidad invalida.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();  // limpia

    Alumno *lista = malloc(n * sizeof *lista);
    if (!lista) {
        perror("Error malloc");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf(" Matricula: ");
        scanf("%d", &lista[i].matricula);
        getchar();
        printf(" Nombre   : ");
        fgets(lista[i].nombre, sizeof lista[i].nombre, stdin);
        lista[i].nombre[strcspn(lista[i].nombre, "\n")] = '\0';
        printf(" Promedio : ");
        scanf("%f", &lista[i].promedio);
        getchar();
    }

    FILE *f = fopen(ARCHIVO, "wb");
    if (!f) {
        perror("Error al abrir archivo");
        free(lista);
        return;
    }
    fwrite(lista, sizeof *lista, n, f);
    fclose(f);
    free(lista);

    printf("\nSe han grabado %d alumnos en \"%s\".\n", n, ARCHIVO);
}

/* Lee todos los alumnos desde disco usando punteros y memoria dinamica */
void leerAlumnos() {
    FILE *f = fopen(ARCHIVO, "rb");
    if (!f) {
        printf("No se pudo abrir \"%s\"\n", ARCHIVO);
        return;
    }

    fseek(f, 0, SEEK_END);
    long bytes = ftell(f);
    rewind(f);
    int n = bytes / sizeof(Alumno);
    if (n <= 0) {
        printf("El archivo esta vacio.\n");
        fclose(f);
        return;
    }

    Alumno *lista = malloc(n * sizeof *lista);
    if (!lista) {
        perror("Error malloc");
        fclose(f);
        return;
    }

    fread(lista, sizeof *lista, n, f);
    fclose(f);

    printf("\n--- Alumnos leidos (%d) ---\n", n);
    for (Alumno *p = lista; p < lista + n; p++) {
        int idx = (int)(p - lista) + 1;
        printf("%2d. %s (Matricula: %d) - Promedio: %.2f\n",
               idx, p->nombre, p->matricula, p->promedio);
    }

    free(lista);
}
