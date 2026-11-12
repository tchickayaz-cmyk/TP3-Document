#include <stdio.h>
#include <assert.h>
#include "pile.h"
#include "file.h"
#include "postfixe.h"
#include "parenthese.h"

int main(){
    // Test Pile
    Pile p; pile_init(&p);
    assert(pile_vide(&p));
    pile_push(&p, 10); pile_push(&p, 20);
    assert(pile_sommet(&p)==20);
    assert(pile_pop(&p)==20); assert(pile_pop(&p)==10);
    assert(pile_vide(&p));
    printf("Pile OK\n");
    pile_detruire(&p);

    // Test File
    File f; file_init(&f);
    assert(file_vide(&f));
    file_enfiler(&f, 1); file_enfiler(&f, 2); file_enfiler(&f, 3);
    assert(file_tete(&f)==1);
    assert(file_defiler(&f)==1); assert(file_defiler(&f)==2);
    assert(f.taille==1);
    file_detruire(&f);
    printf("File OK\n");

    // Test Postfixe - §5.3 du cours
    int res;
    assert(eval_postfixe("3 4 +", &res) && res==7);
    assert(eval_postfixe("5 1 2 + 4 * + 3 -", &res) && res==14); // 5 + (1+2)*4 -3
    assert(eval_postfixe("2 3 1 * + 9 -", &res) && res==-4);
    assert(eval_postfixe("4 0 /", &res)==0); // division par zero -> invalide
    assert(eval_postfixe("4 +", &res)==0); // invalide
    assert(eval_postfixe("10 2 8 * + 3 -", &res) && res==23);
    printf("Postfixe OK - expressions valides, invalides, division par zero testes\n");

    // Test Parenthésage - TD3 Q1
    assert(verif_parenthesage("(a+b)")==true);
    assert(verif_parenthesage("((a+b)*[c-d])")==true);
    assert(verif_parenthesage("{[()]}")==true);
    assert(verif_parenthesage("(a+b]")==false); // mal imbriquées
    assert(verif_parenthesage("((a+b)")==false); // manquante
    assert(verif_parenthesage(")()(")==false);
    assert(verif_parenthesage("")==true);
    printf("Parenthesage OK - valides, invalides, mal imbriquees testes\n");

    printf("\nTOUS LES TESTS TP3 PASSENT - Valgrind 0 fuite attendu\n");
    return 0;
}
