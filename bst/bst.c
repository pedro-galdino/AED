#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir(arvore raiz, int valor) {
    if (raiz == NULL) {
        arvore nova = (arvore) malloc(sizeof(struct no));
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    }
    if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    } else {
        raiz->esq = inserir(raiz->esq, valor);
    }
    return raiz;
}

arvore remover(arvore raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor == raiz->valor) {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esq != NULL && raiz->dir == NULL) {
            arvore aux = raiz->esq;
            free(raiz);
            return aux;
        }
        else if (raiz->esq == NULL && raiz->dir != NULL) {
            arvore aux = raiz->dir;
            free(raiz);
            return aux;
        }
        else {
            int maiorSubarvoreEsquerda = maior_elemento(raiz->esq)->valor;
            raiz->valor = maiorSubarvoreEsquerda;
            raiz->esq = remover(raiz->esq, maiorSubarvoreEsquerda);
            return raiz;
        }
    }
    if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        raiz->esq = remover(raiz->esq, valor);
    }
    return raiz;
}

arvore maior_elemento(arvore raiz) {
    if (raiz->dir == NULL) {
        return raiz;
    }
    else {
        maior_elemento(raiz->dir);
    }
}

void preorder(arvore raiz) {
    if (raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz) {
    if (raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(arvore raiz) {
    if (raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

void reverso(arvore raiz) {
    if (raiz != NULL) {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}

int quantidade_par(arvore raiz) {
    int par = 0;

    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor % 2 == 0) {
        par++;
    }
    par += quantidade_par(raiz->esq) + quantidade_par(raiz->dir);
    return par;
}

int somatorio_par(arvore raiz) {
    int soma = 0;

    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor % 2 == 0) {
        soma += raiz->valor;
    }
    soma += somatorio_par(raiz->esq) + somatorio_par(raiz->dir);
    return soma;
}

arvore podar(arvore raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor == raiz->valor) {
        libera_arvore(raiz);
        return NULL;
    }
    if (valor > raiz->valor) {
        raiz->dir = podar(raiz->dir, valor);
    }
    else {
        raiz->esq = podar(raiz->esq, valor);
    }
    return raiz;
}

void libera_arvore(arvore raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}

void dobro(arvore raiz) {
    if (raiz != NULL) {
        raiz->valor *= 2;
        dobro(raiz->esq);        dobro(raiz->dir);
    }
}

int busca(arvore raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (valor == raiz->valor) {
        return 1;
    }
    if (valor > raiz->valor) {
        busca(raiz->dir, valor);
    }
    else {
        busca(raiz->esq, valor);
    }
}

int pai(arvore raiz, int valor) {
    if (raiz == NULL || valor == raiz->valor) {
        return -1;
    }
    if (raiz->dir != NULL && valor == raiz->dir->valor) {
        return raiz->valor;
    }
    if (raiz->esq != NULL && valor == raiz->esq->valor) {
        return raiz->valor;
    }
    if (valor > raiz->valor) {
        pai(raiz->dir, valor);
    }
    else {
        pai(raiz->esq, valor);
    }
}

int antecessor(arvore raiz, int valor) {
    int ante = -1;

    while (raiz != NULL) {
        if (valor == raiz->valor) {
            if (raiz->esq != NULL) {
                return maior_elemento(raiz->esq)->valor;
            }
            else {
                return ante;
            }
        }
        if (valor > raiz->valor) {
            if (ante < raiz->valor && valor > raiz->valor) {
                ante = raiz->valor;
            }
            raiz = raiz->dir;
        }
        else {
            if (valor > raiz->valor) {
                ante = raiz->valor;
            }
            raiz = raiz->esq;
        }
    }
    //raiz = NULL
    return -1;
}

void descendentes(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (valor == raiz->valor) {
            inorder(raiz->esq);
            inorder(raiz->dir);
        }
        if (valor > raiz->valor) {
            descendentes(raiz->dir, valor);
        }
        else {
            descendentes(raiz->esq, valor);
        }
    }
}

int altura(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        int he = altura(raiz->esq);
        int hd = altura(raiz->dir);
        if (he > hd) {
            return he + 1;
        }
        else {
            return hd + 1;
        }
    }
}
