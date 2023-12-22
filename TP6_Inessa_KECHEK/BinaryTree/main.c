/***********************************************/
/* TP6                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    22/12/2023                        */
/***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "abr.h"


int main(){
    TreeNode* abr=NULL;
    int tab[]={101,8,14,129,4,99,13,55};
    for (int i=0; i < 8; i++){
        abr=insert(abr,tab[i]);
    }
    printf("parcours prefixe :");
    printAbr(abr);
    printf("\n");
    printf("parcours infixe :");
    inorder(abr);
    printf("\n");
    freeAbr(abr);
    return 0;
}