#include <stdio.h>
#include <stdlib.h>

typedef struct no {
        int valor;
        struct no* proximo;
} no;

typedef no* fila;

int isEmpty(fila f) {
    if(f == NULL)
        return 1;
    else
        return 0;
}

fila enqueue(fila f, int valor) {
    fila novo = (fila) malloc(sizeof(no));

    if(isEmpty(f)) {
        novo->valor = valor;
        novo->proximo = NULL;
        return novo;
    }

    fila aux = f;

    while(aux->proximo != NULL)
        aux = aux->proximo;

    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;

    return f;
}

fila dequeue(fila f) {
    if(f == NULL)
        return NULL;

    fila aux = f->proximo;
    free(f);
    return aux;
}

int peek(fila f) {
    if(isEmpty(f))
        return -1;
    else
        return f->valor;
}

void print(fila f) {
    fila aux = f;

    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

int main(int argc, char *argv) {
    fila f = NULL;

    f = enqueue(f, 5);
    f = enqueue(f, 7);
    f = enqueue(f, 9);
    f = enqueue(f, 2);

    print(f);
    printf("primeiro elemento da fila: %d\n", peek(f));

    f = dequeue(f);
    print(f);
    printf("primeiro elemento da fila: %d\n", peek(f));

}
