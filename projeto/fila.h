#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* fila_criar(void);
int fila_inserir(Fila* f, float elem);
int fila_retirar(Fila* f, float* elem);
void fila_visualizar(Fila* f);
void fila_liberar(Fila* f);

#endif