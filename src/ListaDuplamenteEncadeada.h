#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct lista {
    int size;
    No *primeiro;
    No *ultimo;
} Lista;

void inicializarLista(Lista *lista);
void inserirNoInicio(Lista *lista, int novoValor);
void inserirNoMeio(Lista *lista, int posicao, int novoValor);
void inserirNoFinal(Lista *lista, int novoValor);
void imprimir(No *no);

#endif
