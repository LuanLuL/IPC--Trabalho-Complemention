#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"

void inicializarLista(Lista *lista) {
    lista->size = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

void inserirNoInicio(Lista *lista, int novoValor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = novoValor;
        novo->proximo = lista->primeiro;
        novo->anterior = NULL;
        if (lista->primeiro) {
            lista->primeiro->anterior = novo;
        }
        lista->primeiro = novo;
        if (lista->ultimo == NULL) {
            lista->ultimo = novo;
        }
        lista->size++;
    } else {
        printf("\n\nERRO... Não foi possível alocar memória...\n\n");
    }
}

void inserirNoMeio(Lista *lista, int posicao, int novoValor) {
    if (posicao == 0) {
        inserirNoInicio(lista, novoValor);
        return;
    }
    if (posicao > lista->size) {
        printf("Posição inválida\n");
        return;
    }
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = novoValor;
        No *atual = lista->primeiro;
        for (int i = 0; i < posicao - 1 && atual; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        novo->anterior = atual;
        if (atual->proximo) {
            atual->proximo->anterior = novo;
        }
        atual->proximo = novo;
        if (novo->proximo == NULL) {
            lista->ultimo = novo;
        }
        lista->size++;
    } else {
        printf("\n\nERRO... Não foi possível alocar memória...\n\n");
    }
}

void inserirNoFinal(Lista *lista, int novoValor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = novoValor;
        novo->proximo = NULL;
        novo->anterior = lista->ultimo;
        if (lista->ultimo) {
            lista->ultimo->proximo = novo;
        }
        lista->ultimo = novo;
        if (lista->primeiro == NULL) {
            lista->primeiro = novo;
        }
        lista->size++;
    } else {
        printf("\n\nERRO... Não foi possível alocar memória...\n\n");
    }
}

void imprimir(No *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}
