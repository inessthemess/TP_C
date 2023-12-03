#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("Saisissez a, b et c d'un polynome du second degre\n");
    int a;
    int b;
    int c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("le polynome saisi est %dx^2 + %dx + %d\n",a,b,c);

    int delta = b*b - 4*a*c;
if (a!=0){
    if (delta > 0){
        float r1 = (-b -sqrt(delta))/(2*a);
        float r2 = (-b +sqrt(delta))/(2*a);
        printf("Le polynome a 2 racines réelles : r1 = %.2f et r2 = %.2f\n",r1,r2);
    }
    else if (delta == 0){
        float r = -b/(2*a);
        printf("Le polynome a une seule racine : r = %.2f\n",r);
    }
    else{
        float r1[2] = {-b/2*a, -sqrt(abs(delta)/(2*a))};
        float r2[2] = {-b/2*a, sqrt(abs(delta)/(2*a))};
        printf("Le polynome a 2 racines complexes : r1 = {%.2f,%.2f} et r2 = {%.2f,%.2f}\n",r1[0],r1[1],r2[0],r2[1]);

    }
}



    return 0;

}