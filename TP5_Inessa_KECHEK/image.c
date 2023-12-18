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

image* init_image(char type_image[],int largeur_image, int hauteur_image, int valeur_max){
    image* pgm=(image*)malloc(sizeof(image));
    pgm->mat = (int**)malloc(largeur_image*sizeof(int*));
    for (int i = 0; i < largeur_image; i++){
        pgm->mat[i] = (int*)malloc(hauteur_image*sizeof(int));
    }
    pgm->type=strdup(type_image);
    pgm->hauteur = hauteur_image;
    pgm->largeur = largeur_image;
    pgm->val_max = valeur_max;
    return pgm;
}



void free_image(image* pgm){
    for (int i = 0; i < pgm->largeur; i++) {
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
    for (int i = 0; i < pgm->largeur; i++){
        
        for (int j = 0; j < pgm->hauteur; j++){
            printf("%d ",pgm->mat[i][j]);
        }
        printf("\n");
    }
}

image* loadImage(const char *nom_pgm){
    FILE *f = fopen(nom_pgm, "r");

    char type_image[2];
    int largeur_image, hauteur_image, valeur_max;
    fscanf(f, "%2s", type_image);
    fscanf(f, "%d %d",&largeur_image,&hauteur_image);
    fscanf(f,"%d",&valeur_max);
    image* pgm=init_image(type_image, largeur_image, hauteur_image, valeur_max);

    for (int i = 0; i < largeur_image; i++) {
        for (int j = 0; j < hauteur_image; j++) {
            fscanf(f, "%d", &pgm->mat[i][j]);
        }
    }
    fclose(f);
    return pgm;

}


void recordImage(const char* nom_pgm, image* pgm){
    FILE *f = fopen(nom_pgm, "w");
    fprintf(f,"%s\n", pgm->type);
    fprintf(f,"%d %d\n", pgm->largeur,pgm->hauteur);
    fprintf(f,"%d\n", pgm->val_max);

    for (int i = 0; i < pgm->largeur; i++){
 
        for (int j = 0; j < pgm->hauteur; j++){
            fprintf(f,"%d ", pgm->mat[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}


void binarisation(int seuil,const char* nom_pgm){
    image* pgm= loadImage(nom_pgm);
    for (int i = 0; i < pgm->largeur; i++){
        for (int j = 0; j < pgm->hauteur; j++){
            if (pgm->mat[i][j]<seuil){
                pgm->mat[i][j]=0;
            }
            else {
                pgm->mat[i][j]=255;
            }
        }
    }
    recordImage("nouvelle_lena.pgm",pgm);
    free_image(pgm);
}


void binarisation_inverse(const char* nom_pgm_binarise){
    image* pgm= loadImage(nom_pgm_binarise);
    for (int i = 0; i < pgm->largeur; i++){
        for (int j = 0; j < pgm->hauteur; j++){
            if (pgm->mat[i][j]==255){
                pgm->mat[i][j]=0;
            }
            else if (pgm->mat[i][j]==0) {
                pgm->mat[i][j]=255;
            }
        }
    }
    recordImage("nouvelle_lena_inverse.pgm",pgm);
    free_image(pgm);
}



/*
image* erosion(image* pgm){
    image* tmp=init_image(pgm->type,pgm->largeur,pgm->hauteur,pgm->val_max);                  

    for (int i = 1; i < pgm->largeur-1; i++){
        for (int j = 1; j < pgm->hauteur-1; j++){
  
            int tab[4];
            int min=pgm->mat[i][j];
            tab[0]=pgm->mat[i-1][j];
            tab[1]=pgm->mat[i][j-1];
            tab[2]=pgm->mat[i+1][j];
            tab[3]=pgm->mat[i][j+1];
            for (int z = 0; z < 4; z++){
                if (tab[z] < min){
                    min = tab[z];
                }
            }
            tmp->mat[i][j]=min;
        }
    }
    //recordImage("erosion_lena.pgm",tmp);
    //free_image(pgm);
    //free_image(tmp);
    return tmp;
}*/

void erosion(image* pgm) {
    image* tmp=init_image(pgm->type,pgm->largeur,pgm->hauteur,pgm->val_max);
    for (int i = 1; i < pgm->largeur - 1; i++) {
        for (int j = 1; j < pgm->hauteur- 1; j++) {
            // Calcul du min
            int minVal = pgm->mat[i][j];
            minVal=(pgm->mat[i-1][j]<minVal)?pgm->mat[i-1][j]:minVal;
            minVal=(pgm->mat[i+1][j]<minVal)? pgm->mat[i + 1][j] :minVal; 
            minVal=(pgm->mat[i][j-1]<minVal) ? pgm->mat[i][j -1] :minVal; 
            minVal=(pgm->mat[i][j+1]<minVal) ?pgm->mat[i][j+ 1] : minVal; 

            tmp->mat[i][j] = minVal;
        }
    }
    for (int i = 1; i < pgm->largeur - 1; i++) {
        for (int j = 1; j < pgm->hauteur - 1; j++) {
            pgm->mat[i][j] = tmp->mat[i][j];
        }
    }
}


void dilatation(image* pgm) {
    image* tmp=init_image(pgm->type,pgm->largeur,pgm->hauteur,pgm->val_max);
    for (int i = 1; i < pgm->largeur - 1; i++) {
        for (int j = 1; j < pgm->hauteur- 1; j++) {
            // Calcul du max
            int maxVal = pgm->mat[i][j];
            maxVal=(pgm->mat[i-1][j]>maxVal)?pgm->mat[i-1][j]:maxVal;
            maxVal=(pgm->mat[i+1][j]>maxVal)? pgm->mat[i + 1][j] :maxVal; 
            maxVal=(pgm->mat[i][j-1]>maxVal) ? pgm->mat[i][j -1] :maxVal; 
            maxVal=(pgm->mat[i][j+1]>maxVal) ?pgm->mat[i][j+ 1] : maxVal; 

            tmp->mat[i][j] = maxVal;
        }
    }
    for (int i = 1; i < pgm->largeur - 1; i++) {
        for (int j = 1; j < pgm->hauteur - 1; j++) {
            pgm->mat[i][j] = tmp->mat[i][j];
        }
    }
}