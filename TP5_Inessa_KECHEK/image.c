/***********************************************/
/* TP5                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    18/12/2023                        */
/***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"



void free_image(image* pgm){
    for (int i = 0; i < pgm->hauteur; i++) {
        free(pgm->mat[i]);
    }
    free(pgm->mat);
    //free(pgm->type);
    free(pgm);
}


void print_pgm(image* pgm){
    printf("L'image est de type %s\n",pgm->type);
    printf("La largeur et la hauteur de l'image sont respectivement : %dx%d\n",pgm->largeur,pgm->hauteur);
    printf("La valeur maximale de l'image est %d\n",pgm->val_max);
    for (int i = 0; i < pgm->hauteur; i++){ 
        for (int j = 0; j < pgm->largeur; j++){
            printf("%d ",pgm->mat[i][j]);
        }
        printf("\n");
    }
}


image* loadImage(const char *filename) {

    image* pgm=(image*)malloc(sizeof(image));
    FILE *file = fopen(filename, "r");

    fscanf(file, "P2\n%d %d\n%d\n", &pgm->largeur, &pgm->hauteur, &pgm->val_max);


    pgm->mat = (int **)malloc(pgm->hauteur * sizeof(int *));

    for (int i=0; i<pgm->hauteur; i++) {
        pgm->mat[i] = (int *)malloc(pgm->largeur * sizeof(int));
    
    }

    for (int i=0; i<pgm->hauteur; i++) {
        for (int j=0; j<pgm->largeur; j++) {
            fscanf(file, "%d", &pgm->mat[i][j]);
        }
    }

    fclose(file);

    return pgm;
}


void recordImage(const char* nom_pgm,image* pgm) {

    FILE* pgmdup = fopen(nom_pgm, "wb");
    fprintf(pgmdup, "P2\n");
    fprintf(pgmdup, "%d %d\n", pgm->largeur, pgm->hauteur);
    fprintf(pgmdup, "%d\n", pgm->val_max);

    for (int i=0; i<pgm->hauteur; i++) { 
        for (int j=0; j<pgm->largeur; j++) { 
            int temp = pgm->mat[i][j];
  
            fprintf(pgmdup, "%d ", temp); 
        } 
        fprintf(pgmdup, "\n"); 
    } 
    fclose(pgmdup); 
} 





void binarisation(int seuil,const char* nom_pgm){
    image* pgm= loadImage(nom_pgm);
    for (int i = 0; i < pgm->hauteur; i++){
        for (int j = 0; j < pgm->largeur; j++){
            if (pgm->mat[i][j]<seuil){
                pgm->mat[i][j]=0;
            }
            else {
                pgm->mat[i][j]=255;
            }
        }
    }
    recordImage("bin_lena.pgm",pgm);
    free_image(pgm);
}


void binarisation_inverse(const char* nom_pgm_binarise){
    image* pgm= loadImage(nom_pgm_binarise);
    for (int i = 0; i < pgm->hauteur; i++){
        for (int j = 0; j < pgm->largeur; j++){
            if (pgm->mat[i][j]==255){
                pgm->mat[i][j]=0;
            }
            else if (pgm->mat[i][j]==0) {
                pgm->mat[i][j]=255;
            }
        }
    }
    recordImage("bin_lena_inverse.pgm",pgm);
    free_image(pgm);
}



void erosion(image* pgm) {

    FILE* erodedpgm = fopen("er_lena.pgm", "wb");
    fprintf(erodedpgm, "P2\n");
    fprintf(erodedpgm, "%d %d\n", pgm->largeur-2, pgm->hauteur-2);
    fprintf(erodedpgm, "%d\n", pgm->val_max);

    for (int i=1; i<pgm->hauteur-1; i++) { 
        for (int j=1; j<pgm->largeur-1; j++) { 
            int ver = pgm->mat[i-1][j]<pgm->mat[i][j]? pgm->mat[i-1][j]:pgm->mat[i][j];
            int hor = pgm->mat[i+1][j-1]<pgm->mat[i+1][j+1]? pgm->mat[i+1][j-1]:pgm->mat[i+1][j+1];
            int temp = hor<ver? hor:ver;
            fprintf(erodedpgm, "%d ", temp); 
        }
        fprintf(erodedpgm, "\n"); 
    }
    fclose(erodedpgm);
}

void dilatation(image* pgm) {

    FILE* dilatedpgm = fopen("dil_lena.pgm", "wb");
    fprintf(dilatedpgm, "P2\n");
    fprintf(dilatedpgm, "%d %d\n", pgm->largeur-2, pgm->hauteur-2);
    fprintf(dilatedpgm, "%d\n", pgm->val_max);

    for (int i=1; i<pgm->hauteur-1; i++) { 
        for (int j=1; j<pgm->largeur-1; j++) { 
            int ver = pgm->mat[i-1][j]>pgm->mat[i][j]? pgm->mat[i-1][j]:pgm->mat[i][j];
            int hor = pgm->mat[i+1][j-1]>pgm->mat[i+1][j+1]? pgm->mat[i+1][j-1]:pgm->mat[i+1][j+1];
            int temp = hor>ver? hor:ver;
            fprintf(dilatedpgm, "%d ", temp); 
        }
        fprintf(dilatedpgm, "\n"); 
    }
    fclose(dilatedpgm);
}

