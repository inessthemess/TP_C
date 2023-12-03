/***********************************************/
/* TP4                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    27/11/2023                        */
/***********************************************/



#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int main(){


/*QUESTION 3*/
//InfoPatient p={.nom="Maries",.prenom="Drouet",.age=21,.taille=1.75,.masse=55.7,.sexe='F',.groupe_sanguin[0]='A',.groupe_sanguin[1]='B',.rhesus='+'};


/*QUESTION 4*/
InfoPatient tab[5]={{.prenom="Réné",.nom="Girard",.age=54,.taille=1.74,.masse=92,.sexe='H',.groupe_sanguin[0]='A',.groupe_sanguin[1]='B',.rhesus='+'},
                    {.prenom="Annie",.nom="Cordie",.age=40,.taille=1.62,.masse=64,.sexe='F',.groupe_sanguin[0]='O',.rhesus='-'},
                    {.prenom="Sylvain",.nom="Martinez",.age=35,.taille=1.84,.masse=81,.sexe='H',.groupe_sanguin[0]='B',.rhesus='+'},
                    {.prenom="Manuel",.nom="Delavilla",.age=25,.taille=1.76,.masse=85,.sexe='H',.groupe_sanguin[0]='A',.rhesus='-'},
                    {.prenom="Mathilde",.nom="Bramouche",.age=65,.taille=1.73,.masse=66,.sexe='F',.groupe_sanguin[0]='O',.rhesus='+'}};

int* res=calcul_IMC(tab);
printf("\n");
float* ration=calcul_ration_alimentaire('H');
printf("\n");
printf("%dkcal pour le repas de la question 7\n",calcul_kcal_repas());
printf("\n");
printf("%dkcal pour les pompes et flexions de la question 8 pour %s %s\n",calcul_kcal_sport(tab[0].taille,tab[0].masse,100,200),tab[0].prenom,tab[0].nom);

ecrit_fichier(tab[0]);
printf("\n");

int bilan = bilan_energetique();
printf("Le bilan énergétique de la journée pour %s %s est %dkcal\n",tab[0].prenom,tab[0].nom,bilan);


free(res);
free(ration);

return 0;
}