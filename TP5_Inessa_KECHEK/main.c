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
    //image *pgm_lena = loadImage(nom_pgm);

    //print_pgm(pgm_lena);
    //recordImage("new_lena.pgm", pgm_lena);
    binarisation(128,"lena.pgm");
    binarisation_inverse("bin_lena.pgm");
    //free_image(pgm_lena);

    image* pgm=loadImage("lena.pgm");
    recordImage("recorded_lena.pgm",pgm);
    erosion(pgm);
    dilatation(pgm);
    free_image(pgm);
    return 0;

}