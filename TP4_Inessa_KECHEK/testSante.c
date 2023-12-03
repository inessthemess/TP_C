/***********************************************/
/* TP4                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    27/11/2023                        */
/***********************************************/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"


#define TAILLE_TAB 5
#define RATION_ALIMENTAIRE_F 2200
#define RATION_ALIMENTAIRE_H 2800

#define POURCENTAGE_GLUCIDES 0.55
#define POURCENTAGE_LIPIDES 0.3
#define POURCENTAGE_PROTIDES 0.15

#define G 9.8

void print_infoPatient(InfoPatient* p){
    printf("Nom: %s\n",p->nom);
    printf("Prenom: %s\n",p->prenom);
    printf("Age: %d\n",p->age);
    printf("Taille: %.2f et Masse:%.2f\n",p->taille,p->masse);
    printf("Sexe: %c\n",p->sexe);
    printf("Groupe Sanguin: %c",p->groupe_sanguin[0]);
    if (p->groupe_sanguin[1]=='B') printf("%c",p->groupe_sanguin[1]);
    printf("%c\n",p->rhesus);
}



/*QUESTION 5*/
int* calcul_IMC(InfoPatient tab[]){
    int* res=(int*)malloc(sizeof(int)*TAILLE_TAB);
    for (int i=0; i < TAILLE_TAB; i++){
        int IMC = (int) tab[i].masse/(tab[i].taille*tab[i].taille);
        if (tab[i].sexe=='F' && IMC>=24) {res[i]=1; printf("%s est obèse\n",tab[i].prenom);}
        else if (tab[i].sexe=='H'&& IMC>=27) {res[i]=1; printf("%s est obèse\n",tab[i].prenom);}
        else {res[i]=0; printf("%s n'est pas obèse\n",tab[i].prenom);}
    }
    return res;
}



/*QUESTION 6*/
float* calcul_ration_alimentaire(char c){
    float* ration=(float*)malloc(sizeof(float)*3);
    if (c=='F'){
        float glucides=(RATION_ALIMENTAIRE_F*POURCENTAGE_GLUCIDES)/4;
        float lipides=(RATION_ALIMENTAIRE_F*POURCENTAGE_LIPIDES)/9;
        float protides=(RATION_ALIMENTAIRE_F*POURCENTAGE_PROTIDES)/4;
        ration[0]=glucides;
        ration[1]=lipides;
        ration[2]=protides;
        printf("Le nombre de glucides nécessaires pour une femme est %.2fg\n",glucides);
        printf("Le nombre de lipides nécessaires pour une femme est %.2fg\n",lipides);
        printf("Le nombre de protides nécessaires pour une femme est %.2fg\n",protides);
    }
    else if (c=='H'){
        float glucides=(RATION_ALIMENTAIRE_H*POURCENTAGE_GLUCIDES)/4;
        float lipides=(RATION_ALIMENTAIRE_H*POURCENTAGE_LIPIDES)/9;
        float protides=(RATION_ALIMENTAIRE_H*POURCENTAGE_PROTIDES)/4;
        ration[0]=glucides;
        ration[1]=lipides;
        ration[2]=protides;
        printf("Le nombre de glucides nécessaires pour un hommme est %.2fg\n",glucides);
        printf("Le nombre de lipides nécessaires pour un homme est %.2fg\n",lipides);
        printf("Le nombre de protides nécessaires pour un homme est %.2fg\n",protides);
    }
    return ration;

}


/*QUESTION 7*/
int calcul_kcal_repas(){
    /*Nous avons un repas de :
        -200g de steak haché
        -35g de beurre en total
        -150g de riz*/


//1,9g de protides, 0,3g de glucides, 4,6g de lipides dans 100g de steak haché
int kcal_steak=(int) 2*1.9*4 + 0.3*2*4 + 4.6*2*9; 

//0.7g de protides, 1g de glucides, 81.5g de lipides dans 100g de beurre
int kcal_beurretot=(int) ((0.7*35)/100)*4 + (1*35/100)*4 + (81.5*35/100)*9; 

//2.8g de protides, 31.1g de glucides, 0.4g de lipides dans 100g de riz
int kcal_riz=(int) (2.8*150/100)*4 + (31.1*150/100)*4 + (0.4*150/100)*9; 

return kcal_steak+kcal_beurretot+kcal_riz;

}


/*QUESTION 8*/
int calcul_kcal_sport(float taille,float masse,int pompes,int flexions){
    int energie_pompes=(int)(masse/2*G*taille/5)*pompes;
    int kcal_pompes=(int)energie_pompes/4182; //1kcal->4182J

    int energie_flexions=(int)(masse*0.75*G*taille/4)*flexions;
    int kcal_flexions=(int)energie_flexions/4182; //1kcal->4182J

    return kcal_pompes+kcal_flexions;
}

/*QUESTION 9*/
void ecrit_fichier(InfoPatient p){
    FILE* f = fopen("repas.txt","w");
    //on prend des valeurs aléatoires pour le nombre de glucides, lipides, protides et flexions
    fprintf(f,"%d %d %d %d %.2f %.2f\n",50,20,40,50,p.masse,p.taille); //petit-déjeuner
    fprintf(f,"%d %d %d %d %.2f %.2f\n",210,21,60,200,p.masse,p.taille); //déjeuner
    fprintf(f,"%d %d %d %d %.2f %.2f\n",60,20,10,150,p.masse,p.taille); //quart d'heure
    fprintf(f,"%d %d %d %d %.2f %.2f\n",70,10,55,50,p.masse,p.taille); //diner
    fclose(f);
}


/*QUESTION 10*/
int bilan_energetique(){
    FILE* f = fopen("repas.txt","r");
    int glucides,lipides,protides;
    int flexions;
    float masse,taille;
    int kcal_repas=0;
    int kcal_flexions=0;
    while (fscanf(f,"%d %d %d %d %f %f\n",&glucides,&lipides,&protides,&flexions,&masse,&taille)!=EOF){
        kcal_repas+= glucides*4 + lipides*9 + protides*4;
        kcal_flexions+=calcul_kcal_sport(taille,masse,0,flexions);
    }
    fclose(f);
    return kcal_repas - kcal_flexions;
}