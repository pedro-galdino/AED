#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

arvore novo_no(int valor) {
    arvore novo = (arvore) malloc(sizeof(struct no));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->fb = 0;
    return novo;
}

arvore inserir(arvore raiz, int valor, int *cresceu) {
    if(raiz == NULL) {
        *cresceu = 1;
        return novo_no(valor);
    }
    if(valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor, cresceu);

        if(*cresceu) {
            switch(raiz->fb) {
                case -1:
                    raiz->fb = 0;
                    *cresceu = 0;
                    break;
                case 0:
                    raiz->fb = 1;
                    *cresceu = 1;
                    break;
                case 1:
                    *cresceu = 0;
                    return rotacao(raiz);
                    break;
            }
        }
    }
    else {
        raiz->esq = inserir(raiz->esq, valor, cresceu);

        if(*cresceu) {
            switch(raiz->fb) {
                case -1:
                    *cresceu = 0;
                    return rotacao(raiz);
                    break;
                case 0:
                    raiz->fb = -1;
                    *cresceu = 1;
                    break;
                case 1:
                    raiz->fb = 0;
                    *cresceu = 0;
                    break;
            }
        }
    }
    return raiz;
}

arvore remover(arvore raiz, int valor, int *diminuiu) {
    if(raiz == NULL) {
        *diminuiu = 0;
        return NULL;
    }
    if(valor == raiz->valor) {
        if(raiz->esq == NULL || raiz->dir == NULL) {
            arvore aux = (raiz->esq != NULL) ? raiz->esq : raiz->dir;
            free(raiz);
            *diminuiu = 1;
            return aux;
        }
        // dois filhos
        else {
            raiz->valor = maior_elemento(raiz->esq)->valor;
            valor = raiz->valor;
        }
    }
    if(valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor, diminuiu);

        if(*diminuiu) {
            switch(raiz->fb) {
                case -1:
                    *diminuiu = (raiz->esq->fb == 0) ? 0 : 1;
                    return rotacao(raiz);
                    break;
                case 0:
                    raiz->fb = -1;
                    *diminuiu = 0;
                    break;
                case 1:
                    raiz->fb = 0;
                    *diminuiu = 1;
                    break;
            }
        }
    }
    else {
        raiz->esq = remover(raiz->esq, valor, diminuiu);

        if(*diminuiu) {
            switch(raiz->fb) {
                case -1:
                    raiz->fb = 0;
                    *diminuiu = 1;
                    break;
                case 0:
                    raiz->fb = 1;
                    *diminuiu = 0;
                    break;
                case 1:
                    *diminuiu = (raiz->dir->fb == 0) ? 0 : 1;
                    return rotacao(raiz);
                    break;
            }
        }
    }
    return raiz;
}

arvore maior_elemento(arvore raiz) {
    if (raiz->dir == NULL)
        return raiz;
    else
        return maior_elemento(raiz->dir);
}

arvore rotacao(arvore pivo) {
    // rotacao direita
    if(pivo->fb < 0) {
        if(pivo->esq->fb <= 0) {
            balanceamento_rot_direita(pivo);
            return rotacao_simples_direita(pivo);
        }
        else {
            balanceamento_rot_direita(pivo);
            return rotacao_dupla_direita(pivo);
        }
    }
    // rotacao esquerda
    else {
        if(pivo->dir->fb >= 0) {
            balanceamento_rot_esquerda(pivo);
            return rotacao_simples_esquerda(pivo);
        }
        else {
            balanceamento_rot_esquerda(pivo);
            return rotacao_dupla_esquerda(pivo);
        }
    }
}

void balanceamento_rot_direita(arvore pivo) {
    arvore u, v;
    u = pivo->esq;
    v = u->dir;

    switch(u->fb) {
        case -1:
            pivo->fb = 0;
            u->fb = 0;
            break;

        case 0:
            pivo->fb = -1;
            u->fb = 1;
            break;

        case 1:
            if(v->fb == -1)
                pivo->fb = 1;
            else
                pivo->fb = 0;

            if(v->fb == 1)
                u->fb = -1;
            else
                u->fb = 0;

            v->fb = 0;
            break;
    }
}

void balanceamento_rot_esquerda(arvore pivo) {
    arvore u, v;
    u = pivo->dir;
    v = u->esq;

    switch(u->fb) {
        case 1:
            pivo->fb = 0;
            u->fb = 0;
            break;

        case 0:
            pivo->fb = 1;
            u->fb = -1;
            break;

        case -1:
            if(v->fb == -1)
                u->fb = 1;
            else
                u->fb = 0;

            if(v->fb == 1)
                pivo->fb = -1;
            else
                pivo->fb = 0;

            v->fb = 0;
            break;
    }
}

arvore rotacao_simples_direita(arvore pivo) {
    arvore u, t2;
    u = pivo->esq;
    t2 = u->dir;

    u->dir = pivo;
    pivo->esq = t2;

    return u;
}

arvore rotacao_simples_esquerda(arvore pivo) {
    arvore u, t2;
    u = pivo->dir;
    t2 = u->esq;

    u->esq = pivo;
    pivo->dir = t2;

    return u;
}

arvore rotacao_dupla_direita(arvore pivo) {
    pivo->esq = rotacao_simples_esquerda(pivo->esq);
    return rotacao_simples_direita(pivo);
}

arvore rotacao_dupla_esquerda(arvore pivo) {
    pivo->dir = rotacao_simples_direita(pivo->dir);
    return rotacao_simples_esquerda(pivo);
}

void preorder(arvore raiz) {
    if(raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz) {
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}
