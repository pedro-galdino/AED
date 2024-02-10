#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int leitura(char* c) {
    int x;
    printf("Insira %s:\n", c);
    scanf("%d", &x);
    return x;
}

int main(int argc, char *argv) {
    int op, valor, pos;
    lista l1 = NULL;

    while(1) {
        printf("1 - inserir no inicio\n2 - inserir no fim\n3 - inserir na posicao\n4 - inserir em ordem\n5 - exibir\n6 - exibir invertido\n");
        printf("7 - remover do inicio\n8 - remover do fim\n9 - remover na posicao\n10 - remover valor\n11 - procurar valor\n12 - somatorio\n");
        printf("13 - tamanho da lista\n14 - elementos ao quadrado\n15 - quant. de primos\n16 - lista somada\n99 - sair\n");
        printf("\nInsira a opcao:\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                valor = leitura("o valor");
                l1 = inserir_inicio(l1, valor);
                break;

            case 2:
                valor = leitura("o valor");
                l1 = inserir_fim(l1, valor);
                break;

            case 3:
                pos = leitura("a posicao");
                valor = leitura("o valor");
                l1 = inserir_posicao(l1, pos, valor);
                break;

            case 4:
                valor = leitura("o valor");
                l1 = inserir_ordem(l1, valor);
                break;

            case 5:
                exibir_lista(l1);
                break;

            case 6:
                exibir_reverso(l1);
                printf("\n");
                break;

            case 7:
                l1 = remover_inicio(l1);
                break;

            case 8:
                l1 = remover_fim(l1);
                break;

            case 9:
                pos = leitura("a posicao");
                l1 = remover_posicao(l1, pos);
                break;

            case 10:
                valor = leitura("o valor");
                l1 = remover_valor(l1, valor);
                break;

            case 11:
                valor = leitura("o valor");
                lista ref = procurar(l1, valor);
                if(ref == NULL)
                    printf("O valor nao foi encontrado.\n");
                else
                    printf("resultado da procura: %p\n", ref);
                break;

            case 12:
                valor = leitura("o valor");
                printf("somatorio: %d\n", somatorio(l1, valor));
                break;

            case 13:
                printf("tamanho: %d\n", tamanho(l1));
                break;

            case 14:
                quadrado(l1);
                break;

            case 15:
                printf("quantidade de primos: %d\n", qtd_primo(l1));
                break;

            case 16:
                l1 = lista_soma(l1);
                break;

            case 99:
                exit(0);

            default:
                printf("Funcao nao encontrada.\n");
        }

    }
}
