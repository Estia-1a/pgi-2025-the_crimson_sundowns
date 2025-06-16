#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {

    if ((x >= height) || (y >= width)) {
        fprintf(stderr, "Erreur : image trop petite pour aller chercher le pixel demandé\n");
        return NULL;
    }

    else if (data == NULL) {
        fprintf(stderr, "Erreur : données image nulles\n");
        return NULL;
    }

    else {
        return (pixelRGB *) &data[(y * width + x) * n] ;
    }

}

void print_pixel(char *filename, int x, int y) {

    int width, height, channels;
    unsigned char *pixelArray;

    int result = read_image_data(filename, &pixelArray, &width, &height, &channels);

    if (result) {
        pixelRGB * pixel_recherche = get_pixel(pixelArray, width, height, channels, x, y);
        if (pixel_recherche != NULL) {
            printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel_recherche->R, pixel_recherche->G, pixel_recherche->B);
        } else {
            fprintf(stderr, "Erreur : coordonnées pixel (%d, %d) invalides.\n", x, y);
        }
        free(pixelArray);
    }
}
