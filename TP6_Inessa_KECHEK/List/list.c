/***********************************************/
/* TP6                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    22/12/2023                        */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


ListNode* initNode(int valeur){
    ListNode* node=(ListNode*)malloc(sizeof(ListNode));
    node->val=valeur;
    node->suiv=NULL;
    return node;
}

void freeList(ListNode* list){
    if (!list) printf("[!] La liste est vide\n");
    ListNode* tmp=NULL;
    while (list){
        tmp=list->suiv;
        free(list);
        list=tmp;
    }
}



ListNode* insertEnd(ListNode* list,int valeur){
    if (!list) printf("[!] La liste est vide\n");
    else{
        ListNode* tmp=list;
        while (tmp->suiv != NULL){
            tmp=tmp->suiv;
        }
        ListNode* node=initNode(valeur);
        tmp->suiv=node;
    }
    return list;
}

ListNode* insertBeginning(ListNode* list,int valeur){
    if (!list) printf("[!] La liste est vide\n");
    ListNode* node=initNode(valeur);
    node->suiv=list;
    return node;
}

ListNode* insertMiddle(ListNode* list, int valeur, int element){
    ListNode* tmp=list;
    if (!list) printf("[!] La liste est vide\n");
    else{
        while (tmp!=NULL && tmp->val!=element){
            tmp=tmp->suiv;
        }
        if (tmp==NULL){
        // Élément non trouvé
        printf("[!] Élément %d non trouvé dans la liste\n", element);
        return list;
        }
        ListNode* node=initNode(valeur);
        node->suiv = tmp->suiv;
        tmp->suiv = node;
    }
    return list;
}


ListNode* deleteNode(ListNode* list, int valeur){
    ListNode* tete=list;
    ListNode* tmp=NULL;

    while (list!=NULL && list->val!=valeur){ //trouver l'élément
        tmp=list; // on garde un pointeur sur le précédent
        list=list->suiv;
    }
    if (!list){
        printf("[!] Élément %d non trouvé dans la liste\n",valeur);
    }
    else{ // si j'ai trouvé l'é;ément
        if(tmp){ //s'il n'est pas le 1er 
            tmp->suiv=list->suiv;
        }
        else{ //s'il est le 1er
            tete=list->suiv; //on change la tete de liste
        }
        free(list); // on libere l'élément
    }
    return tete;
}

void listPrint(ListNode* list){
    if (!list) printf("[!] La liste est vide\n");
    else{
        while (list){
            printf("%d ",list->val);
            list=list->suiv;
        }
    }
    printf("\n");
}

int searchNode(ListNode* list, int valeur){
    ListNode* tmp=list;
    while (tmp){
        if (tmp->val==valeur){
            printf("[!] Élément %d trouvé dans la liste\n",valeur);
            return 1;
        }
        tmp=tmp->suiv;
    }
    if (!tmp){
        printf("[!] Élément %d non trouvé dans la liste\n",valeur);
    }
    return 0;
}



ListNode* sorterList(ListNode* liste) {
    // Utiliser le tri par insertion
    ListNode* nList = NULL;
    ListNode* tmp1 = liste;
    if (liste == NULL || liste->suiv == NULL) { //si liste vide ou a un seul element
        return liste;
    }

    while (tmp1 != NULL) {
        ListNode* suivant = tmp1->suiv;

        if (nList == NULL || tmp1->val < nList->val) { 
            // Insérer au début de la liste triée
            tmp1->suiv = nList;
            nList = tmp1;
        } else {
            // Chercher la ou il faut inserer
            ListNode* tmp2 = nList;
            while (tmp2->suiv != NULL && tmp2->suiv->val < tmp1->val) {
                tmp2 = tmp2->suiv;
            }

            // Insérer tmp1 après tmp2 dans la liste triée
            tmp1->suiv = tmp2->suiv;
            tmp2->suiv = tmp1;
        }

        tmp1 = suivant;
    }

    return nList;
}


