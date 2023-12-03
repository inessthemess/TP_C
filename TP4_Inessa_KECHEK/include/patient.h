/***********************************************/
/* TP4                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    27/11/2023                        */
/***********************************************/


/*QUESTION 2*/
typedef struct _infopatient{
    char* nom;
    char* prenom;
    int age;
    float taille; //en m
    float masse; //en kg
    char sexe;
    char groupe_sanguin[2];
    char rhesus;
}InfoPatient;

//affiche les informations d'un patient
void print_infoPatient(InfoPatient* p);
//calcule le IMC d'un tableau de patient et retourne un tableau contenant 1 si le patient est obèse, 0 sinon
int* calcul_IMC(InfoPatient tab[]);
//calcule le nombre de gramme de glucide, lipide et protide nécessaire pour un homme ou une femme
float* calcul_ration_alimentaire(char c);
//calcule le nombre de kcal absorbées lors d'un repas
int calcul_kcal_repas();
//calcule le nombre de kcal consommé lors d'une activité sportive
int calcul_kcal_sport(float taille,float masse,int pompes,int flexions);
//écrit dans un fichier le nombre de glucide,lipide et protide consommé durant chaque repas ainsi que le nombre de flexions effectué
void ecrit_fichier(InfoPatient p);
//recupère les info figurant dans le fichier écrit précédemment et calcule le bilan énergétique de la journée
int bilan_energetique();