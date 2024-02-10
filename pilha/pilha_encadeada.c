#include <stdio.h>
#include <stdlib.h>

typedef struct no {
        int valor;
        struct no* proximo;
} no;

typedef no* pilha;

int isEmpty(pilha p) {
    if(p == NULL)
        return 1;
    else
        return 0;
}

pilha push(pilha p, int valor) {
    pilha novo = (pilha) malloc(sizeof(no));
    pilha aux = p;

    if(isEmpty(p)) {
        novo->valor = valor;
        novo->proximo = NULL;
        return novo;
    }
    while(aux->proximo != NULL)
        aux = aux->proximo;

    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;
    return p;
}

pilha pop(pilha p) {
    if(isEmpty(p))
        return NULL;

    if(p->proximo == NULL){
        free(p);
        return NULL;
    }
    pilha aux = p;
    while(aux->proximo->proximo != NULL)
        aux = aux->proximo;

    free(aux->proximo);
    aux->proximo = NULL;
    return p;
}

int top(pilha p) {
    pilha aux = p;

    if(!isEmpty(p)) {
        while(aux->proximo != NULL)
            aux = aux->proximo;
        return aux->valor;
    }
    else
        return -1;
}

void print(pilha p) {
    if(p == NULL)
        return ;

    print(p->proximo);
    printf("[%d]\n", p->valor);
}

int main(int argc, char *argv) {
    pilha p = NULL;

    p = push(p, 5);
    p = push(p, 7);
    p = push(p, 9);
    p = push(p, 2);

    print(p);
    printf("elemento do topo: %d\n", top(p));

    p = pop(p);
    print(p);
    printf("elemento do topo: %d\n", top(p));

}
