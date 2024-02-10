#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct pilha {
        int elementos[MAX];
        int topo;
} pilha;

void inicializar(pilha *p) {
    p->topo = 0;
}

int isEmpty(pilha *p) {
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

int push(pilha *p, int valor) {
    if(p->topo < MAX) {
        p->elementos[p->topo] = valor;
        p->topo++;
        return 1;
    }
    else
        return 0;
}

int pop(pilha *p) {
    if(!isEmpty(p)) {
        p->topo--;
        return 1;
    }
    else
        return 0;
}

int top(pilha *p) {
    if(!isEmpty(p))
        return p->elementos[p->topo-1];
    else
        return -1;
}

void print(pilha *p) {
    int i;
    for(i = p->topo; i > 0; i--)
        printf("[%d]\n", p->elementos[i-1]);
}

int main(int argc, char *argv) {
    pilha *p;
    p = (pilha *) malloc(sizeof(pilha));
    inicializar(p);

    push(p, 5);
    push(p, 7);
    push(p, 9);
    push(p, 2);

    print(p);
    printf("elemento do topo: %d\n", top(p));

    pop(p);
    print(p);
    printf("elemento do topo: %d\n", top(p));

}
