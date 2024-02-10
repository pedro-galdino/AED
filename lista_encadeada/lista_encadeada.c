#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio(lista l, int valor) {
    lista novo = (lista) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = l;
    return novo;
}

lista inserir_fim(lista l, int valor) {
    lista aux = l;
    lista novo = (lista) malloc(sizeof(no));

    if(l == NULL)
        return inserir_inicio(l, valor);

    while(aux->proximo != NULL)
        aux = aux->proximo;

    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;
    return l;
}

lista inserir_posicao(lista l, int posicao, int valor) {
    int cont = 1;
    lista aux = l;
    lista novo = (lista) malloc(sizeof(no));

    if(posicao == 0)
        return inserir_inicio(l, valor);

    if(posicao > tamanho(l))
        return inserir_fim(l, valor);

    while(cont != posicao) {
        aux = aux->proximo;
        cont++;
    }
    novo->valor = valor;
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    return l;
}

lista inserir_ordem(lista l, int valor) {
    int cont = 0;
    lista aux = l;

    if(l == NULL)
        return inserir_inicio(l, valor);

    while(valor > aux->valor) {
        if(aux->proximo == NULL)
            return inserir_fim(l, valor);
        aux = aux->proximo;
        cont++;
    }
    return inserir_posicao(l, cont, valor);
}

lista remover_inicio(lista l) {
    if(l == NULL)
        return NULL;

    lista aux = l->proximo;
    free(l);
    return aux;
}

lista remover_fim(lista l) {
    if(l == NULL)
        return NULL;

    if(l->proximo == NULL)
        return remover_inicio(l);

    lista aux = l;
    while(aux->proximo->proximo != NULL)
        aux = aux->proximo;

    free(aux->proximo);
    aux->proximo = NULL;
    return l;
}

lista remover_posicao(lista l, int posicao) {
    if(l == NULL)
        return NULL;

    if(posicao > tamanho(l)-1)
        return l;

    if(posicao == 0)
        return remover_inicio(l);

    int cont = 1;
    lista aux = l;
    lista temp;

    while(posicao != cont) {
        aux = aux->proximo;
        cont++;
    }

    temp = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(temp);
    return l;
}

lista remover_valor(lista l, int valor) {
    if(l == NULL)
        return NULL;

    if(l->valor == valor)
        return remover_inicio(l);

    lista aux = l;

    while(aux->proximo != NULL && aux->proximo->valor != valor)
        aux = aux->proximo;

    if(aux->proximo == NULL)
        return l;

    lista temp = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(temp);
    return l;
}

lista procurar(lista l, int n) {
    lista aux = l;

    if(aux == NULL)
        return NULL;

    while(aux != NULL && n != aux->valor)
        aux = aux->proximo;

    if(aux == NULL)
        return NULL;

    return aux;
}

void exibir_lista(lista l) {
    lista aux = l;

    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void exibir_reverso(lista l) {
    if(l == NULL)
        return;
    exibir_reverso(l->proximo);
    printf("[%d]", l->valor);
}

int somatorio(lista l, int n) {
    lista aux = l;
    int soma = 0;

    if(aux == NULL)
        return 0;

    while(aux != NULL && n > 0) {
        soma += aux->valor;
        aux = aux->proximo;
        n--;
    }

    if(aux == NULL && n > 0)
        return -1;

    return soma;
}

int tamanho(lista l) {
    int cont = 1;
    if(l == NULL)
        return 0;

    while(l->proximo != NULL) {
        l = l->proximo;
        cont++;
    }
    return cont;
}

void quadrado(lista l) {
    while(l != NULL) {
        l->valor *= l->valor;
        l = l->proximo;
    }
}

int primo(int valor) {
    int i, ehprimo = 1;
    if(valor <= 1)
        return 0;

    for(i = 2; i < valor; i++) {
        if(valor % i == 0) {
            ehprimo = 0;
            break;
        }
    }
    if(ehprimo == 0)
        return 0;
    else
        return 1;
}

int qtd_primo(lista l) {
    int cont = 0;
    if(l == NULL)
        return 0;

    while(l != NULL) {
        if(primo(l->valor) == 1)
            cont++;
            l = l->proximo;
    }
    return cont;
}

lista lista_soma(lista l) {
    int soma = 0;
    lista aux = l;
    lista sum = NULL;

    while(aux != NULL) {
        soma += aux->valor;
        sum = inserir_fim(sum, soma);
        aux = aux->proximo;
    }

    return sum;
}
