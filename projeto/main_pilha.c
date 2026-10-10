// Atividade semi-presencial 01: Pilhas e Filas
// Ronaldy Tairan Mandebura (ronaldymandebura.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
    Pilha* p = pilha_criar();
    if (p == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int opcao, valor;

    do {
        printf("\n MENU \n");
        printf("1) Inserir elemento\n");
        printf("2) Retirar elemento\n");
        printf("3) Imprimir conteudo\n");
        printf("4) Liberar memoria e encerrar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor inteiro a ser inserido: ");
                scanf("%d", &valor);
                if (pilha_inserir(p, valor)) {
                    printf("Sucesso: Valor %d inserido na pilha.\n", valor);
                }
                break;

            case 2:
                if (pilha_retirar(p, &valor)) {
                    printf("Elemento retornado da pilha: %d\n", valor);
                }
                break;

            case 3:
                pilha_visualizar(p);
                break;

            case 4:
                pilha_liberar(p);
                printf("Memoria liberada com sucesso. Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}