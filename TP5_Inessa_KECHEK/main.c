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
    image *pgm_lena = loadImage(nom_pgm);

    print_pgm(pgm_lena);
    free_image(pgm_lena);

    return 0;

}