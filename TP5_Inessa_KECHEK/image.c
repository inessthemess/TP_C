/***********************************************/
/* TP5                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    18/12/2023                        */
/***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

image* init_image(char type_image[],int largeur_image, int hauteur_image, int valeur_max){
    image* pgm=(image*)malloc(sizeof(image));
    pgm->mat = (int**)malloc(hauteur_image*sizeof(int*));
    for (int i = 0; i < hauteur_image; i++){
        pgm->mat[i] = (int*)malloc(largeur_image*sizeof(int));
    }
    pgm->type=strdup(type_image);
    pgm->hauteur = hauteur_image;
    pgm->largeur = largeur_image;
    pgm->val_max = valeur_max;
    return pgm;
}



void free_image(image* pgm){
    for (int i = 0; i < pgm->hauteur; i++) {
        free(pgm->mat[i]);
    }
    free(pgm->mat);
    free(pgm->type);
    free(pgm);
}


void print_pgm(image* pgm){
    printf("L'image est de type %s\n",pgm->type);
    printf("La largeur et la hauteur de l'image sont respectivement : %dx%d\n",pgm->largeur,pgm->hauteur);
    printf("La valeur maximale de l'image est %d\n",pgm->val_max);
    for (int i = 0; i < pgm->hauteur; i++){
        printf("\n");
        for (int j = 0; j < pgm->largeur; j++){
            printf("%d ",pgm->mat[i][j]);
        }
    }
    printf("\n");
}

image* loadImage(const char *nom_pgm){
    FILE *f = fopen(nom_pgm, "r");

    char type_image[2];
    int largeur_image, hauteur_image, valeur_max;
    fscanf(f, "%2s", type_image);
    fscanf(f, "%d %d",&largeur_image,&hauteur_image);
    fscanf(f,"%d",&valeur_max);
    image* pgm=init_image(type_image, largeur_image, hauteur_image, valeur_max);

    for (int i = 0; i < hauteur_image; i++) {
        for (int j = 0; j < largeur_image; j++) {
            fscanf(f, "%d", &pgm->mat[i][j]);
        }
    }
    fclose(f);
    return pgm;

}


