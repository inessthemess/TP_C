/***********************************************/
/* TP3                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    25/10/2023                        */
/***********************************************/


#include <stdio.h>
#include "reservation.h"



int main(){
    Reservation r[5]= {{.nom_reservation="MARIE",.date_arrivee.jour=12,.date_arrivee.mois=10,.date_arrivee.annee=2023,.date_depart.jour=12,.date_depart.mois=11,.date_depart.annee=2023,.type_reservation="suite"},
                       {.nom_reservation="JIWON",.date_arrivee.jour=1,.date_arrivee.mois=5,.date_arrivee.annee=2024,.date_depart.jour=11,.date_depart.mois=5,.date_depart.annee=2024,.type_reservation="chambre classique"},
                       {.nom_reservation="LUCA",.date_arrivee.jour=7,.date_arrivee.mois=12,.date_arrivee.annee=2023,.date_depart.jour=23,.date_depart.mois=12,.date_depart.annee=2023,.type_reservation="suite"},
                       {.nom_reservation="EMMA",.date_arrivee.jour=28,.date_arrivee.mois=4,.date_arrivee.annee=2024,.date_depart.jour=5,.date_depart.mois=5,.date_depart.annee=2024,.type_reservation="suite"},
                       {.nom_reservation="PHILIP",.date_arrivee.jour=13,.date_arrivee.mois=8,.date_arrivee.annee=2024,.date_depart.jour=30,.date_depart.mois=8,.date_depart.annee=2024,.type_reservation="chambre classique"}
                       };
    tri_a_bulle(r);
    print_reservation_html(r[0]);

    FILE* devis = fopen("devis.html","w");
    FILE* comptes = fopen("comptes.html", "w");
    ecrit_reservation_html(r[0],devis);
    comptes_reservation_html(r,comptes);
    fclose(devis);
    fclose(comptes);
    return 0;
}