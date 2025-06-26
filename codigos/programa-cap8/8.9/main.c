#include <stdio.h>
#include <string.h>

/* Bienes raíces.
   El programa maneja información sobre las propiedades que tiene una empresa
   de bienes raíces de Lima, Perú, tanto para venta como para renta. */

/* Estructura para la ubicación de la propiedad */
typedef struct {
    char zona[20];   /* Zona (ej. Miraflores) */
    char calle[20];  /* Nombre de la calle */
    char colo[20];   /* Colonia */
} ubicacion;

/* Estructura para los datos de cada propiedad */
typedef struct {
    char   clave[5];   /* Código identificador */
    float  scu;        /* Superficie cubierta (m²) */
    float  ste;        /* Superficie de terreno (m²) */
    char   car[50];    /* Características descriptivas */
    ubicacion ubi;     /* Ubicación (estructura anidada) */
    float  precio;     /* Precio en nuevos soles */
    char   dispo;      /* Disponibilidad: 'V' venta, 'R' renta */
} propiedades;

/* Prototipos de funciones */
void Lectura(propiedades A[], int T);
void F1(propiedades A[], int T);
void F2(propiedades A[], int T);

int main(void)
{
    propiedades PROPIE[100];
    int TAM, OPE;

    /* Leer cantidad de propiedades */
    do {
        printf("Ingrese el número de propiedades (1-100): ");
        scanf("%d", &TAM);
    } while (TAM < 1 || TAM > 100);

    fflush(stdin);
    Lectura(PROPIE, TAM);

    /* Mostrar listados según criterio */
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

void Lectura(propiedades A[], int T)
/* Leer T propiedades desde la entrada estándar */
{
    for (int i = 0; i < T; i++) {
        printf("\n--- Propiedad %d ---\n", i + 1);
        fflush(stdin);
        printf("Clave: ");
        gets(A[i].clave);

        printf("Superficie cubierta (m2): ");
        scanf("%f", &A[i].scu);

        printf("Superficie terreno (m2): ");
        scanf("%f", &A[i].ste);
        fflush(stdin);

        printf("Características: ");
        gets(A[i].car);

        printf("\tZona: ");
        gets(A[i].ubi.zona);

        printf("\tCalle: ");
        gets(A[i].ubi.calle);

        printf("\tColonia: ");
        gets(A[i].ubi.colo);

        printf("Precio (S/): ");
        scanf("%f", &A[i].precio);
        fflush(stdin);

        printf("Disponibilidad (Venta-V / Renta-R): ");
        A[i].dispo = getchar();
        fflush(stdin);
    }
}

void F1(propiedades A[], int T)
/* Listado de propiedades para venta en Miraflores con precio entre 450k y 650k */
{
    printf("\n\nListado de Propiedades en Venta (Miraflores, S/450k–650k):\n");
    for (int i = 0; i < T; i++) {
        if (A[i].dispo == 'V'
         && strcmp(A[i].ubi.zona, "Miraflores") == 0
         && A[i].precio >= 450000
         && A[i].precio <= 650000)
        {
            printf("\nClave: %s\n", A[i].clave);
            printf("  Sup. cubierta: %.2f m2\n", A[i].scu);
            printf("  Sup. terreno:  %.2f m2\n", A[i].ste);
            printf("  Características: %s\n", A[i].car);
            printf("  Calle: %s\n", A[i].ubi.calle);
            printf("  Colonia: %s\n", A[i].ubi.colo);
            printf("  Precio: S/%.2f\n", A[i].precio);
        }
    }
}

void F2(propiedades A[], int T)
/* Listado de propiedades para renta en zona y rango de precio dado */
{
    char zon[20];
    float li, ls;

    printf("\n\nListado de Propiedades en Renta:\n");
    fflush(stdin);
    printf("Ingrese zona geográfica: ");
    gets(zon);

    printf("Ingrese límite inferior de precio (S/): ");
    scanf("%f", &li);
    printf("Ingrese límite superior de precio (S/): ");
    scanf("%f", &ls);

    for (int i = 0; i < T; i++) {
        if (A[i].dispo == 'R'
         && strcmp(A[i].ubi.zona, zon) == 0
         && A[i].precio >= li
         && A[i].precio <= ls)
        {
            printf("\nClave: %s\n", A[i].clave);
            printf("  Sup. cubierta: %.2f m2\n", A[i].scu);
            printf("  Sup. terreno:  %.2f m2\n", A[i].ste);
            printf("  Características: %s\n", A[i].car);
            printf("  Calle: %s\n", A[i].ubi.calle);
            printf("  Colonia: %s\n", A[i].ubi.colo);
            printf("  Precio: S/%.2f\n", A[i].precio);
        }
    }
}
