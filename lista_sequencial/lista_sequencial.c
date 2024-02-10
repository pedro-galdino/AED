#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void inicializar(lista *l) {
    l->particao = 0;
}

int inserir_fim(lista *l, int valor) {
    if(l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserir_inicio(lista *l, int valor) {
    int i;
    if(l->particao < MAX) {
        for(i = l->particao; i > 0; i--) {
            l->elementos[i] = l->elementos[i-1];
        }
        l->elementos[0] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserir_posicao(lista *l, int valor, int posicao) {
    int i;
    if(l->particao < MAX && l->particao >= posicao) {
        for(i = l->particao; i > posicao; i--) {
            l->elementos[i] = l->elementos[i-1];
        }
        l->elementos[posicao] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserir_ordem(lista *l, int valor) {
    int i, inserido = 0;
    if(l->particao < MAX) {
        for(i = 0; i < l->particao; i++) {
            if(l->elementos[i] > valor) {
                inserir_posicao(l, valor, i);
                inserido = 1;
                break;
            }
        }
        if(inserido == 0)
            inserir_fim(l, valor);
        return 1;
    } else {
        return 0;
    }
}

void exibir(lista *l) {
    int i;
    for(i = 0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

void reverso(lista *l) {
    int i;
    for(i = l->particao; i > 0; i--) {
        printf("[%d]", l->elementos[i-1]);
    }
    printf("\n");
}

int remover_fim(lista *l) {
    if(l->particao > 0) {
        l->particao--;
        return 1;
    } else {
        return 0;
    }
}

int remover_inicio(lista *l) {
    int i;
    if(l->particao > 0) {
        for(i = 0; i < l->particao-1; i++) {
            l->elementos[i] = l->elementos[i+1];
        }
        l->particao--;
        return 1;
    } else {
        return 0;
    }
}

int remover_posicao(lista *l, int posicao) {
    int i;
    if(l->particao > 0 && posicao < l->particao) {
        for(i = posicao; i < l->particao; i++) {
            l->elementos[i] = l->elementos[i+1];
        }
        l->particao--;
        return 1;
    } else {
        return 0;
    }
}

int remover_valor(lista *l, int valor) {
    int i, pos;
    if(l->particao > 0) {
        pos = procurar(l, valor);
        if(pos != -1) {
            remover_posicao(l, pos);
            return 1;
        } else
            return 0;
    } else {
        return 0;
    }
}

int procurar(lista *l, int n) {
    int i, pos = -1;
    for(i = 0; i < l->particao; i++) {
        if(l->elementos[i] == n){
            pos = i;
            break;
        }
    }
    return pos;
}

int somatorio(lista *l) {
    int i, soma = 0;
    for(i = 0; i < l->particao; i++) {
        soma += l->elementos[i];
    }
    return soma;
}

int tamanho(lista *l) {
    return l->particao;
}

void quadrado(lista *l) {
    int i;
    for(i = 0; i < l->particao; i++) {
        l->elementos[i] *= l->elementos[i];
    }
}

int primo(int valor) {
    int i, ehprimo = 1;
    if(valor <= 1)
        return 0;

    for(i = 2; i < valor; i++) {
        if(valor % i == 0){
            ehprimo = 0;
            break;
        }
    }
    if(ehprimo == 0)
        return 0;
    else
        return 1;
}

int qtd_primo(lista *l) {
    int i, qtd = 0;
    for(i = 0; i < l->particao; i++) {
        if(primo(l->elementos[i]) == 1)
            qtd++;
    }
    return qtd;
}

void inverte_lista(lista *l) {
    int i, j, aux;
    for(j = 0, i = l->particao-1; i > j; j++, i--) {
        aux = l->elementos[j];
        l->elementos[j] = l->elementos[i];
        l->elementos[i] = aux;
    }
    return l;
}
