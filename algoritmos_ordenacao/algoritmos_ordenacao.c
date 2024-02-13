#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_ordenacao.h"

void inicializar(struct lista *l) {
    l->particao = 0;
}

int inserir_fim(struct lista *l, int valor) {
    if(l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserir_inicio(struct lista *l, int valor) {
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

int inserir_posicao(struct lista *l, int valor, int posicao) {
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

int inserir_ordem(struct lista *l, int valor) {
    int i, inserido = 0;
    if(l->particao < MAX) {
        for(i = 0; i<l->particao; i++) {
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

void exibir(struct lista *l) {
    int i;
    for(i = 0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

void reverso(struct lista *l) {
    int i;
    for(i = l->particao; i > 0; i--) {
        printf("[%d]", l->elementos[i-1]);
    }
    printf("\n");
}

int remover_fim(struct lista *l) {
    if(l->particao > 0){
        l->particao--;
        return 1;
    } else {
        return 0;
    }
}

int remover_inicio(struct lista *l) {
    int i;
    if(l->particao > 0){
        for(i = 0; i < l->particao-1; i++) {
            l->elementos[i] = l->elementos[i+1];
        }
        l->particao--;
        return 1;
    } else {
        return 0;
    }
}

int remover_posicao(struct lista *l, int posicao) {
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

int remover_valor(struct lista *l, int valor) {
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

int procurar(struct lista *l, int n) {
    int i, pos = -1;
    for(i = 0; i < l->particao; i++) {
        if(l->elementos[i] == n){
            pos = i;
            break;
        }
    }
    return pos;
}

int somatorio(struct lista *l) {
    int i, soma = 0;
    for(i = 0; i < l->particao; i++) {
        soma += l->elementos[i];
    }
    return soma;
}

int tamanho(struct lista *l) {
    return l->particao;
}

void quadrado(struct lista *l) {
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

int qtd_primo(struct lista *l){
    int i, qtd = 0;
    for(i = 0; i < l->particao; i++) {
        if(primo(l->elementos[i]) == 1)
            qtd++;
    }
    return qtd;
}

void troca(struct lista *l, int a, int b) {
    int temp = l->elementos[a];
    l->elementos[a] = l->elementos[b];
    l->elementos[b] = temp;
}

void bubble_sort(struct lista *l) {
    int i, j;

    for(i = 0; i < l->particao - 1; i++)
        for(j = l->particao - 1; j > i; j--)
            if(l->elementos[j] < l->elementos[j-1])
                troca(l, j, j-1);
}

void insertion_sort(struct lista *l) {
    int i, j, chave;

    for(i = 1; i < l->particao; i++) {
        chave = l->elementos[i];
        j = i - 1;
        while(j >= 0 && l->elementos[j] > chave) {
            l->elementos[j+1] = l->elementos[j];
            j--;
        }
        l->elementos[j+1] = chave;
    }
}

void selection_sort(struct lista *l) {
    int i, j, posicao_menor;

    for(j = 0; j < l->particao - 1; j++) {
        posicao_menor = j;
        for(i = j + 1; i < l->particao; i++) {
            if(l->elementos[i] < l->elementos[posicao_menor])
                posicao_menor = i;
        }
        troca(l, j, posicao_menor);
    }
}

void merge_sort(struct lista *l, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        merge_sort(l, inicio, meio);
        merge_sort(l, meio, fim);
        merge(l, inicio, meio, fim);
    }
}

void merge(struct lista *l, int inicio, int meio, int fim) {
    int *temp;
    int i, j, k;
    int tamanho = fim - inicio;

    temp = (int *)malloc(sizeof(int) * tamanho);

    for (i = inicio, j = meio, k = 0; i < meio && j < fim; k++) {
        if (l->elementos[i] <= l->elementos[j]) {
            temp[k] = l->elementos[i];
            i++;
        } else {
            temp[k] = l->elementos[j];
            j++;
        }
    }

    while (i < meio) {
        temp[k] = l->elementos[i];
        i++;
        k++;
    }

    while (j < fim) {
        temp[k] = l->elementos[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; k < tamanho; k++, i++) {
        l->elementos[i] = temp[k];
    }

    free(temp);
}

int particiona(struct lista *l, int inicio, int fim) {
    int i, j, pivo = inicio;
    i = inicio;

    for(j = inicio + 1; j <= fim; j++) {
        if(l->elementos[j] < l->elementos[pivo]) {
            i++;
            troca(l, i, j);
        }
    }

    troca(l, pivo, i);
    return i;
}

void quick_sort(struct lista *l, int inicio, int fim) {
    if (fim > inicio) {
		int pivo = particiona(l, inicio, fim);
		quick_sort(l, inicio, pivo - 1);
		quick_sort(l, pivo + 1, fim);
	}
}

int pai(int n) {
    if(n > 0) {
        return (n-1) / 2;
    } else {
        return -1;
    }
}

void re_heap(struct lista * l, int inicio, int limite) {
    int maior = inicio;
    int filhoe = 2 * inicio + 1;
    int filhod = 2 * inicio + 2;

    if (filhoe < limite && l->elementos[filhoe] > l->elementos[maior])
        maior = filhoe;

    if (filhod < limite && l->elementos[filhod] > l->elementos[maior])
        maior = filhod;

    if (maior != inicio) {
        troca(l, inicio, maior);
        re_heap(l, maior, limite);
    }
}

void heapfy(struct lista * l) {
    int i, p, j;
    for(i = 1; i < l->particao; i++) {
        for(j = i; j > 0; j = pai(j)) {
            p = pai(j);
            if(l->elementos[j] > l->elementos[p]) {
                troca(l, j, p);
            } else {
                break;
            }
        }
    }
}

void heap_sort(struct lista * l) {
    int i;
    heapfy(l);

    for(i = l->particao-1; i > 0; i--) {
        troca(l, 0, i);
        re_heap(l, 0, i);
    }
}
