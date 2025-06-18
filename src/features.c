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
    } 
    else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
    }    
}

void first_pixel (char *source_path){
    int width, height, channels;
    unsigned char *pixelArray = NULL;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);
    if (result == 1) {
        if (channels == 3) {
            int R = pixelArray[0];
            int G = pixelArray[1];
            int B = pixelArray[2];
            printf("first_pixel: %d, %d, %d\n", R, G, B);
        }
        free(pixelArray);
    }
    else {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
    }
}

void tenth_pixel (char *source_path) {

    int width, height, channel_count;
    unsigned char *pixelArray;

    read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (width < 10) {
    fprintf(stderr, "Error: la taille de l'image est inférieure à 10\n");
    return;
    }

    int pixel_index = 9; // on definit le numero du pixel qu'on veut utiliser ici 10eme
    int base_index = pixel_index * channel_count; // calcul l'index de depart dans le tableau data des donnees du pixel

    int R = pixelArray[base_index]; // R = premiere valeur rouge
    int G = pixelArray[base_index + 1]; 
    int B = pixelArray[base_index + 2];


    printf("tenth_pixel: %d, %d, %d\n" , R, G, B);

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

void max_pixel(char *source_path) { 

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int max = 0;
    int xmax, ymax;
    pixelRGB pixelMax;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (result == 0) {

        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
        
    } else {

        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                int somme = pixelActuel->R + pixelActuel->G + pixelActuel->B;
                if (somme > max) {
                    max = somme;
                    xmax = x;
                    ymax = y;
                    pixelMax = *pixelActuel;
                }
            }
        }
        
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", xmax, ymax, pixelMax.R, pixelMax.G, pixelMax.B);
    free(pixelArray);

}

void min_pixel(char *source_path) {

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int min = 255;
    int xmin, ymin;
    pixelRGB pixelMin;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (result == 0) {

        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
        
    } else {

        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                int somme = pixelActuel->R + pixelActuel->G + pixelActuel->B;
                if (somme < min) {
                    min = somme;
                    xmin = x;
                    ymin = y;
                    pixelMin = *pixelActuel;
                }
            }
        }
        
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", xmin, ymin, pixelMin.R, pixelMin.G, pixelMin.B);
    free(pixelArray);

}

void max_component(char *source_path, char component) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMax = 0;
    int xmax, ymax;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (result == 0) {
 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
       
    } else {
 
        if (component == 'R') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->R > componentMax) {
                        componentMax = pixelActuel->R;
                        xmax = x;
                        ymax = y;
                    }
                }
            }
        }
 
        else if (component == 'G') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->G > componentMax) {
                        componentMax = pixelActuel->G;
                        xmax = x;
                        ymax = y;
                    }
                }
            }
        }
 
        else if (component == 'B') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->B > componentMax) {
                        componentMax = pixelActuel->B;
                        xmax = x;
                        ymax = y;
                    }
                }
            }            
        }
 
        else {
            fprintf(stderr, "Composant inconnu : %c\n", component);
            return;
        }
 
        printf("max_component %c (%d, %d): %d", component, xmax, ymax, componentMax);
 
    }
 
}

void min_component(char *source_path, char component) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMin = 255;
    int xmin, ymin;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (result == 0) {
 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
       
    } else {
 
        if (component == 'R') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->R < componentMin) {
                        componentMin = pixelActuel->R;
                        xmin = x;
                        ymin = y;
                    }
                }
            }
        }
 
        else if (component == 'G') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->G < componentMin) {
                        componentMin = pixelActuel->G;
                        xmin = x;
                        ymin = y;
                    }
                }
            }
        }
 
        else if (component == 'B') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->B < componentMin) {
                        componentMin = pixelActuel->B;
                        xmin = x;
                        ymin = y;
                    }
                }
            }            
        }
 
        else {
            fprintf(stderr, "Composante inconnue : %c\n", component);
            return;
        }
 
        printf("min_component %c (%d, %d): %d", component, xmin, ymin, componentMin);
 
    }
 
}

void max_pixel_file(char *source_path, FILE *fichier) { 

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int max = 0;
    int xmax, ymax;
    pixelRGB pixelMax;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (result == 0) {

        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
        
    } else {

        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                int somme = pixelActuel->R + pixelActuel->G + pixelActuel->B;
                if (somme > max) {
                    max = somme;
                    xmax = x;
                    ymax = y;
                    pixelMax = *pixelActuel;
                }
            }
        }
        
    }

    fprintf(fichier, "max_pixel (%d, %d): %d, %d, %d\n", xmax, ymax, pixelMax.R, pixelMax.G, pixelMax.B);
    free(pixelArray);

}

void min_pixel_file(char *source_path, FILE *fichier) {

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int min = 255;
    int xmin, ymin;
    pixelRGB pixelMin;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (result == 0) {

        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
        
    } else {

        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                int somme = pixelActuel->R + pixelActuel->G + pixelActuel->B;
                if (somme < min) {
                    min = somme;
                    xmin = x;
                    ymin = y;
                    pixelMin = *pixelActuel;
                }
            }
        }
        
    }

    fprintf(fichier, "min_pixel (%d, %d): %d, %d, %d\n", xmin, ymin, pixelMin.R, pixelMin.G, pixelMin.B);
    free(pixelArray);

}

void max_component_file(char *source_path, char component, FILE *fichier) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMax = 0;
    int xmax, ymax;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (result == 0) {
 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
       
    } else {
 
        if (component == 'R') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->R > componentMax) {
                        componentMax = pixelActuel->R;
                        xmax = x;
                        ymax = y;
                    }
                }
            }
        }
 
        else if (component == 'G') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->G > componentMax) {
                        componentMax = pixelActuel->G;
                        xmax = x;
                        ymax = y;
                    }
                }
            }
        }
 
        else if (component == 'B') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->B > componentMax) {
                        componentMax = pixelActuel->B;
                        xmax = x;
                        ymax = y;
                    }
                }
            }            
        }
 
        else {
            fprintf(stderr, "Composant inconnu : %c\n", component);
            return;
        }
 
        fprintf(fichier, "max_component %c (%d, %d): %d", component, xmax, ymax, componentMax);
 
    }
 
}

void min_component_file(char *source_path, char component, FILE *fichier) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMin = 255;
    int xmin, ymin;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (result == 0) {
 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
       
    } else {
 
        if (component == 'R') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->R < componentMin) {
                        componentMin = pixelActuel->R;
                        xmin = x;
                        ymin = y;
                    }
                }
            }
        }
 
        else if (component == 'G') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->G < componentMin) {
                        componentMin = pixelActuel->G;
                        xmin = x;
                        ymin = y;
                    }
                }
            }
        }
 
        else if (component == 'B') {
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    pixelRGB* pixelActuel = get_pixel(pixelArray, width, height, channel_count, x, y);
                    if (pixelActuel->B < componentMin) {
                        componentMin = pixelActuel->B;
                        xmin = x;
                        ymin = y;
                    }
                }
            }            
        }
 
        else {
            fprintf(stderr, "Composante inconnue : %c\n", component);
            return;
        }
 
        fprintf(fichier, "min_component %c (%d, %d): %d", component, xmin, ymin, componentMin);
 
    }
 
}

void stat_report(char *source_path) {

    FILE *fichier = fopen("stat_report.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible de créer le fichier de rapport.\n");
        return;
    } else {

        max_pixel_file(source_path, fichier);

        min_pixel_file(source_path, fichier);

        max_component_file(source_path, 'R', fichier);
        max_component_file(source_path, 'G', fichier);
        max_component_file(source_path, 'B', fichier);

        min_component_file(source_path, 'R', fichier);
        min_component_file(source_path, 'G', fichier);
        min_component_file(source_path, 'B', fichier);

        fclose(fichier);

    }

}
