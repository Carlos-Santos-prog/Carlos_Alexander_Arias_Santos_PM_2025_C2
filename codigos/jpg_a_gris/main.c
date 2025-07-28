#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo_entrada.jpg>\n", argv[0]);
        return 1;
    }
    const char *rutaEntrada = argv[1];

    int ancho, alto, canales;
    unsigned char *imagenColor = stbi_load(
        rutaEntrada,
        &ancho,
        &alto,
        &canales,
        0
    );
    if (imagenColor == NULL) {
        fprintf(stderr, "Error cargando '%s'\n", rutaEntrada);
        return 1;
    }
    if (canales < 3) {
        fprintf(stderr, "La imagen debe tener al menos 3 canales (RGB)\n");
        stbi_image_free(imagenColor);
        return 1;
    }

    size_t numPixeles = (size_t)ancho * alto;
    unsigned char *imagenGris = malloc(numPixeles);
    if (imagenGris == NULL) {
        fprintf(stderr, "Error de memoria\n");
        stbi_image_free(imagenColor);
        return 1;
    }

    for (int y = 0; y < alto; y++) {
        for (int x = 0; x < ancho; x++) {
            int idxColor = (y * ancho + x) * canales;
            float lum =
                0.299f * imagenColor[idxColor + 0] +
                0.587f * imagenColor[idxColor + 1] +
                0.114f * imagenColor[idxColor + 2];
            imagenGris[y * ancho + x] = (unsigned char)lum;
        }
    }

    char nombreSalida[512];
    snprintf(
        nombreSalida,
        sizeof(nombreSalida),
        "%s_gris.jpg",
        rutaEntrada
    );

    if (!stbi_write_jpg(
            nombreSalida,
            ancho,
            alto,
            1,
            imagenGris,
            90
        )) {
        fprintf(stderr, "Error escribiendo '%s'\n", nombreSalida);
        free(imagenGris);
        stbi_image_free(imagenColor);
        return 1;
    }

    printf("Archivo generado: %s\n", nombreSalida);

    free(imagenGris);
    stbi_image_free(imagenColor);
    return 0;
}
