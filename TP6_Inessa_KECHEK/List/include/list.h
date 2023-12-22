/***********************************************/
/* TP6                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    22/12/2023                        */
/***********************************************/

#ifndef _LIST_H
#define _LIST_H

typedef struct _ListNode{
    int val;
    struct _ListNode* suiv;
}ListNode;


//Créer l'élément racine
ListNode* initNode(int valeur);
//désalloue une liste
void freeList(ListNode* list);
//ajoute un élément à la fin de la liste
ListNode* insertEnd(ListNode* list,int valeur);
//insère un élément au début de la liste
ListNode* insertBeginning(ListNode* list,int valeur);
//insert un nouvel élément à l’intérieur de la liste,après un élément donné
ListNode* insertMiddle(ListNode* list, int valeur, int element);
//efface un noeud basé sur sa valeur
ListNode* deleteNode(ListNode* list, int valeur);
//affiche la liste
void listPrint(ListNode* list);
//trouve si un noeud est présent en fonction de sa valeur, renvoie 1 si l'élément est trouvé, 0 sinon
int searchNode(ListNode* list, int valeur);
//trie les éléments de la liste en ordre croissant
ListNode* sorterList(ListNode* liste);



#endif