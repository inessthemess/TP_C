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




int main(){
    srand(time(NULL));
    moteurs tabMoteurs[4];
    int b = 0;


    //fonctions d'initialisation
    
    altitude_attitude a = {.altitude=600, .angLateral=25,.angLongitudinal=25,.angVertical=25};
    carburant c = {.consommation_par_km=2, .distance_a_parcourir=2000,.quantite_carburant_initial=5000};
    init_moteurs(tabMoteurs);

    //fonctions test
    test_altitude_attitude(&a);
    test_carburant(&c);
    test_moteurs(tabMoteurs);
    test_boutons(&b);

    return 0;
}