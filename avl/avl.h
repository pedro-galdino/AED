#ifndef AVL_H
#define AVL_H

typedef struct no {
    int valor;
    int fb;
    struct no *esq;
    struct no *dir;
} no;

typedef no* arvore;

arvore novo_no(int valor);
arvore inserir(arvore raiz, int valor, int *cresceu);
arvore remover(arvore raiz, int valor, int *diminuiu);

int maior(int a, int b);
int altura(arvore raiz);

arvore maior_elemento(arvore raiz);
arvore rotacao(arvore pivo);
arvore rotacao_simples_direita(arvore pivo);
arvore rotacao_simples_esquerda(arvore pivo);
arvore rotacao_dupla_direita(arvore pivo);
arvore rotacao_dupla_esquerda(arvore pivo);

void balanceamento_rot_direita(arvore pivo);
void balanceamento_rot_esquerda(arvore pivo);
void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);

#endif
