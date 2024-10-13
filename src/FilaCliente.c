#include <stdio.h>
#include <stdlib.h>
#include "FilaCliente.h"
#include "Cliente.h"

void inicializarFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

void enfileirar(Fila *fila, Cliente valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->proximo = NULL;
        if (fila->ultimo == NULL) {
            fila->primeiro = novo;
        } else {
            fila->ultimo->proximo = novo;
        }
        fila->ultimo = novo;
        fila->tamanho++;
    } else {
        printf("\nERRO...ERRO...Não foi possível alocar memória...ERRO...ERRO\n");
    }
}


Cliente desenfileirar(Fila *fila) {
    if (fila->primeiro == NULL) {
        printf("\nFila de cientes já está vazia\n");
        Cliente cliente_vazio;
        cliente_vazio.prioridade = -1;
        return cliente_vazio;
    }
    No *remover = fila->primeiro;
    fila->primeiro = remover->proximo;
    if (fila->primeiro == NULL) {
        fila->ultimo = NULL;
    }
    Cliente returnCliente = remover->valor;
    free(remover);
    fila->tamanho--;
    return returnCliente;
}


int filaVazia(Fila fila) {
    return fila.tamanho == 0;
}

void imprimirFila(Fila fila) {
    if(fila.tamanho == 0){
        printf("\n\t--- Não há clientes ---");
        printf("\n\tA fila está vazia\n");
        printf("\t---------------------------\n");
        return;
    }
    No *atual = fila.primeiro;
    for(int i = 0; atual; i++) {
        imprimirCliente(atual->valor, i);
        atual = atual->proximo;
    }
    printf("\n");
}
