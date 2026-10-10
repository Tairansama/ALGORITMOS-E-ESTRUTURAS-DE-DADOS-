// Atividade semi presencial 02 - Listas Encadeadas
// Ronaldy Tairan Mandebura (ronaldymandebura@aluno.unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* criar_lista() {
    return NULL;
}

Aluno* inserir_aluno(Aluno *lista, int matricula, char nome[], float nota) {
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return lista;
    }

    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->prox = NULL;

    if (lista == NULL || strcmp(nome, lista->nome) < 0) {
        novo->prox = lista;
        return novo;
    }

    Aluno *atual = lista;
    Aluno *ant = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) < 0) {
        ant = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    ant->prox = novo;

    return lista;
}

Aluno* remover_aluno(Aluno *lista, char nome[]) {
    if (lista == NULL) {
        printf("aluno inexistente\n");
        return lista;
    }

    Aluno *atual = lista;
    Aluno *ant = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("aluno inexistente\n");
        return lista;
    }

    if (ant == NULL) {
        lista = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    printf("Aluno removido com sucesso!\n");
    return lista;
}

void imprimir_lista(Aluno *lista) {
    if (lista == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    Aluno *aux = lista;
    printf("\nLISTA DE ALUNOS\n");
    while (aux != NULL) {
        printf("Matricula: %d | Nome: %s | Nota: %.2f\n", aux->matricula, aux->nome, aux->nota);
        aux = aux->prox;
    }
}

void liberar_lista(Aluno *lista) {
    Aluno *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}