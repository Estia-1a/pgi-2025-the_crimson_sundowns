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

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    printf("dimension: %d, %d\n", width, height);
    free(pixelArray);

}

void first_pixel (char *source_path){

    int width, height, channels;
    unsigned char *pixelArray = NULL;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    int R = pixelArray[0];
    int G = pixelArray[1];
    int B = pixelArray[2];
    printf("first_pixel: %d, %d, %d\n", R, G, B);
    free(pixelArray);

}

void tenth_pixel (char *source_path) {

    int width, height, channel_count;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    if (width < 10) {
        fprintf(stderr, "Error: la taille de l'image est inférieure à 10 pixels\n");
        return;
    }

    int pixel_index = 9; // on definit le numero du pixel qu'on veut utiliser ici 10eme
    int base_index = pixel_index * channel_count; // calcule l'index de depart dans le tableau data des donnees du pixel

    int R = pixelArray[base_index]; // R = premiere valeur rouge
    int G = pixelArray[base_index + 1]; 
    int B = pixelArray[base_index + 2];


    printf("tenth_pixel: %d, %d, %d\n" , R, G, B);

}

void second_line(char *source_path) {

    int width, height, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    printf("second_line: %d, %d, %d\n", pixelArray[3 * width], pixelArray[3 * width + 1], pixelArray[3 * width + 2]);
    free(pixelArray);

}

void max_pixel(char *source_path) { 

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int max = 0;
    int xmax, ymax;
    pixelRGB pixelMax;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (!result) {
         fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;        
    } 

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

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;        
    }

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
 
    if (!result) { 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;       
    } 
 
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

    printf("max_component %c (%d, %d): %d\n", component, xmax, ymax, componentMax);    
 
}

void min_component(char *source_path, char component) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMin = 255;
    int xmin, ymin;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (!result) { 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;       
    }
 
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

    printf("min_component %c (%d, %d): %d\n", component, xmin, ymin, componentMin); 
 
}

void max_pixel_file(char *source_path, FILE *fichier) { 

    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int max = 0;
    int xmax, ymax;
    pixelRGB pixelMax;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;        
    }

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

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;        
    }

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
 
    if (!result) { 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;       
    }
 
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

    fprintf(fichier, "max_component %c (%d, %d): %d\n", component, xmax, ymax, componentMax); 
 
}

void min_component_file(char *source_path, char component, FILE *fichier) {
 
    int width, height, channel_count;
    unsigned char *pixelArray;
    int x, y;
    int componentMin = 255;
    int xmin, ymin;
 
    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
 
    if (!result) { 
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;       
    }
 
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

    fprintf(fichier, "min_component %c (%d, %d): %d\n", component, xmin, ymin, componentMin);
 
}
 

void stat_report(char *source_path) {

    FILE *fichier = fopen("stat_report.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible de créer le fichier de rapport.\n");
        return;
    } else {

        max_pixel_file(source_path, fichier);
        fprintf(fichier, "\n");

        min_pixel_file(source_path, fichier);
        fprintf(fichier, "\n");

        max_component_file(source_path, 'R', fichier);
        fprintf(fichier, "\n");
        max_component_file(source_path, 'G', fichier);
        fprintf(fichier, "\n");
        max_component_file(source_path, 'B', fichier);
        fprintf(fichier, "\n");

        min_component_file(source_path, 'R', fichier);
        fprintf(fichier, "\n");
        min_component_file(source_path, 'G', fichier);
        fprintf(fichier, "\n");
        min_component_file(source_path, 'B', fichier);

        fclose(fichier);

    }

}

void color_red (char *source_path) {

    int width = 0, height = 0, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    for (int i=0 ; i< width*height*3 ; i +=3) {
        pixelArray[i+1] = 0;
        pixelArray[i+2] = 0;
    }

     if (!write_image_data("image_out_red.bmp", pixelArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    }

    else {
        printf("Image transformee enregistree dans image_out.bmp\n");
    }
    
}

void color_green (char *source_path) {

    int width = 0, height = 0, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    for (int i=0 ; i< width*height*3 ; i +=3) {
        pixelArray[i] = 0;
        pixelArray[i+2] = 0;
    }

     if (!write_image_data("image_out.bmp", pixelArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    }

    else {
        printf("Image transformee enregistree dans image_out.bmp\n");
    }   
}  

void color_blue (char *source_path) {

    int width = 0, height = 0, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    for (int i=0 ; i< width*height*3 ; i +=3) {
        pixelArray[i] = 0;
        pixelArray[i+1] = 0;
    }

     if (!write_image_data("image_out.bmp", pixelArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    }

    else {
        printf("Image transformee enregistree dans image_out.bmp\n");
    }

}

void color_gray (char *source_path) {

    int width = 0, height = 0, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    unsigned char value;

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    for (int i=0 ; i< width * height * 3 ; i += 3) {
        value = (pixelArray[i] + pixelArray[i+1] + pixelArray[i+2]) / 3;
        pixelArray[i] = value;
        pixelArray[i+1] = value;
        pixelArray[i+2] = value;
    }

    if (!write_image_data("image_out.bmp", pixelArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    }

    else {        
        printf("Image transformee enregistree dans image_out.bmp\n");
    }

}

void color_gray_luminance (char *source_path) {

    int width = 0, height = 0, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    unsigned char value;

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    for (int i=0 ; i< width * height * 3 ; i += 3) {
        value = 0.21 * pixelArray[i] + 0.72 * pixelArray[i+1] + 0.07 * pixelArray[i+2] ;
        pixelArray[i] = value;
        pixelArray[i+1] = value;
        pixelArray[i+2] = value;
    }

    if (!write_image_data("image_out.bmp", pixelArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    }

    else {        
        printf("Image transformee enregistree dans image_out.bmp\n");
    }

}

void rotate_cw(char *source_path){
 
    unsigned char* data;
    int width, height, channel_count;
 
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i,j;
        int new_x, new_y, new_index ;
        int new_width = height;
        int new_height = width;
   
        unsigned char* rotated_data = malloc(new_width * new_height * 3);
        for(j=0; j<height; j++){
            for(i=0; i<width; i++){
 
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j );
 
                if(pixel != NULL){
                    new_x = height-1-j;
                    new_y = i;
 
                    new_index = (new_y * new_width + new_x) * 3;
 
                    rotated_data[new_index] = pixel->R;
                    rotated_data[new_index + 1] = pixel->G;
                    rotated_data[new_index + 2] = pixel->B;
                }
               
            }
        }
        if (write_image_data("image_out.bmp", rotated_data, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        free(rotated_data);
       
    }
   
    free_image_data(data);
}

void rotate_acw(char *source_path){
 
    unsigned char* data;
    int width, height, channel_count;
 
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i,j;
        int new_x, new_y, new_index ;
        int new_width = height;
        int new_height = width;
   
        unsigned char* rotated_data = malloc(new_width * new_height * 3);
        for(j=0; j<height; j++){
            for(i=0; i<width; i++){
 
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j );
 
                if(pixel != NULL){
                    new_x = j;
                    new_y = width-1-i;
 
                    new_index = (new_y * new_width + new_x) * 3;
 
                    rotated_data[new_index] = pixel->R;
                    rotated_data[new_index + 1] = pixel->G;
                    rotated_data[new_index + 2] = pixel->B;
                }
               
            }
        }
        if (write_image_data("image_out.bmp", rotated_data, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        free(rotated_data);
       
    }
   
    free_image_data(data);
}


 void color_invert(char *source_path) {
    int width, height, channel_count;
    unsigned char *pixelArray;


    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
    if (result == 0 || pixelArray == 0) {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }

    int total_size = width * height * channel_count;

    unsigned char *inverted_pixelArray = (unsigned char *)malloc(total_size);
    if (inverted_pixelArray == 0) {
        fprintf(stderr, "Erreur : echec de l'allocation memoire pour l'image inversee\n");
        
        return;
    }

    for (int i = 0; i < total_size; i++) {
        inverted_pixelArray[i] = 255 - pixelArray[i];
    }

    if (!write_image_data("image_out.bmp", inverted_pixelArray, width, height)) {
        fprintf(stderr, "Erreur : impossible d'ecrire l'image de sortie\n");
        free(inverted_pixelArray);
        free(pixelArray);
    
    } 
    
    else {
        printf("Image transformee a bien ete transforme : image_out.bmp\n");
    }
 }

void mirror_horizontal (char *source_path) {

    int width, height, channels;
    unsigned char *pixelArray;

    int result = read_image_data(source_path, &pixelArray, &width, &height, &channels);

    if (!result) {
        fprintf(stderr, "L'image n'a pas pu etre lue\n");
        return;
    }

    unsigned char *mirroredArray = (unsigned char *)malloc(width * height * channels);
    if (!mirroredArray) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(pixelArray);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int src_index = (y * width + x) * channels;
            int dest_index = (y * width + (width - 1 - x)) * channels;

            mirroredArray[dest_index] = pixelArray[src_index];
            mirroredArray[dest_index + 1] = pixelArray[src_index + 1];
            mirroredArray[dest_index + 2] = pixelArray[src_index + 2];
        }
    }

    if (!write_image_data("image_out.bmp", mirroredArray, width, height)) {
        printf("Erreur : impossible d'écrire l'image\n");
    } else {
        printf("Image miroir horizontale enregistree dans image_out.bmp\n");
    }

    free(mirroredArray);
    free(pixelArray);
}

void mirror_total(char *source_path) {
    int width, height, channel_count;
    unsigned char *pixelArray;


    int result = read_image_data(source_path, &pixelArray, &width, &height, &channel_count);
    if (result == 0 || pixelArray == NULL) {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }

    int total_size = width * height * channel_count;


    unsigned char *mirrored_pixelArray = (unsigned char *)malloc(total_size);
    if (mirrored_pixelArray == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire pour l'image miroir\n");
        free(pixelArray);
        return;
    }


    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            int src_index = (y * width + x) * channel_count;

            // Calculer la position miroir : symétrie horizontale + verticale
            int mirrored_x = width - 1 - x;
            int mirrored_y = height - 1 - y;

            int dst_index = (mirrored_y * width + mirrored_x) * channel_count;

            // Copier tous les canaux (R, G, B, éventuellement Alpha)
            for (int c = 0; c < channel_count; c++) {
                mirrored_pixelArray[dst_index + c] = pixelArray[src_index + c];
            }
        }
    }


    if (!write_image_data("image_out.bmp", mirrored_pixelArray, width, height)) {
        fprintf(stderr, "Erreur : impossible d'écrire l'image de sortie\n");
    } else {
        printf("Image transformée avec succès : image_out.bmp\n");
    }


    free(pixelArray);
    free(mirrored_pixelArray);
}