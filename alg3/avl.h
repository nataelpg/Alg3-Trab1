#ifndef _LIBAVL_
#define _LIBAVL_

struct nodo {
    int chave;      
    int altura;
    struct nodo* esq;
    struct nodo* dir;
};
typedef struct nodo nodo_t;

nodo_t* cria_nodo(int valor);

void destroiArvore(nodo_t* nodo);

void printTree (nodo_t *n, int alturaArvore);

int max(int a, int b);

int altura (nodo_t *p);

int fatorBalanceamento(nodo_t *n);

nodo_t *tree_minimum(nodo_t *n);

nodo_t *tree_maximum(nodo_t *n);

nodo_t* rotEsq( nodo_t *x);

nodo_t* rotDir( nodo_t *x);

nodo_t *insereNo(nodo_t *n, int chave);

nodo_t* removeNo(nodo_t* nodo, int valor);

#endif