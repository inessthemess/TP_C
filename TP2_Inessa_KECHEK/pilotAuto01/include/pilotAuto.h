/***********************************************/
/* TP2                                         */
/* POLYTECH SORBONNE , FISE , LANGUAGE C       */
/*                                             */
/* auteur :     Inessa KECHEK                  */
/* date :    16/10/2023                        */
/***********************************************/


#define ANGLE_SEUIL 30
#define ALTITUDE_SEUIL 500
#define TEMP_SEUIL 500 //en FAHRENHEIT

typedef struct _altitude_attitude{
    float angVertical;
    float angLateral;
    float angLongitudinal;
    int altitude;
} altitude_attitude;

typedef struct _carburant{
    float distance_a_parcourir;
    int consommation_par_km;
    int quantite_carburant_initial;
} carburant;


typedef struct _moteurs{
    float temperature;
    int prob_electronique; //1 si il y a un probleme 0 sinon
    int prob_mecanique; //1 si il y a un probleme 0 sinon
    struct _moteurs* suivant;
} moteurs;

/*
//dans cette structure si l'entier est a 1 le bouton est allumé
typedef struct _boutons{
    int bleu;
    int rouge;
    int vert;
    int jeune;
} boutons;*/

//initialisation des angles d'attitudes et de l'altitude
altitude_attitude* init_altitude_attitude(float angle_lateral, float angle_longitudinal, float angle_vertical, int altitude);
//on desalloue la structure altitude_attitude
void free_altitude_attitude(altitude_attitude* a);
//test si on depasse les angles d'attitudes et l'altitude limite
void test_altitude_attitude(altitude_attitude* a);
//initialisation de la struct carburant
carburant* init_carburant(float dist_a_parcourir, int consommation_par_km, int quantite_carburant_initial);
//free de la struct carburant
void free_carburant(carburant* c);
//test si on a assez de carburant
void test_carburant(carburant* c);
//initialise un moteur avec des valeurs rand
moteurs* init_moteur();
//free de la liste des moteurs
void free_moteur(moteurs* listeMoteurs);
//test si tout va bien avec les moteurs
void test_moteurs(moteurs* listeMoteurs);
void test_boutons(int* b);
