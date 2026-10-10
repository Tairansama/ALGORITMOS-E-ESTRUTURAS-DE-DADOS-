// Atividade semi presencial 02 - Listas Encadeadas
// Ronaldy Tairan Mandebura (ronaldymandebura@aluno.unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main() {
    Aluno *lista = criar_lista();
    int opcao, mat;
    char nome[40];
    float nota;

    do {
        printf("\nMENU\n");
        printf("1. Inserir aluno\n");
        printf("2. Remover aluno\n");
        printf("3. Imprimir lista\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                getchar();

                printf("Digite o nome: ");
                fgets(nome, 40, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite a nota: ");
                scanf("%f", &nota);

                lista = inserir_aluno(lista, mat, nome, nota);
                break;

            case 2:
                printf("Digite o nome do aluno a ser removido: ");
                fgets(nome, 40, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                lista = remover_aluno(lista, nome);
                break;

            case 3:
                imprimir_lista(lista);
                break;

            case 0:
                printf("Encerrando o programa\n");
                break;

            default:
                printf("ERRO!\n");
        }
    } while (opcao != 0);

    liberar_lista(lista);
    return 0;
}