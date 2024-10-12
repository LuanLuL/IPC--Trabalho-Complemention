#include "FilaCliente.h"

#ifndef CAIXA_H
#define CAIXA_H

typedef struct caixa {
    int numeroIdentificacao, estado, qtdClientes;
    Fila *filasDePrioridade[3];
} Caixa;

Caixa inicializarCaixa(int numeroIndentificacaoCaixa);
void inserirCliente(Caixa *caixa);
void removerCliente(Caixa *caixa, int prioridade);
void imprimirCaixaComCliente(Caixa caixa, int numeroCaixa);
void imprimirCaixaSemCliente(Caixa caixa, int numeroCaixa);

#endif
