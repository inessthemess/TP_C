#include <stdio.h>
#include <math.h>


int main(){

    int A[2] = {10,15};
    int B[2]= {5,20};


    /*traiter le cas B[0] = A[0]*/
    int pente = (B[1] - A[1])/(B[0] - A[0]);
    int dist = sqrt(((B[0] - A[0]) * (B[0] - A[0])) + ((B[1] - A[1]) * (B[1] - A[1])));
    int point_origine = A[1] - pente*A[0]; 
    int C[2];




    C[1] = 0;
    C[0] = -(point_origine)/pente;

    printf ("La pente entre A et B est %d, la distance est %d et les coordonnees de C sont {%d,%d}\n", pente, dist,C[0],C[1]);

    return 0;
}

