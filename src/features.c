#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char *source_path) {
    
    int width, height, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (result) {
        printf("dimension: %d, %d\n", width, height);
        free(pixelArray);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
    }    
}

void second_line(char *source_path) {

    int width, height, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (result) {
        printf("second_line: %d, %d, %d\n", pixelArray[3 * width], pixelArray[3 * width + 1], pixelArray[3 * width + 2]);
        free(pixelArray);
    } else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
    }
}
