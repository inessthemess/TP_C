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
//enregistre l’image au format pgm
void recordImage(const char* nom_pgm, image* pgm);
//prend comme argument un seuil et une image et modifie l’image de telle sorte que toute valeur en niveau de gris
//supérieur à ce seuil sera mise à 255 et toute valeur inférieure sera mise à 0
void binarisation(int seuil,const char* nom_pgm);
//fonction inverse de binarisation qui traite chaque pixel binarisé : les pixel à 255 passeront à 0 et ceux à 0 passeront à 255
//on suppose de l'image en argument est binarisée
void binarisation_inverse(const char* nom_pgm_binarise);
//vérifiera pour chaque pixel le minimum entre la valeur du pixel courant, celle du pixel au-dessus, en dessous à gauche et à droite
//le pixel courant sera remplacé par ce minimum
//image* erosion(image* pgm);
void erosion(image* pgm);
void dilatation(image* pgm);
#endif