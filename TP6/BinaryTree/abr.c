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


TreeNode* newNode(int valeur){
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    if (node==NULL) printf("[!] Erreur lors de l'allocation\n");
    node->data=valeur;
    node->droit=NULL;
    node->gauche=NULL;
    return node;
}



void freeAbr(TreeNode* abr){
    if (abr==NULL) return;
    else{
        freeAbr(abr->gauche);
        freeAbr(abr->droit);
        free(abr);
    }
}


void printAbr(TreeNode* abr){
    if (abr){
        printf("%d ", abr->data);
        printAbr(abr->gauche);
        printAbr(abr->droit);
    }
}



TreeNode* insert(TreeNode* abr,int valeur){
    if (abr==NULL){ //condition d'arret
        return newNode(valeur);
    } 
    else{   
        if (abr->data<=valeur){
            abr->droit=insert(abr->droit,valeur);
        }
        else if (abr->data>valeur){
            abr->gauche=insert(abr->gauche,valeur);
        }
    }
    return abr;
}


void inorder(TreeNode* abr){
    if (abr){
        printAbr(abr->gauche);
        printf("%d ", abr->data);
        printAbr(abr->droit);
    }
}



TreeNode* delete(TreeNode* abr, int valeur) {
    if (abr == NULL) {
        return abr;  //l'élément n'est pas présent dans l'arbre
    }

    if (valeur < abr->data) {
        abr->gauche = delete(abr->gauche, valeur);
    } else if (valeur > abr->data) {
        abr->droit = delete(abr->droit, valeur);
    } else {
        //l'élément à effacer est trouvé

        //pas d'enfant ou un seul enfant
        if (abr->gauche == NULL) {
            TreeNode* tmp=abr->droit;
            free(abr);
            return tmp;
        } else if (abr->droit == NULL) {
            TreeNode* tmp=abr->gauche;
            free(abr);
            return tmp;
        }

        //deux enfants
        TreeNode* tmp = abr->droit;
        while (tmp->gauche != NULL) {
            tmp=tmp->gauche;
        }

        abr->data = tmp->data;

        
        abr->droit = delete(abr->droit, tmp->data);
    }

    return abr;
}







