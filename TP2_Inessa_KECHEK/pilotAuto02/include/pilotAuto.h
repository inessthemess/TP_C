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
} moteurs;



//test si on depasse les angles d'attitudes et l'altitude limite
void test_altitude_attitude(altitude_attitude* a);
//initialisation de la struct carburant
//test si on a assez de carburant
void test_carburant(carburant* c);
//initialise un moteur avec des valeurs rand
void init_moteurs(moteurs tabmoteurs[4]);
//free de la liste des moteurs
//test si tout va bien avec les moteurs
void test_moteurs(moteurs tabMoteurs[4]);
void test_boutons(int* b);
