// Atividade semi presencial 02 - Listas Encadeadas
// Ronaldy Tairan Mandebura (ronaldymandebura@aluno.unipampa.edu.br)

#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno {
    int matricula;      
    char nome[40];      
    float nota;         
    struct Aluno *prox;
} Aluno;

Aluno* criar_lista();
Aluno* inserir_aluno(Aluno *lista, int matricula, char nome[], float nota);
Aluno* remover_aluno(Aluno *lista, char nome[]);
void imprimir_lista(Aluno *lista);
void liberar_lista(Aluno *lista);

#endif