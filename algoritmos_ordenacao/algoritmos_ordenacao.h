#ifndef ALGORITMOS_ORDENACAO_H
#define ALGORITMOS_ORDENACAO_H
#define MAX 1000

struct lista {
    int elementos[MAX];
    int particao;
};

void inicializar(struct lista *l);

int inserir_fim(struct lista *l, int valor);
int inserir_inicio(struct lista *l, int valor);
int inserir_posicao(struct lista *l, int valor, int posicao);
int inserir_ordem(struct lista *l, int valor);

void exibir(struct lista *l);
void reverso(struct lista *l);

int remover_fim(struct lista *l);
int remover_inicio(struct lista *l);
int remover_posicao(struct lista *l, int posicao);
int remover_valor(struct lista *l, int valor);

int procurar(struct lista *l, int n);
int somatorio(struct lista *l);
int tamanho(struct lista *l);
void quadrado(struct lista *l);
int primo(int valor);
int qtd_primo(struct lista *l);

void troca(struct lista *l, int a, int b);

void bubble_sort(struct lista *l);
void insertion_sort(struct lista *l);
void selection_sort(struct lista *l);

void merge(struct lista *l, int inicio, int meio, int fim);
void merge_sort(struct lista *l, int inicio, int fim);

int particiona(struct lista *l, int inicio, int fim);
void quick_sort(struct lista *l, int inicio, int fim);

int pai(int n);
void re_heap(struct lista * l, int inicio, int limite);
void heapfy(struct lista * l);
void heap_sort(struct lista * l);

#endif
