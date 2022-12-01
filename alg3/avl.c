#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

nodo_t* cria_nodo(int chave){
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
nodo_t *binario(arvore_t *t,nodo_t *n, int chave){
    if(n == NULL)
        return cria_nodo(chave);
    if(n->chave > chave){ 
        n->esq = binario(t, n->esq, chave);
    }
    if(n->chave < chave){
        n->dir = binario (t, n->dir, chave);  
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

void treeDelete(arvore_t *t, nodo_t *z){
    if (z->esq == NULL)
        transplant(t, z, z->dir);
    else if (z->dir == NULL)
        Transplant(t, z, z->esq);
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
    return altura(n->esq) - altura(n->dir);
}

void insere(arvore_t* t, nodo_t* n, int chave){
    if (t->raiz == NULL){
        t->raiz = cria_nodo(chave);

        return;
    }
    if ((n->esq == NULL) && (n->dir == NULL))
        if (n->chave < n->chave){//se menor
            /* insere na esq */
            n->esq = cria_nodo(chave);
        }
        else{                   //se maior
            /* insere na dir */
            n->dir = cria_nodo(chave);
        }
    else
        if (n < chave)
            return insere(t, n->esq, chave);
        else
            return insere(t, n->dir, chave);

    return;
}