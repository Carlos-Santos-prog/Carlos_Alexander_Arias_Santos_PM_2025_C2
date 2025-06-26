#include <stdio.h>
#include <string.h>

/* Estructuras-1.
   El programa muestra cómo declarar una estructura y cómo acceder a sus campos
   tanto para asignación de valores como para lectura y escritura. */

struct alumno  /* Declaración de la estructura alumno */
{
    int matricula;        /* Matrícula del alumno */
    char nombre[20];      /* Nombre del alumno */
    char carrera[20];     /* Carrera del alumno */
    float promedio;       /* Promedio del alumno */
    char direccion[20];   /* Dirección del alumno */
};  /* Siempre termina con punto y coma */

int main(void)
{
    /* a1 inicializado directamente en la declaración */
    struct alumno a1 = {
        120,
        "María",
        "Contabilidad",
        8.9f,
        "Querétaro"
    };
    struct alumno a2, a3;  /* Declaración de otras dos variables de tipo alumno */

    /* Lectura de campos de a2 mediante scanf/gets y acceso a campos */
    printf("Ingrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno 2: ");
    gets(a2.nombre);
    printf("Ingrese la carrera del alumno 2: ");
    gets(a2.carrera);
    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese la dirección del alumno 2: ");
    gets(a2.direccion);

    /* Lectura de datos para a3 usando variables temporales y strcpy */
    int mat;
    char nom[20], car[20], dir[20];
    float pro;
    printf("\nIngrese la matrícula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;            /* Asignación directa al campo matricula */
    fflush(stdin);
    printf("Ingrese el nombre del alumno 3: ");
    gets(nom);
    strcpy(a3.nombre, nom);        /* Copia nom al campo nombre */
    printf("Ingrese la carrera del alumno 3: ");
    gets(car);
    strcpy(a3.carrera, car);       /* Copia car al campo carrera */
    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;             /* Asignación directa al campo promedio */
    fflush(stdin);
    printf("Ingrese la dirección del alumno 3: ");
    gets(dir);
    strcpy(a3.direccion, dir);     /* Copia dir al campo direccion */

    /* Impresión de los datos de a1 */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.direccion);

    /* Impresión de los datos de a2 */
    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.direccion);

    /* Impresión de los datos de a3 en una sola línea */
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n",
           a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);

    return 0;
}
