#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int main(int argc, char** argv){
    nodo_t* raiz = NULL;
    int valor;
    char c;
    scanf("%c", &c); 
    while(!feof(stdin))
    {
        if (c == 'i'){
            scanf("%d", &valor);
            raiz = insere(raiz, valor);
        }
        else if (c == 'r'){
            scanf("%d", &valor);
            raiz = remove(raiz, valor);
        }
    }   

    return 0;
}