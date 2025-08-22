#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEH 300
#define STR 64

#define TIPO_GASOLINA 1
#define TIPO_GASOIL   2
#define DATA_FILE "vehiculos.dat"

typedef struct {
    char placa[STR];
    char marca[STR];
    char modelo[STR];
    int tipo_combustible;
    double km_gal_carretera;
    double km_gal_ciudad;
    double costo_gomas;
    int vida_gomas_anios;
    double costo_seguro_anual;
    double costo_mantenimiento;
    double km_entre_mant;
    double costo_vehiculo;
    int vida_util_anios;
    double km_por_anio;
} Vehiculo;

double precio_gasolina_galon = 290.10;
double precio_gasoil_galon   = 242.10;

Vehiculo* lista[MAX_VEH];
int n_veh = 0;

void leer_linea(char *buf, int n) {
    if (fgets(buf, n, stdin)) {
        size_t L = strlen(buf);
        if (L>0 && buf[L-1]=='\n') buf[L-1]=0;
    } else {
        clearerr(stdin);
        buf[0]=0;
    }
}

int leer_entero(const char *msg) {
    char s[128]; int x;
    for (;;) {
        printf("%s", msg);
        leer_linea(s, sizeof(s));
        if (sscanf(s, "%d", &x)==1) return x;
        puts("Entrada invalida. Intenta de nuevo.");
    }
}

double leer_double(const char *msg) {
    char s[128]; double x;
    for (;;) {
        printf("%s", msg);
        leer_linea(s, sizeof(s));
        if (sscanf(s, "%lf", &x)==1) return x;
        puts("Entrada invalida. Intenta de nuevo.");
    }
}

void mostrar_uno(const Vehiculo *v, int idx) {
    printf("\n--- Vehiculo %d ---\n", idx);
    printf("Placa: %s\n", v->placa);
    printf("Marca: %s\n", v->marca);
    printf("Modelo: %s\n", v->modelo);
    printf("Combustible: %s\n", (v->tipo_combustible==TIPO_GASOLINA)?"Gasolina":"Gasoil");
    printf("Km/gal carretera: %.2f\n", v->km_gal_carretera);
    printf("Km/gal ciudad:    %.2f\n", v->km_gal_ciudad);
    printf("Gomas -> costo: %.2f | vida: %d anios\n", v->costo_gomas, v->vida_gomas_anios);
    printf("Seguro anual: %.2f\n", v->costo_seguro_anual);
    printf("Mantenimiento -> costo: %.2f | cada: %.0f km\n", v->costo_mantenimiento, v->km_entre_mant);
    printf("Vehiculo -> costo: %.2f | vida util: %d anios | km/anio: %.0f\n",
           v->costo_vehiculo, v->vida_util_anios, v->km_por_anio);
}

void listar_todos(void) {
    if (n_veh==0) { puts("No hay vehiculos."); return; }
    puts("\n--- Lista de vehiculos ---");
    for (int i=0;i<n_veh;i++) {
        printf("[%d] %s - %s %s\n", i, lista[i]->placa, lista[i]->marca, lista[i]->modelo);
    }
}

void crear_vehiculo(Vehiculo **nuevo_out) {
    Vehiculo *v = (Vehiculo*)malloc(sizeof(Vehiculo));
    if (!v) { *nuevo_out = NULL; return; }

    printf("Placa: ");  leer_linea(v->placa, STR);
    printf("Marca: ");  leer_linea(v->marca, STR);
    printf("Modelo: "); leer_linea(v->modelo, STR);

    v->tipo_combustible = leer_entero("Tipo combustible (1=Gasolina, 2=Gasoil): ");

    v->km_gal_carretera = leer_double("Km por galon en carretera: ");
    v->km_gal_ciudad    = leer_double("Km por galon en ciudad: ");

    v->costo_gomas       = leer_double("Costo del juego de gomas: ");
    v->vida_gomas_anios  = leer_entero("Vida de gomas (anios): ");

    v->costo_seguro_anual = leer_double("Costo del seguro (12 meses): ");

    v->costo_mantenimiento = leer_double("Costo mantenimiento por servicio: ");
    v->km_entre_mant       = leer_double("Cada cuantos km se hace mantenimiento: ");

    v->costo_vehiculo  = leer_double("Costo del vehiculo: ");
    v->vida_util_anios = leer_entero("Vida util (anios): ");
    v->km_por_anio     = leer_double("Km por anio promedio: ");

    *nuevo_out = v;
}

void guardar_todo(void) {
    FILE *f = fopen(DATA_FILE, "wb");
    if (!f) return;

    fwrite(&precio_gasolina_galon, sizeof(precio_gasolina_galon), 1, f);
    fwrite(&precio_gasoil_galon,   sizeof(precio_gasoil_galon),   1, f);

    fwrite(&n_veh, sizeof(n_veh), 1, f);

    for (int i = 0; i < n_veh; ++i) {
        fwrite(lista[i], sizeof(Vehiculo), 1, f);
    }

    fclose(f);
}

void cargar_todo(void) {
    FILE *f = fopen(DATA_FILE, "rb");
    if (!f) return;

    if (fread(&precio_gasolina_galon, sizeof(precio_gasolina_galon), 1, f) != 1) { fclose(f); return; }
    if (fread(&precio_gasoil_galon,   sizeof(precio_gasoil_galon),   1, f) != 1) { fclose(f); return; }

    int count = 0;
    if (fread(&count, sizeof(count), 1, f) != 1) { fclose(f); return; }
    if (count < 0) count = 0;
    if (count > MAX_VEH) count = MAX_VEH;

    n_veh = 0;
    for (int i = 0; i < count; ++i) {
        Vehiculo *v = (Vehiculo*)malloc(sizeof(Vehiculo));
        if (!v) break;
        if (fread(v, sizeof(Vehiculo), 1, f) != 1) { free(v); break; }
        lista[n_veh++] = v;
    }

    fclose(f);
}

void insertar_vehiculo(Vehiculo **arr, int *n_p, Vehiculo *v) {
    if (*n_p >= MAX_VEH) {
        puts("Capacidad llena.");
        free(v);
        return;
    }
    arr[*n_p] = v;
    (*n_p)++;
    puts("Vehiculo creado.");
    guardar_todo();
}

void borrar_vehiculo(Vehiculo **arr, int *n_p) {
    if (*n_p == 0) { puts("No hay vehiculos."); return; }
    listar_todos();
    int idx = leer_entero("Indice a borrar: ");
    if (idx < 0 || idx >= *n_p) { puts("Indice invalido."); return; }

    free(arr[idx]);
    for (int i = idx; i < (*n_p) - 1; ++i) arr[i] = arr[i+1];
    (*n_p)--;
    puts("Vehiculo borrado.");
    guardar_todo();
}

void modificar_vehiculo(void) {
    if (n_veh == 0) { puts("No hay vehiculos."); return; }
    listar_todos();
    int idx = leer_entero("Indice a modificar: ");
    if (idx < 0 || idx >= n_veh) { puts("Indice invalido."); return; }

    Vehiculo *v = lista[idx];
    char s[STR];
    double x; int y;

    printf("Placa (%s): ", v->placa); leer_linea(s, STR); if (strlen(s)) strncpy(v->placa, s, STR);
    printf("Marca (%s): ", v->marca); leer_linea(s, STR); if (strlen(s)) strncpy(v->marca, s, STR);
    printf("Modelo (%s): ", v->modelo); leer_linea(s, STR); if (strlen(s)) strncpy(v->modelo, s, STR);

    y = leer_entero("Tipo (1 gasolina, 2 gasoil, -1 no cambiar): ");
    if (y == 1 || y == 2) v->tipo_combustible = y;

    x = leer_double("Km/gal carretera (-9999 no cambiar): "); if (x != -9999) v->km_gal_carretera = x;
    x = leer_double("Km/gal ciudad (-9999 no cambiar): ");    if (x != -9999) v->km_gal_ciudad    = x;

    x = leer_double("Costo gomas (-9999 no cambiar): "); if (x != -9999) v->costo_gomas = x;
    y = leer_entero("Vida de gomas anios (-1 no cambiar): "); if (y != -1) v->vida_gomas_anios = y;

    x = leer_double("Seguro anual (-9999 no cambiar): "); if (x != -9999) v->costo_seguro_anual = x;

    x = leer_double("Costo mantenimiento (-9999 no cambiar): "); if (x != -9999) v->costo_mantenimiento = x;
    x = leer_double("Km entre mant (-9999 no cambiar): ");       if (x != -9999) v->km_entre_mant       = x;

    x  = leer_double("Costo vehiculo (-9999 no cambiar): "); if (x != -9999) v->costo_vehiculo = x;
    y  = leer_entero("Vida util anios (-1 no cambiar): ");   if (y != -1)    v->vida_util_anios = y;
    x  = leer_double("Km por anio (-9999 no cambiar): ");    if (x != -9999) v->km_por_anio = x;

    puts("Vehiculo modificado.");
    guardar_todo();
}

void ver_datos_generales(void) {
    printf("\n--- Datos generales ---\n");
    printf("Precio gasolina/galon: %.2f\n", precio_gasolina_galon);
    printf("Precio gasoil/galon:  %.2f\n", precio_gasoil_galon);
}

void editar_datos_generales(void) {
    precio_gasolina_galon = leer_double("Nuevo precio gasolina/galon: ");
    precio_gasoil_galon   = leer_double("Nuevo precio gasoil/galon: ");
    puts("Datos generales actualizados.");
    guardar_todo();
}

double costo_combustible(const Vehiculo *v, double km_total, double pct_ciudad) {
    if (v->km_gal_carretera <= 0 || v->km_gal_ciudad <= 0) return 0.0;
    if (pct_ciudad < 0) pct_ciudad = 0;
    if (pct_ciudad > 100) pct_ciudad = 100;
    double km_ciudad    = km_total * (pct_ciudad / 100.0);
    double km_carretera = km_total - km_ciudad;
    double gal_ciudad   = km_ciudad    / v->km_gal_ciudad;
    double gal_carre    = km_carretera / v->km_gal_carretera;
    double gal_total    = gal_ciudad + gal_carre;
    double precio = (v->tipo_combustible == TIPO_GASOLINA) ? precio_gasolina_galon : precio_gasoil_galon;
    return gal_total * precio;
}

double costo_gomas(const Vehiculo *v, double km_total) {
    if (v->vida_gomas_anios <= 0 || v->km_por_anio <= 0) return 0.0;
    double km_vida_gomas = v->vida_gomas_anios * v->km_por_anio;
    return (v->costo_gomas / km_vida_gomas) * km_total;
}

double costo_seguro(const Vehiculo *v, double km_total) {
    if (v->km_por_anio <= 0) return 0.0;
    double por_km = v->costo_seguro_anual / v->km_por_anio;
    return por_km * km_total;
}

double costo_mantenimiento_viaje(const Vehiculo *v, double km_total) {
    if (v->km_entre_mant <= 0) return 0.0;
    double por_km = v->costo_mantenimiento / v->km_entre_mant;
    return por_km * km_total;
}

double costo_depreciacion(const Vehiculo *v, double km_total) {
    if (v->vida_util_anios <= 0 || v->km_por_anio <= 0) return 0.0;
    double dep_anual  = v->costo_vehiculo / (double)v->vida_util_anios;
    double dep_por_km = dep_anual / v->km_por_anio;
    return dep_por_km * km_total;
}

void calcular_costo_viaje(void) {
    if (n_veh == 0) { puts("Debe registrar al menos un vehiculo."); return; }
    listar_todos();
    int idx = leer_entero("Seleccione el indice del vehiculo: ");
    if (idx < 0 || idx >= n_veh) { puts("Indice invalido."); return; }
    Vehiculo *v = lista[idx];
    double km_total   = leer_double("Kilometros del viaje: ");
    double pct_ciudad = leer_double("Porcentaje de km en ciudad (0-100): ");
    double c_comb = costo_combustible(v, km_total, pct_ciudad);
    double c_gom  = costo_gomas(v, km_total);
    double c_seg  = costo_seguro(v, km_total);
    double c_man  = costo_mantenimiento_viaje(v, km_total);
    double c_dep  = costo_depreciacion(v, km_total);
    double total = c_comb + c_gom + c_seg + c_man + c_dep;
    double por_km = (km_total > 0) ? total / km_total : 0.0;
    printf("\n--- Resultado desglosado ---\n");
    printf("Vehiculo: %s %s (%s) - %s\n", v->marca, v->modelo, v->placa,
           (v->tipo_combustible==TIPO_GASOLINA)?"Gasolina":"Gasoil");
    printf("1) Costo de gomas:        %.2f\n", c_gom);
    printf("2) Costo de seguro:       %.2f\n", c_seg);
    printf("3) Costo de combustible:  %.2f\n", c_comb);
    printf("4) Costo de mantenimiento:%.2f\n", c_man);
    printf("5) Costo del vehiculo (deprec.): %.2f\n", c_dep);
    printf("Costo por km: %.4f\n", por_km);
    printf("Costo total del viaje: %.2f\n", total);
}

void menu_principal(void) {
    puts("\n==== GESTION DE COSTOS POR KM ====");
    puts("1) Crear vehiculo");
    puts("2) Listar vehiculos");
    puts("3) Modificar vehiculo");
    puts("4) Borrar vehiculo");
    puts("5) Ver/Editar datos generales (combustible)");
    puts("6) Calcular costo de viaje");
    puts("7) Ver detalle de un vehiculo");
    puts("0) Salir");
}

int main(void) {
    cargar_todo();

    if (n_veh == 0) {
        Vehiculo *demo = (Vehiculo*)malloc(sizeof(Vehiculo));
        if (demo) {
            strcpy(demo->placa, "M123XYZ");
            strcpy(demo->marca, "Mercedes");
            strcpy(demo->modelo, "Clase C");
            demo->tipo_combustible = TIPO_GASOLINA;
            demo->km_gal_carretera = 70.1;
            demo->km_gal_ciudad    = 50.5;
            demo->costo_gomas = 25000.0;
            demo->vida_gomas_anios = 3;
            demo->costo_seguro_anual = 30000.0;
            demo->costo_mantenimiento = 2600.0;
            demo->km_entre_mant = 10000.0;
            demo->costo_vehiculo  = 4500000.0;
            demo->vida_util_anios = 8;
            demo->km_por_anio = 15000.0;
            lista[n_veh++] = demo;
            guardar_todo();
        }
    }

    for (;;) {
        menu_principal();
        int op = leer_entero("Opcion: ");
        if (op == 0) { guardar_todo(); break; }
        if (op == 1) {
            Vehiculo *nuevo = NULL;
            crear_vehiculo(&nuevo);
            if (!nuevo) puts("Error de memoria.");
            else insertar_vehiculo(lista, &n_veh, nuevo);
        } else if (op == 2) {
            listar_todos();
        } else if (op == 3) {
            modificar_vehiculo();
        } else if (op == 4) {
            borrar_vehiculo(lista, &n_veh);
        } else if (op == 5) {
            ver_datos_generales();
            int e = leer_entero("Editar? (1=si, 0=no): ");
            if (e == 1) editar_datos_generales();
        } else if (op == 6) {
            calcular_costo_viaje();
        } else if (op == 7) {
            listar_todos();
            int idx = leer_entero("Indice a mostrar: ");
            if (idx >= 0 && idx < n_veh) mostrar_uno(lista[idx], idx);
            else puts("Indice invalido.");
        } else {
            puts("Opcion invalida.");
        }
    }

    for (int i=0;i<n_veh;i++) free(lista[i]);
    puts("Hasta luego.");
    return 0;
}

