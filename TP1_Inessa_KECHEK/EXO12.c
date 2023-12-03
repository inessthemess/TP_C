#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define CURRENT_YEAR 2023
#define SEUIL_GR 60



typedef struct _patient{
    char *nom;
    char *prenom;
    char *groupe_sanguin;
    int married; //est à 1 si le patient est marié 0 sinon
    char sexe;
    int age[3];
    int nb_enfants;
    float taux_gb_rouges;
    float taux_gb_blancs;
    int nb_plaquettes;
} Patient;


Patient* init_patient(const char *nom_p,const char *prenom_p,const char *groupe_sanguin_p,int ismarried,char sexe_p, int age_p[3], int nb_enfants_p,float taux_rouges,float taux_blancs,int nb_plaquettes_p){
    Patient* p = malloc(sizeof(Patient));
    p->nom = strdup(nom_p);
    p->prenom = strdup(prenom_p);
    p->groupe_sanguin =strdup(groupe_sanguin_p);
    p->married = ismarried;
    p->sexe = sexe_p;
    p->age[0] = age_p[0]; //day
    p->age[1] = age_p[1]; //month
    p->age[2] = age_p[2]; //year
    p->nb_enfants = nb_enfants_p;
    p->taux_gb_blancs = taux_blancs;
    p->taux_gb_rouges = taux_rouges;
    p->nb_plaquettes = nb_plaquettes_p;
    return p;
}

void free_patient (Patient* p){
    free(p->nom);
    free(p->prenom);
    free(p->groupe_sanguin);
    free(p);
}


int main(){
    int age[3] = {25,10,1956};
    Patient* p = init_patient("marie","drouet","AB",0,'F',age,0,50.0,40.0,200000);
    int age_patient = CURRENT_YEAR - p->age[2];
    if ((p->sexe == 'F') && (p->taux_gb_rouges < SEUIL_GR) && (age_patient > 65)){
        printf("ATTENTION : CONTACTER LA PATIENTE %s %s\n",p->nom,p->prenom);
    }
    free_patient(p);
    return 0;
}