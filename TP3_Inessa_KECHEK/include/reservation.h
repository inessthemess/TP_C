/***********************************************/
/* TP3                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    25/10/2023                        */
/***********************************************/

typedef struct _date{
    int jour;
    int mois;
    int annee;
}Date;



typedef struct _reservation{
    char* nom_reservation;
    Date date_arrivee;
    Date date_depart; 
    char* type_reservation;
}Reservation;




//renvoie 0 si la date d'arrivee de la 2eme reservation est posterieure ou egale a la date d'arrivee de la 1er reservation
int compare_date_reservation(Reservation r1,Reservation r2);
//tri a bulle des par date d'arrivee
void tri_a_bulle(Reservation r[]);
//test si c'est une année bissextile
int est_annee_bissextile(int annee) ;
//fonction qui calcule le nombre de moiss d'un mois dans une annee
int jours_dans_un_mois(int mois, int annee);
//fonction qui calcule le nombre de moiss depuis le 1er janvier selon une date donnee
int calcule_jours_du_debut(int jour, int mois, int annee);
//donne la duree de semois
int duree_sejour(Reservation r);
//calcule le prix a payer pour une reservation
int prix_a_payer(Reservation r);
//affiche les details de la reservation
void print_reservation(Reservation r[]);
//ecrit une page html qui contient les informations pour le devis
void print_reservation_html(Reservation r);
//ecrit un fichier html qui contient les info pour le devis
void ecrit_reservation_html(Reservation r,FILE* f);
//ecrit un fichier html qui contient toutes les reservations par ordre chronologique
void comptes_reservation_html(Reservation r[], FILE* f);