#include <stdio.h>
#include <string.h>

#define MAX 100
#define ARCHIVO "alumnos.dat"


typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

int main(void) {
    FILE *f;
    Alumno lista[MAX], alumno;
    int opcion, n, i, j;
    char resp;

    do {
        printf("\n1- Agregar alumno\n");
        printf("2- Mostrar orden alfabetico\n");
        printf("3- Mostrar por promedio\n");
        printf("4- Salir\n");
        printf("Elige una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (opcion == 1) {
            f = fopen(ARCHIVO, "ab");
            if (!f) { perror("Error al abrir el archivo"); continue; }
            do {
                printf("Nombre del alumno: ");
                fgets(alumno.nombre, sizeof alumno.nombre, stdin);
                alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0';

                printf("Promedio del alumno: ");
                scanf("%f", &alumno.promedio);
                while (getchar() != '\n');

                fwrite(&alumno, sizeof alumno, 1, f);

                printf("¿Desea agregar otro alumno? (s/n): ");
                resp = getchar();
                while (getchar() != '\n');
            } while (resp == 's' || resp == 'S');
            fclose(f);

        } else if (opcion == 2 || opcion == 3) {
            f = fopen(ARCHIVO, "rb");
            if (!f) { printf("No hay alumnos registrados.\n"); continue; }
            for (n = 0; n < MAX && fread(&lista[n], sizeof lista[n], 1, f) == 1; n++);
            fclose(f);
            if (n == 0) { printf("No hay alumnos registrados.\n"); continue; }


            for (i = 0; i < n-1; i++) {
                for (j = 0; j < n-1-i; j++) {
                    int debe = 0;
                    if (opcion == 2) {
                        if (strcasecmp(lista[j].nombre, lista[j+1].nombre) > 0)
                            debe = 1;
                    } else {
                        if (lista[j].promedio > lista[j+1].promedio)
                            debe = 1;
                    }
                    if (debe) {
                        Alumno tmp = lista[j];
                        lista[j] = lista[j+1];
                        lista[j+1] = tmp;
                    }
                }
            }

            printf("\nLista de alumnos (%d):\n", n);
            for (i = 0; i < n; i++)
                printf("%2d. %-30s Promedio: %.2f\n",
                       i+1, lista[i].nombre, lista[i].promedio);

        } else if (opcion != 4) {
            printf("Opcion invalida. Intenta de nuevo.\n");
        }
    } while (opcion != 4);

    printf("Fin del programa.\n");
    return 0;
}
