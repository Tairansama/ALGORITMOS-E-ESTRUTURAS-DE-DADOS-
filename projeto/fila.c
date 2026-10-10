// Atividade semi-presencial 01: Pilhas e Filas
// Ronaldy Tairan Mandebura (ronaldymandebura.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 100

struct fila {
    float dados[MAX];
    int inicio;
    int fim;
    int qtd;
};

Fila* fila_criar(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
    }
    return f;
}

int fila_inserir(Fila* f, float elem) {
    if (f == NULL) return 0;

    if (f->qtd >= MAX) {
        printf("\n[ERRO] Fila cheia! Nao e possivel inserir %.2f.\n", elem);
        return 0;
    }

    f->dados[f->fim] = elem;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
    return 1;
}

int fila_retirar(Fila* f, float* elem) {
    if (f == NULL) return 0;

    if (f->qtd == 0) {
        printf("\n[ERRO] Fila vazia! Nao ha elementos para remover.\n");
        return 0;
    }

    *elem = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return 1;
}

void fila_visualizar(Fila* f) {
    if (f == NULL || f->qtd == 0) {
        printf("\n Conteudo da Fila: [VAZIA] \n");
        return;
    }

    printf("\n Conteudo da Fila (Inicio para Fim) \n");
    for (int i = 0; i < f->qtd; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("Posicao %d : %.2f\n", i + 1, f->dados[idx]);
    }
}

void fila_liberar(Fila* f) {
    if (f != NULL) {
        free(f);
    }
}