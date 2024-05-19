#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

typedef no* arvore;

arvore inserir (arvore raiz, int valor);
arvore remover (arvore raiz, int valor);
arvore maior_elemento(arvore raiz);
arvore podar(arvore raiz, int valor);
void libera_arvore(arvore raiz);

void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
void reverso(arvore raiz);

int quantidade_par(arvore raiz);
int somatorio_par(arvore raiz);
int busca(arvore raiz, int valor);
void dobro(arvore raiz);
void mesclar (arvore raiz1, arvore raiz2);
int pai(arvore raiz, int valor);
int antecessor(arvore raiz, int valor);
void descendentes(arvore raiz, int valor);
int altura(arvore raiz);

#endif
