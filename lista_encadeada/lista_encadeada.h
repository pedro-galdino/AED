#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef int tipo;

typedef struct no {
        int valor;
        struct no* proximo;
} no;

typedef no* lista;

lista inserir_fim(lista l, int valor);
lista inserir_inicio(lista l, int valor);
lista inserir_posicao(lista l, int posicao, int valor);
lista inserir_ordem(lista l, int valor);

lista remover_fim(lista l);
lista remover_inicio(lista l);
lista remover_posicao(lista l, int posicao);
lista remover_valor(lista l, int valor);

void exibir_lista(lista l);
void exibir_reverso(lista l);

lista procurar(lista l, int valor);
int somatorio(lista l, int n);
int tamanho(lista l);
void quadrado(lista l);
int primo(int valor);
int qtd_primo(lista l);
lista lista_soma(lista l);

#endif
