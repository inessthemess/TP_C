/***********************************************/
/* TP5                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    18/12/2023                        */
/***********************************************/
#include <stdio.h>
#include "image.h"

int main(){
    const char *nom_pgm = "lena.pgm";
    //image *pgm_lena = loadImage(nom_pgm);

    //print_pgm(pgm_lena);
    //recordImage("new_lena.pgm", pgm_lena);
    //binarisation(128,nom_pgm);
    //binarisation_inverse("nouvelle_lena.pgm");
    //free_image(pgm_lena);
    image* pgm=loadImage(nom_pgm);
    erosion(pgm);
    dilatation(pgm);
    recordImage("erosion_dilatation_lena.pmg",pgm);
    return 0;

}