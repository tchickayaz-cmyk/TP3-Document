#include <stdio.h>
#include "postfixe.h"
int main(){
    char ligne[256];
    printf("Calculatrice postfixe (ex: 3 4 +) - tape q pour quitter\n");
    while(1){
        printf("> "); if(!fgets(ligne,256,stdin)) break;
        if(ligne[0]=='q') break;
        int res; if(eval_postfixe(ligne, &res)) printf("= %d\n", res);
        else printf("Erreur: expression invalide ou division par zero\n");
    }
    return 0;
}
