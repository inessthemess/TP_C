/***********************************************/
/* TP2                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    16/10/2023                        */
/***********************************************/
/*Dans ce TP notre objectif sera de coder un pilote automatique. Nous nous concentrerons sur l’aspect types 
de données et prototypes. Pour finir nous verrons comment compiler des projets un peu plus important*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./include/pilotAuto.h"






void test_altitude_attitude(aconst ltitude_attitude* a){
    if (a->angLateral >= ANGLE_SEUIL || a->angLongitudinal >= ANGLE_SEUIL || a->angVertical >= ANGLE_SEUIL || a->altitude <= ALTITUDE_SEUIL) {
        printf("ATTENTION : PROBLEME D'ALTITUDE OU D'ATTITUDE\n");}
}




void test_carburant(const carburant* c){
    if ((c->consommation_par_km * c->distance_a_parcourir) > c->quantite_carburant_initial) printf("ATTENTION : IL N'Y A PAS ASSEZ DE CARBURANT!\n");
}


void init_moteurs(moteurs tabmoteurs[4]){
    for (int i=0;i<4;i++){
        tabmoteurs[i].temperature = rand()% (TEMP_SEUIL-165) +165;
        tabmoteurs[i].prob_electronique = rand()%2;
        tabmoteurs[i].prob_mecanique = rand()%2;
    }
}




void test_moteurs(moteurs tabMoteurs[4]){
    int i=0;
    for(i=0;i<4;i++){
        if (tabMoteurs[i].temperature > TEMP_SEUIL || tabMoteurs[i].prob_electronique == 1 || tabMoteurs[i].prob_mecanique == 1) {
            printf("ATTENTION : PROBLEME AVEC LE MOTEUR %d\n",i);}
    }   
}




//nous supposons qu'un bouton ne peut etre allume a la fois
void test_boutons(int* b){
    *b = rand()% (3) + 1;
    switch(*b){
        case 1 : printf("ARRET DU PILOTE AUTOMATIQUE\n"); break;
        case 2 : printf("OUVERTURE DES VANNES DES RESERVES D'ESSENCES\n"); break;
        case 3 : printf("ALLUMER LES LUMIERES EXTERIEURS\n"); break;
        case 4 : printf("OUVERTURE DE LA PORTE DU COCKPIT\n"); break;
    }
}



