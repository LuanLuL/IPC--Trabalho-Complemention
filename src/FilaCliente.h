#include "Cliente.h"

#ifndef FILACLIENTE_H
#define FILACLIENTE_H

typedef struct no {
    Cliente valor;
    struct no *proximo;
} No;

typedef struct fila {
    No *primeiro;
    No *ultimo;
    int tamanho;
} Fila;

void inicializarFila(Fila *fila);
void enfileirar(Fila *fila, Cliente valor);
Cliente desenfileirar(Fila *fila);
void imprimirFila(Fila fila);
int filaVazia(Fila fila);

#endif