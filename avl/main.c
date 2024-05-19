#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

int ler_valor() {
    int x;
    printf("Insira o valor: ");
    scanf("%d", &x);
    return x;
}

int main(int argc, char * argv[]) {
    arvore a = NULL;
    int opcao, cresceu, diminuiu, valor, temp;

    while(1) {
        printf("\n1 - inserir\n2 - preorder\n3 - inorder\n4 - posorder \n5 - remover\n99 - sair\n");
        printf("\nInsira a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                valor = ler_valor();
                a = inserir(a, valor, &cresceu);
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
                valor = ler_valor();
                a = remover(a, valor, &diminuiu);
                break;
            case 99:
                exit(0);
        }
    }
}
