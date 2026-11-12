#include "pile.h"
#include "parenthese.h"
bool verif_parenthesage(const char* expr){
    Pile p; pile_init(&p);
    for(int i=0; expr[i]!='\0'; i++){
        char c=expr[i];
        if(c=='(' || c=='{' || c=='['){ pile_push(&p, c); }
        else if(c==')' || c=='}' || c==']'){
            if(pile_vide(&p)){ pile_detruire(&p); return false; }
            int o=pile_pop(&p);
            if((c==')' && o!='(') || (c=='}' && o!='{') || (c==']' && o!='[')){ pile_detruire(&p); return false; }
        }
    }
    bool ok = pile_vide(&p);
    pile_detruire(&p);
    return ok;
}
