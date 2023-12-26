/***********************************************/
/* TP6                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    22/12/2023                        */
/***********************************************/

#ifndef _LIST_H
#define _LIST_H

typedef struct _TreeNode{
    int data;
    struct _TreeNode* gauche;
    struct _TreeNode* droit;
}TreeNode;

//crée un nouveau noeud
TreeNode* newNode(int valeur);
//desalloue un arbre binaire de recherche
void freeAbr(TreeNode* abr);
//affiche un arbre binaire (parcours préfixe)
void printAbr(TreeNode* abr);
//ajoute un élément dans l'arbre de manière ordonné
TreeNode* insert(TreeNode* abr,int valeur);
//lire les valeurs en ordre croissant
void inorder(TreeNode* abr);
TreeNode* delete(TreeNode* abr, int valeur);
#endif