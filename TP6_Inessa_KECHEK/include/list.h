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
void freeList(ListNode* list);
void listPrint(ListNode* list);
ListNode* insertEnd(ListNode* list,int valeur);
ListNode* insertBeginning(ListNode* list,int valeur);
ListNode* insertMiddle(ListNode* list, int valeur, int element);
ListNode* insertMiddle(ListNode* list, int valeur, int element);
ListNode* deleteNode(ListNode* list, int valeur);
int searchNode(ListNode* list, int valeur);
ListNode* sorterList(ListNode* liste);



#endif