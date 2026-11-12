#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pile.h"
#include "postfixe.h"
int eval_postfixe(const char* expr, int* resultat){
    Pile p; pile_init(&p);
    char* copy = strdup(expr);
    char* tok = strtok(copy, " ");
    while(tok){
        if(isdigit(tok[0]) || (tok[0]=='-' && isdigit(tok[1]))){
            pile_push(&p, atoi(tok));
        } else if(strlen(tok)==1){
            if(p.taille < 2){ free(copy); pile_detruire(&p); return 0; }
            int b = pile_pop(&p);
            int a = pile_pop(&p);
            int r=0;
            switch(tok[0]){
                case '+': r=a+b; break;
                case '-': r=a-b; break;
                case '*': r=a*b; break;
                case '/': if(b==0){ free(copy); pile_detruire(&p); return 0; } r=a/b; break;
                case '%': if(b==0){ free(copy); pile_detruire(&p); return 0; } r=a%b; break;
                default: free(copy); pile_detruire(&p); return 0;
            }
            pile_push(&p, r);
        } else { free(copy); pile_detruire(&p); return 0; }
        tok = strtok(NULL, " ");
    }
    if(p.taille != 1){ free(copy); pile_detruire(&p); return 0; }
    *resultat = pile_pop(&p);
    free(copy);
    pile_detruire(&p);
    return 1;
}
