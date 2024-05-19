#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int ler_valor() {
    int x;
    printf("Insira o valor: ");
    scanf("%d", &x);
    return x;
}

void exibir_menu() {
    printf("\n1 - inserir valor\n2 - preorder\n3 - inorder\n4 - posorder \n5 - reverso\n");
    printf("6 - remover valor\n7 - buscar valor\n8 - buscar antecessor\n9 - buscar pai\n");
    printf("10 - quantidade de pares\n11 - somatorio de pares\n12 - podar arvore\n");
    printf("13 - dobrar valores\n14 - descendentes\n15 - altura da arvore\n99 - sair\n");
}

int main(int argc, char * argv[]) {
    arvore a = NULL;
    int opcao, valor;
    a = inserir(a, 8);
    a = inserir(a, 20);
    a = inserir(a, 15);
    a = inserir(a, 30);
    a = inserir(a, 9);
    a = inserir(a, 25);
    a = inserir(a, 4);
    a = inserir(a, 3);
    a = inserir(a, 7);
    a = inserir(a, 37);
    a = inserir(a, 32);
    a = inserir(a, 35);

    while(1) {
        exibir_menu();
        printf("\nInsira a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                valor = ler_valor();
                a = inserir(a, valor);
                break;

            case 2:
                preorder(a);
                printf("\n");
                break;

            case 3:
                inorder(a);
                printf("\n");
                break;

            case 4:
                posorder(a);
                printf("\n");
                break;

            case 5:
                reverso(a);
                printf("\n");
                break;

            case 6:
                valor = ler_valor();
                a = remover(a, valor);
                break;

            case 7:
                valor = ler_valor();
                printf("%d\n", busca(a, valor));
                break;

            case 8:
                valor = ler_valor();
                printf("%d\n", antecessor(a, valor));
                break;

            case 9:
                valor = ler_valor();
                printf("%d\n", pai(a, valor));
                break;

            case 10:
                printf("%d\n", quantidade_par(a));
                break;

            case 11:
                printf("%d\n", somatorio_par(a));
                break;

            case 12:
                valor = ler_valor();
                a = podar(a, valor);
                break;

            case 13:
                dobro(a);
                break;

            case 14:
                valor = ler_valor();
                descendentes(a, valor);
                printf("\n");
                break;

            case 15:
                printf("%d\n", altura(a));
                break;

            case 99:
                exit(0);

            default:
                printf("Funcao invalida.\n");
        }
    }

    return 0;

}