#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct fila {
        int elementos[MAX];
        int tamanho;
} fila;

void inicializar(fila *f) {
    f->tamanho = 0;
}

int isEmpty(fila *f) {
    if(f->tamanho == 0)
        return 1;
    else
        return 0;
}

int enqueue(fila *f, int valor) {
    if(f->tamanho < MAX) {
        f->elementos[f->tamanho] = valor;
        f->tamanho++;
        return 1;
    }
    else
        return 0;
}

int dequeue(fila *f) {
    int i;
    if(!isEmpty(f)) {
        for(i = 0; i < f->tamanho-1; i++)
            f->elementos[i] = f->elementos[i+1];
        f->tamanho--;
        return 1;
    }
    else
        return 0;
}

int peek(fila *f) {
    if(isEmpty(f))
        return -1;
    else
        return f->elementos[0];
}

void print(fila *f) {
    int i;
    for(i = 0; i < f->tamanho; i++)
        printf("[%d]", f->elementos[i]);
    printf("\n");
}

int main(int argc, char *argv) {
    fila *f;
    f = (fila *) malloc(sizeof(fila));
    inicializar(f);

    enqueue(f, 5);
    enqueue(f, 7);
    enqueue(f, 9);
    enqueue(f, 2);

    print(f);
    printf("primeiro elemento da fila: %d\n", peek(f));

    dequeue(f);
    print(f);
    printf("primeiro elemento da fila: %d\n", peek(f));

}
