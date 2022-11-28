#include "libavl.h"
#include <stdio.h>
#include <stdlib.h>
//aaaaa
nodo_t* cria_nodo(){
    nodo_t *n = malloc(sizeof(nodo_t));
    if (!n)
        return NULL;
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
/*     n->irmao = NULL; */
    n->pai = NULL;

    return n;
}

nodo_t *binario(nodo_t *n, int chave){
    if(n == NULL)
        return cria_nodo(chave);
    if(n->chave > chave)
        return binario(n->esq, chave);
    if(n->chave < chave)
        return binario (n->dir, chave);
    
    return n;
}

void printTree (nodo_t *n){
    if (n == NULL)
        return;
    printTree(n->esq);
    printf("%d", n->chave);
    printTree(n->dir);
}

void transplant(t, nodo_t *u, nodo_t* v){
    if(u.pai == NULL)
        t->raiz = v;
    else if (u == u->p->esq)
        u->p->esq = v;
    else
        u->p->dir = v;
    if (v != NULL)
        v->p = u->p;
}