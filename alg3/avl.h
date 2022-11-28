#ifndef _LIBavl_t_H
#define _LIBavl_t_H

struct nodo {
    int chave;       /* lista de numeros inteiros */
    int altura;
    struct nodo* esq;
    struct nodo* dir;
    struct nodo* irmao;
    struct nodo* pai;  /* ponteiro para o proximo   */
};
typedef struct nodo nodo_t;

struct arvore {
    nodo_t* raiz;      /* ponteiro para o inicio da lista */
    int tamanho;        /* numero de elementos na lista    */
};
typedef struct arvore arvore_t;

nodo_t *cria_nodo ();

nodo_t *binario(nodo_t *n, int chave);

void printTree(nodo_t *n);

void rotEsq(arvore_t* t, nodo_t* n);

void rotDir(arvore_t* t, nodo_t* n);

nodo_t* find_min(nodo_t* n);

nodo_t* find_max(nodo_t* n);

void treeDelete (arvore_t* t, nodo* n);

void transplant(arvore_t* t, nodo_t* u, nodo_t* v);

#endif