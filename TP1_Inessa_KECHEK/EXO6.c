/*nom,prenom + ce que fait la fonction*/

#include <stdio.h>




int main(){
    float f1;
    float f2;


    printf("Saisissez deux nombres reels\n");

    printf("Reel 1 :");
    scanf("%f",&f1);
    printf("\n");


    printf("Reel 2 :");
    scanf("%f",&f2);
    printf("\n");

    
    printf("L'addition des 2 nombres reels saisis est %.2f\n",f1 + f2);
    return 0;
}
