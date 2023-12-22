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



int main(){

    //ListNode* list=init_node(2);

    int nbNode=10;
    ListNode* list=NULL;
    ListNode* tmp = NULL;
    for (int i=1; i <= nbNode; i++){
        ListNode* node=initNode(i);
        if (list==NULL){
            list=node;
            tmp=node;
        }
        else{
            tmp->suiv=node;
            tmp=node;
        }
    }

    list=insertEnd(list,11);
    list=insertBeginning(list,0);
    list=insertMiddle(list,12,5);
    list=deleteNode(list,6);
    listPrint(list);
    int i=searchNode(list,6);
    list=sorterList(list);
    listPrint(list);
    freeList(list);
    return 0;
}
