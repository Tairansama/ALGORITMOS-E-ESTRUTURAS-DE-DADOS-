// Atividade semi-presencial 01: Pilhas e Filas
// Ronaldy Tairan Mandebura (ronaldymandebura.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 100

struct pilha {
    int dados[MAX];
    int topo;
};

Pilha* pilha_criar(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = 0;
    }
    return p;
}

int pilha_inserir(Pilha* p, int elem) {
    if (p == NULL) return 0;
    
    if (p->topo >= MAX) {
        printf("\n[ERRO] Pilha cheia! Nao e possivel inserir %d.\n", elem);
        return 0;
    }

    p->dados[p->topo] = elem;
    p->topo++;
    return 1;
}

int pilha_retirar(Pilha* p, int* elem) {
    if (p == NULL) return 0;

    if (p->topo == 0) {
        printf("\n[ERRO] Pilha vazia! Nao ha elementos para remover.\n");
        return 0;
    }

    p->topo--;
    *elem = p->dados[p->topo];
    return 1;
}

void pilha_visualizar(Pilha* p) {
    if (p == NULL || p->topo == 0) {
        printf("\n--- Conteudo da Pilha: [VAZIA] ---\n");
        return;
    }

    printf("\n--- Conteudo da Pilha (Topo para Base) ---\n");
    for (int i = p->topo - 1; i >= 0; i--) {
        printf("[%d] : %d\n", i, p->dados[i]);
    }
}

void pilha_liberar(Pilha* p) {
    if (p != NULL) {
        free(p);
    }
}