#include <stdio.h>
#include <string.h>

/* Comercializadora farmacéutica.
   El programa maneja información sobre ventas, inventario,
   reabastecimiento y nuevos productos de una comercializadora farmacéutica. */

typedef struct {
    int    clave;       /* Clave del producto */
    char   nombre[15];  /* Nombre del producto */
    float  precio;      /* Precio unitario */
    int    existencia;  /* Cantidad en inventario */
} producto;

/* Prototipos de funciones */
void Lectura(producto A[], int T);
void Ventas(producto A[], int T);
void Reabastecimiento(producto A[], int T);
void Nuevos_Productos(producto A[], int *T);
void Inventario(producto A[], int T);

int main(void)
{
    producto INV[100];  /* Inventario: hasta 100 productos */
    int T, OPE;

    /* Leer número de productos */
    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &T);
    } while (T < 1 || T > 100);

    /* Cargar datos iniciales */
    Lectura(INV, T);

    /* Menú de operaciones */
    do {
        printf("\nIngrese operación a realizar:\n");
        printf(" 1 - Ventas\n");
        printf(" 2 - Reabastecimiento\n");
        printf(" 3 - Nuevos Productos\n");
        printf(" 4 - Inventario\n");
        printf(" 0 - Salir\n> ");
        scanf("%d", &OPE);

        switch (OPE) {
            case 1: Ventas(INV, T); break;
            case 2: Reabastecimiento(INV, T); break;
            case 3: Nuevos_Productos(INV, &T); break;
            case 4: Inventario(INV, T); break;
            case 0: break;
            default:
                printf("Opción inválida.\n");
        }
    } while (OPE != 0);

    return 0;
}

void Lectura(producto A[], int T)
/* Leer un arreglo de T productos */
{
    for (int i = 0; i < T; i++) {
        printf("\nProducto %d\n", i + 1);
        printf(" Clave: ");
        scanf("%d", &A[i].clave);
        fflush(stdin);
        printf(" Nombre: ");
        gets(A[i].nombre);
        printf(" Precio: ");
        scanf("%f", &A[i].precio);
        printf(" Existencia: ");
        scanf("%d", &A[i].existencia);
    }
}

void Ventas(producto A[], int T)
/* Manejar ventas: ingresar clave y cantidad hasta que clave = 0;
   actualizar inventario y acumular total de la venta. */
{
    int cla, can;
    float TOT = 0.0f;

    printf("\n--- Ventas ---\n");
    do {
        printf("Ingrese clave del producto (0 para salir): ");
        scanf("%d", &cla);
        if (cla == 0) break;

        printf(" Cantidad vendida: ");
        scanf("%d", &can);

        /* Buscar producto por clave */
        int i = 0;
        while (i < T && A[i].clave != cla) i++;
        if (i == T) {
            printf("  Clave incorrecta.\n");
        } else if (A[i].existencia < can) {
            printf("  Solo hay %d en inventario.\n", A[i].existencia);
            printf("  ¿Vender toda la existencia? (1=Sí / 0=No): ");
            int resp; scanf("%d", &resp);
            if (resp) {
                TOT += A[i].precio * A[i].existencia;
                A[i].existencia = 0;
            }
        } else {
            /* Venta normal */
            A[i].existencia -= can;
            TOT += A[i].precio * can;
        }
    } while (1);

    printf("Total de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T)
/* Ingresar clave y cantidad a reabastecer hasta clave = 0; actualizar existencia */
{
    int cla, can;
    printf("\n--- Reabastecimiento ---\n");
    do {
        printf("Ingrese clave del producto (0 para salir): ");
        scanf("%d", &cla);
        if (cla == 0) break;

        /* Buscar producto */
        int i = 0;
        while (i < T && A[i].clave != cla) i++;
        if (i == T) {
            printf("  Clave incorrecta.\n");
        } else {
            printf(" Cantidad a reabastecer: ");
            scanf("%d", &can);
            A[i].existencia += can;
        }
    } while (1);
}

void Nuevos_Productos(producto A[], int *T)
/* Insertar nuevos productos manteniendo inventario ordenado por clave */
{
    int cla;
    printf("\n--- Nuevos Productos ---\n");
    do {
        if (*T >= 100) {
            printf("Inventario lleno, no se pueden agregar más.\n");
            break;
        }

        printf("Ingrese clave del nuevo producto (0 para salir): ");
        scanf("%d", &cla);
        if (cla == 0) break;

        /* Encontrar posición de inserción */
        int pos = 0;
        while (pos < *T && A[pos].clave < cla) pos++;

        if (pos < *T && A[pos].clave == cla) {
            printf("  El producto ya existe en inventario.\n");
        } else {
            /* Mover para abrir espacio */
            for (int j = *T; j > pos; j--) {
                A[j] = A[j - 1];
            }
            /* Leer datos del nuevo producto */
            A[pos].clave = cla;
            fflush(stdin);
            printf(" Nombre: ");
            gets(A[pos].nombre);
            printf(" Precio: ");
            scanf("%f", &A[pos].precio);
            printf(" Existencia: ");
            scanf("%d", &A[pos].existencia);
            (*T)++;
        }
    } while (1);
}

void Inventario(producto A[], int T)
/* Mostrar todo el inventario */
{
    printf("\n--- Inventario ---\n");
    for (int i = 0; i < T; i++) {
        printf("Clave: %d  Nombre: %s  Precio: %.2f  Existencia: %d\n",
               A[i].clave, A[i].nombre, A[i].precio, A[i].existencia);
    }
}
