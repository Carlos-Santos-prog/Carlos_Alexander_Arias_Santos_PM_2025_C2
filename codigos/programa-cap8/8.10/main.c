#include <stdio.h>
#include <string.h>

/* Vendedores.
   El programa maneja información sobre las ventas que realizan los vendedores de
   artículos domésticos de una importante empresa de la Ciudad de México. */

/* Declaración de la estructura banco, para datos de cheque o nómina */
typedef struct {
    char noba[10];   /* Nombre del banco */
    char nucu[10];   /* Número de cuenta */
} banco;

/* Declaración de la unión fpago, con tres posibles formas de pago */
typedef union {
    banco che;      /* Pago por cheque */
    banco nomi;     /* Pago por nómina */
    char venta;     /* Pago en ventanilla (indica con 'S' o 'N') */
} fpago;

/* Declaración de la estructura domicilio */
typedef struct {
    char cnu[20];   /* Calle y número */
    char col[20];   /* Colonia */
    char cp[5];     /* Código Postal */
    char ciu[15];   /* Ciudad */
} domicilio;

/* Declaración de la estructura vendedor */
typedef struct {
    int     num;       /* Número de vendedor */
    char    nom[20];   /* Nombre del vendedor */
    float   ven[12];   /* Ventas de cada mes (12 meses) */
    domicilio domi;    /* Domicilio del vendedor */
    float   sal;       /* Salario mensual */
    fpago   pago;      /* Forma de pago */
    int     cla;       /* Clave de forma de pago: 1=Cheque,2=Nómina,3=Ventanilla */
} vendedor;

/* Prototipos de funciones */
void Lectura(vendedor A[], int T);
void F1(vendedor A[], int T);
void F2(vendedor A[], int T);
void F3(vendedor A[], int T);
void F4(vendedor A[], int T);

int main(void)
{
    vendedor VENDEDORES[100];
    int TAM;

    /* Leer número de vendedores */
    do {
        printf("Ingrese el número de vendedores (1-100): ");
        scanf("%d", &TAM);
    } while (TAM < 1 || TAM > 100);

    fflush(stdin);
    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

void Lectura(vendedor A[], int T)
/* Lee los datos de T vendedores: número, nombre, ventas mensuales, domicilio,
   salario y forma de pago */
{
    for (int i = 0; i < T; i++) {
        printf("\n--- Vendedor %d ---\n", i + 1);

        printf("Número de vendedor: ");
        scanf("%d", &A[i].num);

        fflush(stdin);
        printf("Nombre del vendedor: ");
        gets(A[i].nom);

        printf("Ventas del año (12 meses):\n");
        for (int j = 0; j < 12; j++) {
            printf("\tMes %d: ", j + 1);
            scanf("%f", &A[i].ven[j]);
        }

        fflush(stdin);
        printf("Domicilio del vendedor:\n");
        printf("\tCalle y número: ");
        gets(A[i].domi.cnu);
        printf("\tColonia: ");
        gets(A[i].domi.col);
        printf("\tCódigo Postal: ");
        gets(A[i].domi.cp);
        printf("\tCiudad: ");
        gets(A[i].domi.ciu);

        printf("Salario mensual: ");
        scanf("%f", &A[i].sal);

        printf("Forma de Pago (1=Cheque, 2=Nomina, 3=Ventanilla): ");
        scanf("%d", &A[i].cla);
        fflush(stdin);

        switch (A[i].cla) {
            case 1:
                /* Pago por cheque */
                printf("\tNombre del banco: ");
                gets(A[i].pago.che.noba);
                printf("\tNúmero de cuenta: ");
                gets(A[i].pago.che.nucu);
                break;
            case 2:
                /* Pago por nómina */
                printf("\tNombre del banco: ");
                gets(A[i].pago.nomi.noba);
                printf("\tNúmero de cuenta: ");
                gets(A[i].pago.nomi.nucu);
                break;
            case 3:
                /* Pago por ventanilla */
                A[i].pago.venta = 'S';
                break;
            default:
                printf("\tForma de pago inválida.\n");
        }
    }
}

void F1(vendedor A[], int T)
/* Calcula e imprime las ventas totales anuales de cada vendedor */
{
    printf("\n\n\tVentas Totales de los Vendedores\n");
    for (int i = 0; i < T; i++) {
        float SUM = 0.0f;
        for (int j = 0; j < 12; j++)
            SUM += A[i].ven[j];
        printf("Vendedor %d - Ventas anuales: %.2f\n", A[i].num, SUM);
    }
}

void F2(vendedor A[], int T)
/* Incrementa un 5% el salario de los vendedores cuyas ventas anuales superaron
   $1,500,000 e imprime su nuevo salario */
{
    printf("\n\n\tIncremento a Vendedores con Ventas > 1,500,000\n");
    for (int i = 0; i < T; i++) {
        float SUM = 0.0f;
        for (int j = 0; j < 12; j++)
            SUM += A[i].ven[j];
        if (SUM > 1500000.00f) {
            A[i].sal *= 1.05f;
            printf("Vendedor %d - Ventas: %.2f - Nuevo salario: %.2f\n",
                   A[i].num, SUM, A[i].sal);
        }
    }
}

void F3(vendedor A[], int T)
/* Imprime los datos de los vendedores que en el año vendieron menos de $300,000 */
{
    printf("\n\n\tVendedores con Ventas < 300,000\n");
    for (int i = 0; i < T; i++) {
        float SUM = 0.0f;
        for (int j = 0; j < 12; j++)
            SUM += A[i].ven[j];
        if (SUM < 300000.00f) {
            printf("Vendedor %d - Nombre: %s - Ventas: %.2f\n",
                   A[i].num, A[i].nom, SUM);
        }
    }
}

void F4(vendedor A[], int T)
/* Imprime el número, banco y cuenta de los vendedores cuyo salario se deposita
   en cuenta de cheques (cla == 1) */
{
    printf("\n\n\tVendedores con Cuenta en el Banco\n");
    for (int i = 0; i < T; i++) {
        if (A[i].cla == 1) {
            printf("Vendedor %d - Banco: %s - Cuenta: %s\n",
                   A[i].num,
                   A[i].pago.che.noba,
                   A[i].pago.che.nucu);
        }
    }
}
