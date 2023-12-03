#include <stdio.h>


int compare_int(int* n1,int* n2){
    int tmp;
    if (*n2 > *n1){
        tmp = *n2;
        *n2 = *n1;
        *n1 = tmp;
        return 1;
    }
    return 0;
}


int main(){

    int N1;
    int N2;

    printf("Saisissez deux entiers\n\t");

    printf("N1 :");
    scanf("%d",&N1);
    printf("\n\t");


    printf("N2 :");
    scanf("%d",&N2);
    printf("\n");



    if ((compare_int(&N1,&N2))==1){
        printf("N2 est plus grand que N1. On interverti leur valeur.\n");
        printf("N1 = %d et N2 = %d\n",N1,N2);
    }
    else{
        printf("N2 est plus petit que N1. On ne change rien\n");
        printf("N1 = %d et N2 = %d\n",N1,N2);
    }

    return 0;
}