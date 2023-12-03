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
#include "./include/pilotAuto.h"



altitude_attitude* init_altitude_attitude(float angle_lateral, float angle_longitudinal, float angle_vertical, int altitude){
    altitude_attitude* a=malloc(sizeof(altitude_attitude));
    a->angLateral = angle_lateral;
    a->angLongitudinal = angle_longitudinal;
    a->angVertical = angle_vertical;
    a->altitude = altitude;
    return a;
}



void free_altitude_attitude(altitude_attitude* a){
    free(a);
}



void test_altitude_attitude(altitude_attitude* a){
    if (a->angLateral >= ANGLE_SEUIL || a->angLongitudinal >= ANGLE_SEUIL || a->angVertical >= ANGLE_SEUIL || a->altitude <= ALTITUDE_SEUIL) {
        printf("ATTENTION : PROBLEME D'ALTITUDE OU D'ATTITUDE\n");}
}


carburant* init_carburant(float dist_a_parcourir, int consommation_par_km, int quantite_carburant_initial){
    carburant* c=malloc(sizeof(carburant));
    c->distance_a_parcourir = dist_a_parcourir;
    c->consommation_par_km = consommation_par_km;
    c->quantite_carburant_initial = quantite_carburant_initial;
    return c;
}

void free_carburant(carburant* c){
    free(c);
}

void test_carburant(carburant* c){
    if ((c->consommation_par_km * c->distance_a_parcourir) > c->quantite_carburant_initial) printf("ATTENTION : IL N'Y A PAS ASSEZ DE CARBURANT!\n");
}


moteurs* init_moteur(){
    moteurs* m=malloc(sizeof(moteurs));
    m->temperature = rand()% (TEMP_SEUIL-165) +165;
    m->prob_electronique = rand()%2;
    m->prob_mecanique = rand()%2;
    m->suivant = NULL;
    return m;
}

void free_listemoteur(moteurs* listeMoteurs){
    while (listeMoteurs){
        free(listeMoteurs);
        listeMoteurs=listeMoteurs->suivant;
    }
}

void test_moteurs(moteurs* listeMoteurs){
    int i=0;
    while (listeMoteurs){
        i++;
        if (listeMoteurs->temperature > TEMP_SEUIL || listeMoteurs->prob_electronique == 1 || listeMoteurs->prob_mecanique == 1) {
            printf("ATTENTION : PROBLEME AVEC LE MOTEUR %d\n",i);}
        listeMoteurs = listeMoteurs->suivant;
    }   
}

/*
//nous supposons qu'un bouton ne peut etre allume a la fois
void test_boutons(boutons* b){
    if (boutons->bleu == 1) printf("ARRET DU PILOTE AUTOMATIQUE\n");
    else if (boutons->rouge) printf("OUVERTURE DES VANNES DES RESERVES D'ESSENCES\n");
    else if (boutons->vert) printf("ALLUMER LES LUMIERES EXTERIEURS\n");
    else if (boutons->jaune) printf("OUVERTURE DE LA PORTE DU COCKPIT\n");
}
*/


//nous supposons qu'un bouton ne peut etre allume a la fois
void test_boutons(int* b){
    *b = rand()% (3) + 1;
    switch(*b){
        case 1 : printf("ARRET DU PILOTE AUTOMATIQUE\n");
        case 2 : printf("OUVERTURE DES VANNES DES RESERVES D'ESSENCES\n");
        case 3 : printf("ALLUMER LES LUMIERES EXTERIEURS\n");
        case 4 : printf("OUVERTURE DE LA PORTE DU COCKPIT\n");
    }
}



int main(){
    srand(time(NULL));
    moteurs* listeMoteurs = NULL;
    int b = 0;


    //fonctions d'initialisation
    altitude_attitude* a = init_altitude_attitude(25,20,14,600);
    carburant* c=init_carburant(2000,2, 5000);
    for (int i=0; i<4;i++){
        moteurs* listeMoteurs=init_moteur();
        listeMoteurs->suivant=listeMoteurs;
    }

    //fonctions test
    test_altitude_attitude(a);
    test_carburant(c);
    test_boutons(&b);


    //fonctions free
    free_altitude_attitude(a);
    free_carburant(c);
    free_listemoteur(listeMoteurs);
    return 0;
}