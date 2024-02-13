#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_ordenacao.h"

void verifica_erro(int x, char* c) {
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
    int op, valor, pos, ref, a, b;
    struct lista *l1;

    l1 = (struct lista *) malloc(sizeof(struct lista));
    inicializar(l1);

    while(1){
        printf("1 - inserir no inicio\n2 - inserir no fim\n3 - inserir na posicao\n4 - inserir em ordem\n5 - exibir\n6 - exibir invertido\n7 - remover no inicio\n");
        printf("8 - remover no fim\n9 - remover na posicao\n10 - remover valor\n11 - procurar valor\n12 - somatorio\n13 - tamanho da lista\n14 - elementos ao quadrado\n");
        printf("15 - quant. de primos\n16 - trocar\n17 - bubble sort\n18 - insertion sort\n19 - selection sort\n20 - merge sort\n21 - quick sort\n22 - heap sort\n99 - sair\n");
        printf("Insira a opcao:\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                valor = leitura("valor");
                ref = inserir_inicio(l1, valor);
                verifica_erro(ref, "inserir");
                break;

            case 2:
                valor = leitura("valor");
                ref = inserir_fim(l1, valor);
                verifica_erro(ref, "inserir");
                break;

            case 3:
                valor = leitura("valor");
                pos = leitura("posicao");
                ref = inserir_posicao(l1, valor, pos);
                verifica_erro(ref, "inserir");
                break;

            case 4:
                valor = leitura("valor");
                ref = inserir_ordem(l1, valor);
                verifica_erro(ref, "inserir");
                break;

            case 5:
                exibir(l1);
                break;

            case 6:
                reverso(l1);
                break;

            case 7:
                ref = remover_inicio(l1);
                verifica_erro(ref, "remover");
                break;

            case 8:
                ref = remover_fim(l1);
                verifica_erro(ref, "remover");
                break;

            case 9:
                pos = leitura("posicao");
                ref = remover_posicao(l1, pos);
                verifica_erro(ref, "remover");
                break;

            case 10:
                valor = leitura("valor");
                ref = remover_valor(l1, valor);
                verifica_erro(ref, "remover");
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
                a = leitura("posicao a");
                b = leitura("posicao b");
                troca(l1, a, b);
                break;

            case 17:
                bubble_sort(l1);
                break;

            case 18:
                insertion_sort(l1);
                break;

            case 19:
                selection_sort(l1);
                break;

            case 20:
                merge_sort(l1, 0, l1->particao);
                break;

            case 21:
                quick_sort(l1, 0, l1->particao-1);
                break;

            case 22:
                heap_sort(l1);
                break;

            case 99:
                exit(0);

            default:
                printf("Funcao nao encontrada.\n");
        }
    }
}
