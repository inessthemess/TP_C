#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int res = 0;
    char word[100];
    printf("saissisez un mot :\n");
    scanf("%s",word);


    printf("quel caractère souhaitez-vous chercher dans le mot saisi?\n");
    char c;
    scanf("\r%c",&c);
    
    res = -1;
    for (int i = 0; i < strlen(word); i++ ){
        if ( c == word[i]){
            res = i;
        }
    }
    if (res>=0) printf("caractère trouvé a la position %d\n", res+1);
    else printf("caractère non-trouvé\n");
    return 0;
}


