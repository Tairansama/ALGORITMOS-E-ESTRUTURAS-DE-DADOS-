#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* pilha_criar(void);
int pilha_inserir(Pilha* p, int elem);
int pilha_retirar(Pilha* p, int* elem);
void pilha_visualizar(Pilha* p);
void pilha_liberar(Pilha* p);

#endif