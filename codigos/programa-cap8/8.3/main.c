#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras-3.
   El programa muestra la manera en que se declara una estructura anidada, así
   como la forma de acceso a los campos de las variables o apuntadores de tipo
   estructura, tanto para lectura como para escritura. Se utiliza además una
   función que recibe como parámetro un apuntador de tipo estructura. */

/* Declaración de domicilio utilizando typedef */
typedef struct {
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

/* Declaración de la estructura anidada empleado */
struct empleado {
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;  /* direccion es un campo de tipo estructura domicilio */
};

void Lectura(struct empleado *a);  /* Prototipo de función */

int main(void)
{
    /* Inicialización directa de un struct */
    struct empleado e0 = {
        "Arturo",
        "Compras",
        15500.75f,
        { "San Jeronimo", 120, 3490, "Toluca" }
    };
    struct empleado *e1, *e2, e3, e4;
    /* *e1, *e2: apuntadores de tipo struct empleado; e3, e4: variables directas */

    /* Reservar memoria para e1 y leer sus campos */
    e1 = malloc(sizeof *e1);
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%19s", e1->nombre);
    fflush(stdin);
    printf("Ingrese el departamento del empleado 1: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado 1: ");
    scanf("%f", &e1->sueldo);
    printf("---Ingrese la direccion del empleado 1---\n");
    fflush(stdin);
    printf("Calle: ");
    gets(e1->direccion.calle);
    printf("Numero: ");
    scanf("%d", &e1->direccion.numero);
    printf("Codigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    fflush(stdin);
    printf("Localidad: ");
    gets(e1->direccion.localidad);

    /* Leer campos de e3 usando variable directa */
    printf("\nIngrese el nombre del empleado 3: ");
    scanf("%19s", e3.nombre);
    fflush(stdin);
    printf("Ingrese el departamento del empleado 3: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado 3: ");
    scanf("%f", &e3.sueldo);
    printf("---Ingrese la direccion del empleado 3---\n");
    fflush(stdin);
    printf("Calle: ");
    gets(e3.direccion.calle);
    printf("Numero: ");
    scanf("%d", &e3.direccion.numero);
    printf("Codigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    fflush(stdin);
    printf("Localidad: ");
    gets(e3.direccion.localidad);

    /* Usar la función Lectura para e2 y e4 */
    e2 = malloc(sizeof *e2);
    Lectura(e2);      /* Pasa apuntador */
    Lectura(&e4);     /* Pasa dirección de variable directa */

    /* Imprimir datos de e0 */
    printf("\nDatos del empleado 0\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e0.nombre, e0.departamento, e0.sueldo,
           e0.direccion.calle, e0.direccion.numero,
           e0.direccion.cp, e0.direccion.localidad);

    /* Imprimir datos de e1 */
    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero,
           e1->direccion.cp, e1->direccion.localidad);

    /* Imprimir datos de e3 */
    printf("\nDatos del empleado 3\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e3.nombre, e3.departamento, e3.sueldo,
           e3.direccion.calle, e3.direccion.numero,
           e3.direccion.cp, e3.direccion.localidad);

    /* Imprimir datos de e4 */
    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero,
           e4.direccion.cp, e4.direccion.localidad);

    free(e1);
    free(e2);
    return 0;
}

void Lectura(struct empleado *a)
/* Esta función permite leer los campos de un apuntador de tipo estructura empleado. */
{
    printf("\nIngrese el nombre del empleado: ");
    scanf("%19s", a->nombre);
    fflush(stdin);
    printf("Ingrese el departamento del empleado: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("---Ingrese la direccion del empleado---\n");
    printf("Calle: ");
    gets(a->direccion.calle);
    printf("Numero: ");
    scanf("%d", &a->direccion.numero);
    printf("Codigo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("Localidad: ");
    gets(a->direccion.localidad);
}
