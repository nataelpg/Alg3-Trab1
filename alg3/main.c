#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int main(int argc, char** argv){
    arvore_t* arvore = cria_arvore();
    nodo_t* nodo = NULL;
    int valor;
    char c;
    scanf("%c", &c); 
    while(!feof(stdin))
    {
        if (c == 'i'){
            scanf("%d", &valor);
            nodo = cria_nodo(valor);
            nodo = insere(arvore, nodo, valor);
            printf ("altura esq: %d\n", arvore->raiz->esq->altura);
            printf ("altura dir: %d\n", arvore->raiz->dir->altura);
        }
        else if (c == 'r'){
            scanf("%d", &valor);
            nodo = removeNo(arvore, nodo, valor);
        }
    }   

    return 0;
}