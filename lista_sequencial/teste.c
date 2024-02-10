#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void notifica_falha(int x, char* c) {
    if(x == 0)
        printf("Nao foi possivel %s.\n", c);
}

int leitura(char* c) {
    int x;
    printf("Insira o %s:\n", c);
    scanf("%d", &x);
    return x;
}

int main(int argc, char *argv) {
    int op, valor, pos, ref;
    lista *l1;

    l1 = (lista *) malloc(sizeof(lista));
    inicializar(l1);

    while(1) {
        printf("1 - inserir no inicio\n2 - inserir no fim\n3 - inserir na posicao\n4 - inserir em ordem\n5 - exibir\n6 - exibir invertido\n");
        printf("7 - remover no inicio\n8 - remover no fim\n9 - remover na posicao\n10 - remover valor\n11 - procurar valor\n 12 - somatorio\n");
        printf("13 - tamanho da lista\n14 - elementos ao quadrado\n15 - quant. de primos\n16 - inverter lista\n99 - sair\n");
        printf("Insira a opcao:\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                valor = leitura("valor");
                ref = inserir_inicio(l1, valor);
                notifica_falha(ref, "inserir");
                break;

            case 2:
                valor = leitura("valor");
                ref = inserir_fim(l1, valor);
                notifica_falha(ref, "inserir");
                break;

            case 3:
                valor = leitura("valor");
                pos = leitura("posicao");
                ref = inserir_posicao(l1, valor, pos);
                notifica_falha(ref, "inserir");
                break;

            case 4:
                valor = leitura("valor");
                ref = inserir_ordem(l1, valor);
                notifica_falha(ref, "inserir");
                break;

            case 5:
                exibir(l1);
                break;

            case 6:
                reverso(l1);
                break;

            case 7:
                ref = remover_inicio(l1);
                notifica_falha(ref, "remover");
                break;

            case 8:
                ref = remover_fim(l1);
                notifica_falha(ref, "remover");
                break;

            case 9:
                pos = leitura("posicao");
                ref = remover_posicao(l1, pos);
                notifica_falha(ref, "remover");
                break;

            case 10:
                valor = leitura("valor");
                ref = remover_valor(l1, valor);
                notifica_falha(ref, "remover");
                break;

            case 11:
                valor = leitura("valor");
                printf("posicao: %d\n", procurar(l1, valor));
                break;

            case 12:
                printf("somatorio: %d\n", somatorio(l1));
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
                inverte_lista(l1);
                exibir(l1);
                break;

            case 99:
                exit(0);

            default:
                printf("Funcao nao encontrada.\n");
        }
    }
}
