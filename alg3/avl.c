#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



nodo_t* cria_nodo(int valor){
    nodo_t *n = malloc(sizeof(nodo_t));
    if (!n)
        return NULL;
    n->chave = valor;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;

    return n;
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int altura (nodo_t *p) {
    int he, hd;
    if (p == NULL) return -1;
        he = altura (p->esq);
        hd = altura (p->dir);
    if (he > hd)
        return he+1;
    else
        return hd+1;    
}

int fatorBalanceamento(nodo_t *n){
    if (n == NULL)
        return 0;
    return (altura(n->esq) - altura(n->dir));
}

nodo_t *tree_minimum(nodo_t *n){
    if(n->esq)
        return tree_minimum(n->esq);
    return n;
}

nodo_t *tree_maximum(nodo_t *n){
    if(n->dir)
        return tree_maximum(n->dir);
    return n;
}



void printTree (nodo_t *n){
    if (n == NULL)
        return;
    printTree(n->esq);
    printf("%d", n->chave);
    printTree(n->dir);
}

nodo_t* rotEsq(arvore_t *t, nodo_t *x){
    nodo_t *y = x->dir;
    x->dir = y->esq;
    if(y->esq != NULL)
        y->esq->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        t->raiz = y;
    else if (x = x->pai->esq) 
        x->pai->esq = y;
    else 
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;  

    return y;     
}

nodo_t* rotDir(arvore_t *t, nodo_t *x){
    nodo_t *y = x->esq;
    x->esq = y->dir;
    if(y->dir != NULL)
        y->dir->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        t->raiz = y;
    else if (x == x->pai->dir) 
        x->pai->dir = y;
    else 
        x->pai->esq = y;
    y->dir = x;
    x->pai = y;       

    return y;
}
nodo_t *insere(arvore_t *t,nodo_t *n, int chave){
    if(n == NULL)
        return cria_nodo(chave);
    if(n->chave > chave){ 
        n->esq = insere(t, n->esq, chave);
    }
    if(n->chave < chave){
        n->dir = insere(t, n->dir, chave);  
    }
    
    n->altura = 1 + max(altura(n->esq), altura(n->dir));

    int fb = fatorBalanceamento(n);

    if(fb > 1 && chave < n->esq->chave)
        return rotDir(t, n);
    if(fb < -1 && chave > n->dir->chave)
        return rotEsq(t, n);
    if(fb > 1 && chave > n->esq->chave){
        n->esq = rotEsq(t, n->esq);
        return rotDir(t, n);
    }
    if(fb < -1 && chave < n->dir->chave){
        n->dir = rotDir(t, n->dir);
        return rotEsq(t, n);
    }
    
    return n;
}

nodo_t* removeNo(arvore_t* arvore, nodo_t* nodo, int chave){
    if(nodo == NULL)
        return nodo;

    while(nodo->chave != chave && nodo != NULL){
        if(chave < nodo->chave)
            nodo->esq = removeNo(arvore, nodo->esq, chave);
        
    }

}

void treeDelete(arvore_t *t, nodo_t *z){
    if (z->esq == NULL)
        transplant(t, z, z->dir);
    else if (z->dir == NULL)
        transplant(t, z, z->esq);
    else{
        nodo_t *y = tree_minimum(z->dir);
        if(y->pai != z){
            transplant (t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplant(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        
    }
}