#include <stdio.h>
#include <string.h>

/* Uniones.
   El programa muestra cómo se declara una unión, así como la forma de
   acceso a los campos de las variables de tipo unión tanto para asignación
   de valores como para lectura y escritura. */

union datos {              /* Declaración de una unión */
    char celular[15];
    char correo[20];
};

typedef struct {           /* Declaración de la estructura alumno */
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;  /* Uno de los campos de la estructura es una unión */
} alumno;

void Lectura(alumno *a);   /* Prototipo de función */

int main(void)
{
    /* a1 inicializado directamente: sólo el primer campo de la unión recibe valor */
    alumno a1 = {
        120,
        "María",
        "Contabilidad",
        8.9f,
        { "5-158-40-50" }    /* Se asigna al campo celular */
    };
    alumno a2, a3;

    /* Lectura de a2 en el programa principal */
    printf("Alumno 2\n");
    printf("Ingrese la matrícula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo);
    /* Observa que en a2 el segundo campo de la unión recibe valor (correo) */

    /* Lectura de a3 a través de función */
    printf("\nAlumno 3\n");
    Lectura(&a3);

    /* Impresión de resultados para a1 */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);
    /* Observa que escribe el valor del teléfono celular asignado */
    puts(a1.personales.correo);
    /* Observa que si tratamos de imprimir el campo correo, escribe basura */

    /* Ahora asignamos al segundo campo de la unión de a1 (correo) */
    strcpy(a1.personales.correo, "hgimenez@hotmail.com");
    /* Se ingresa un valor al campo correo */
    puts(a1.personales.celular);
    /* Ahora escribe basura en el campo celular */
    puts(a1.personales.correo);
    /* Escribe el contenido del campo correo */

    /* Impresión de datos para a2 */
    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular);
    /* Escribe basura, porque el último valor asignado a la unión fue correo */
    puts(a2.personales.correo);
    /* Escribe el contenido del segundo campo (correo) */

    printf("Ingrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular);
    puts(a2.personales.celular);
    /* Escribe el teléfono celular ingresado */
    puts(a2.personales.correo);
    /* Ahora escribe basura, porque el último valor asignado fue celular */

    /* Impresión de datos para a3 */
    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    /* Escribe basura si su campo activo fue correo */
    puts(a3.personales.correo);
    /* Escribe basura si su campo activo fue celular */

    return 0;
}

void Lectura(alumno *a)
/* La función Lectura se utiliza para leer los campos de una variable de tipo
   estructura alumno. */
{
    printf("Ingrese la matrícula: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el teléfono celular: ");
    gets(a->personales.celular);
    /* El campo activo de la unión es celular; el otro campo queda inválido */
}
