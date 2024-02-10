#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H
#define MAX 3

typedef struct lista{
        int elementos[MAX];
        int particao;
} lista;

void inicializar(lista *l);

int inserir_inicio(lista *l, int valor);
int inserir_fim(lista *l, int valor);
int inserir_posicao(lista *l, int valor, int posicao);
int inserir_ordem(lista *l, int valor);

void exibir(lista *l);
void reverso(lista *l);

int remover_inicio(lista *l);
int remover_fim(lista *l);
int remover_posicao(lista *l, int posicao);
int remover_valor(lista *l, int valor);

int procurar(lista *l, int n);
int somatorio(lista *l);
int tamanho(lista *l);
void quadrado(lista *l);
int qtd_primo(lista *l);
void inverte_lista(lista *l);

#endif
