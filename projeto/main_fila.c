// Atividade semi-presencial 01: Pilhas e Filas
// Ronaldy Tairan Mandebura (ronaldymandebura.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void) {
    Fila* f = fila_criar();
    if (f == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int opcao;
    float valor;

    do {
        printf("\n MENU \n");
        printf("1) Inserir elemento\n");
        printf("2) Retirar elemento\n");
        printf("3) Imprimir conteudo\n");
        printf("4) Liberar memoria e encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor float a ser inserido: ");
                scanf("%f", &valor);
                if (fila_inserir(f, valor)) {
                    printf("Sucesso: Valor %.2f inserido na fila.\n", valor);
                }
                break;

            case 2:
                if (fila_retirar(f, &valor)) {
                    printf("Elemento retornado da fila: %.2f\n", valor);
                }
                break;

            case 3:
                fila_visualizar(f);
                break;

            case 4:
                fila_liberar(f);
                printf("Memoria liberada com sucesso. Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}