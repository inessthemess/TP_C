/***********************************************/
/* TP5                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    18/12/2023                        */
/***********************************************/

#ifndef _IMAGE_H
#define _IMAGE_H

typedef struct _image { 
    char* type; 
    int largeur;     
    int hauteur;     
    int val_max;
    int **mat;  
} image;


//cree une struct imagePGM avec toute les allocations necessaires
image* init_image(char type_image[],int largeur_image, int hauteur_image, int valeur_max);
//desalloue la struct imagePGM
void free_image(image* pgm);
//affiche les donnees d'une image sur le terminal
void print_pgm(image* pgm);
//crée une matrice (pointeur de pointeurs) qui contiendra toutes les valeurs d’un fichier pgm.
image* loadImage(const char *nom_pgm);
#endif