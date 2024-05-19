#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

int ler_valor() {
    int x;
    printf("Insira o valor: ");
    scanf("%d", &x);
    return x;
}

int main(int argc, char * argv[]) {
    arvore a;
    int opcao;
    inicializar(&a);
    
    while(1) {
        printf("\n1 - inserir\n2 - preorder\n3 - inorder\n4 - posorder \n5 - remover\n99 - sair\n");
        printf("\nInsira a opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            int valor;
        case 1:
            valor = ler_valor();
            adicionar(valor, &a);
            break;
        case 2:
            pre_order(a);
            printf("\n");
            break;
        case 3:
            in_order(a);
            printf("\n");
            break;
        case 4:
            pos_order(a);
            printf("\n");
            break;
        case 5:
            valor = ler_valor();
            remover(valor, &a);
            break;
        case 99:
            exit(0);
        }
    }
}
