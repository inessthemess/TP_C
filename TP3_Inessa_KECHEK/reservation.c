/***********************************************/
/* TP3                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    25/10/2023                        */
/***********************************************/




#include <stdio.h>
#include <string.h>
#include "reservation.h"


#define PRIX_SUITE 400
#define PRIX_CHAMBRE 60





int compare_date_reservation(Reservation r1, Reservation r2) {
    if (r2.date_arrivee.annee < r1.date_arrivee.annee) {
        return 1;
    }
    else if (r2.date_arrivee.annee > r1.date_arrivee.annee) {
        return 0;
    }
    
    
    if (r2.date_arrivee.mois < r1.date_arrivee.mois) {
        return 1; 
    }
    else if (r2.date_arrivee.mois > r1.date_arrivee.mois) {
        return 0;
    }
    

    if (r2.date_arrivee.jour < r1.date_arrivee.jour) {
        return 1;
    }
    
    return 0;
}



void tri_a_bulle(Reservation r[]) {
    int n=5;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <  n - i - 1; j++){
            if (compare_date_reservation(r[j],r[j+1])==1){ //si r[j]>r[j+1]
                Reservation temp = r[j];
                r[j] = r[j+1];
                r[j + 1] = temp;
            }
        }
    }
}






int est_annee_bissextile(int annee) {
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
        return 1;
    return 0;
}



int jours_dans_un_mois(int mois, int annee) {
    int jours[13] = { 0, 31, 28 + est_annee_bissextile(annee), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return jours[mois];
}



int calcule_jours_du_debut(int jour, int mois, int annee) {
    int jours_tot = 0;
    for (int y = 1; y < annee; y++) {
        jours_tot += 365 + est_annee_bissextile(y);
    }
    for (int m = 1; m < mois; m++) {
        jours_tot += jours_dans_un_mois(m, annee);
    }
    jours_tot += jour;
    return jours_tot;
}



int duree_sejour(Reservation r) {
    int jours1 = calcule_jours_du_debut(r.date_arrivee.jour, r.date_arrivee.mois, r.date_arrivee.annee);
    int jours2 = calcule_jours_du_debut(r.date_depart.jour, r.date_depart.mois, r.date_depart.annee);
    return jours2 - jours1;
}



int prix_a_payer(Reservation r){
    int prix = 0;
    int duree = duree_sejour(r);
    if (strcmp("suite",r.type_reservation)==0){
        prix = duree * PRIX_SUITE;
    }
    else if (strcmp("chambre classique",r.type_reservation)==0){
        prix = duree * PRIX_CHAMBRE;
    }
    else{
        printf("CE TYPE DE CHAMBRE N'EXISTE PAS\n");
    }
    return prix;
}


void print_reservation(Reservation r[]){
    for (int i=0;i<5;i++){
        printf("\t\tLa réservation est au nom de %s\n\n",r[i].nom_reservation);
        printf("\t\tLa date d'arrivée est le %d/%d/%d\n",r[i].date_arrivee.jour,r[i].date_arrivee.mois,r[i].date_arrivee.annee);
        printf("\t\tLa date de départ est le %d/%d/%d\n\n",r[i].date_depart.jour,r[i].date_depart.mois,r[i].date_depart.annee);
        printf("\t\tLa réservatione est pour une %s\n\n",r[i].type_reservation);
        printf("\t\tLe séjour dure %d jours\n",duree_sejour(r[i]));
        printf("\t\tLe prix à payer est %d euros\n\n\n\n\n\n",prix_a_payer(r[i]));
    }
}



void print_reservation_html(Reservation r){
    printf("<!DOCTYPE html>\n<html>\n");
    printf("\t<head>\n\t\t<title> FACTURE RÉSERVATION </title>\n\t</head>\n");
    printf("\t<body>\n\t\t<p> La réservation est au nom de %s </p>\n",r.nom_reservation);
    printf("\t\t<p> La date d'arrivée était le %d/%d/%d </p>\n",r.date_arrivee.jour,r.date_arrivee.mois,r.date_arrivee.annee);
    printf("\t\t<p> La date de départ est le %d/%d/%d </p>\n",r.date_depart.jour,r.date_depart.mois,r.date_depart.annee);
    printf("\t\t<p> Le séjour dure %d jours </p>\n",duree_sejour(r));
    printf("\t\t<p> Le montant du séjour s'élève à %d€ </p>\n",prix_a_payer(r));
    printf("\t</body>\n</html>\n");
}



void ecrit_reservation_html(Reservation r,FILE* f){
    fprintf(f,"<!DOCTYPE html>\n<html>\n");
    fprintf(f,"\t<head>\n\t\t<title> FACTURE RÉSERVATION </title>\n\t</head>\n");
    fprintf(f,"\t<body>\n\t\t<p> La réservation est au nom de %s </p>\n",r.nom_reservation);
    fprintf(f,"\t\t<p> La date d'arrivée était le %d/%d/%d </p>\n",r.date_arrivee.jour,r.date_arrivee.mois,r.date_arrivee.annee);
    fprintf(f,"\t\t<p> La date de départ est le %d/%d/%d </p>\n",r.date_depart.jour,r.date_depart.mois,r.date_depart.annee);
    fprintf(f,"\t\t<p> Le séjour dure %d jours </p>\n",duree_sejour(r));
    fprintf(f,"\t\t<p> Le montant du sejour s'élève à %d€ </p>\n",prix_a_payer(r));
    fprintf(f,"\t</body>\n</html>\n");
}



void comptes_reservation_html(Reservation r[], FILE* f){
    tri_a_bulle(r);
    fprintf(f,"<!DOCTYPE html>\n<html>\n");
    fprintf(f,"\t<head>\n\t\t<title> COMPTES RÉSERVATIONS </title>\n");
    fprintf(f,"\t\t<style>\n\t\ttable, th, td {\n\t\t\tborder: 1px solid white;\n\t\t\tborder-collapse: collapse;\t\t}\n");
    fprintf(f,"\t\tth, td {\n\t\t\tbackground-color: #EAD4DE;\n\t\t}\n");
    fprintf(f,"\t\t</style>\n\t</head>\n");
    fprintf(f,"\t<body>\n\t\t<table>\n\t\t\t<tr>\n");
    fprintf(f,"\t\t\t<th>NOM DE LA RÉSERVATION</th>\n");
    fprintf(f,"\t\t\t<th>DATE D'ARRIVÉE</th>\n");
    fprintf(f,"\t\t\t<th>DATE DE DÉPART</th>\n");
    fprintf(f,"\t\t\t<th>TYPE DE RÉSERVATION</th>\n");
    fprintf(f,"\t\t\t<th>DURÉE DU SÉJOUR</th>\n");
    fprintf(f,"\t\t\t<th>PRIX DU SÉJOUR</th>\n\t\t\t</tr>\n");
    for (int i = 0; i < 5; i++){
        fprintf(f,"\t\t\t<tr>\n");
        fprintf(f,"\t\t\t<td>%s </td>\n",r[i].nom_reservation);
        fprintf(f,"\t\t\t<td>%d/%d/%d</td>\n",r[i].date_arrivee.jour,r[i].date_arrivee.mois,r[i].date_arrivee.annee);
        fprintf(f,"\t\t\t<td>%d/%d/%d</td>\n",r[i].date_depart.jour,r[i].date_depart.mois,r[i].date_depart.annee);
        fprintf(f,"\t\t\t<td>%s</td>\n",r[i].type_reservation);
        fprintf(f,"\t\t\t<td>%d jours</td>\n",duree_sejour(r[i]));
        fprintf(f,"\t\t\t<td>%d€</td>\n",prix_a_payer(r[i]));
        fprintf(f,"\t\t\t</tr>\n");
    }
    fprintf(f,"\t\t</table>\n\t</body>\n</html>");
}

