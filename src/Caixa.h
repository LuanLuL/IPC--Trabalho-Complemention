#include "FilaCliente.h"
#include "Cliente.h"

#ifndef CAIXA_H
#define CAIXA_H

typedef struct caixa {
    int numeroIdentificacao, estado, qtdClientes;
    Fila *filasDePrioridade[3];
} Caixa;

Caixa inicializarCaixa(int numeroIndentificacaoCaixa);
void inserirCliente(Caixa *caixa);
void trocarCliente(Caixa *caixa, Cliente novoCliente);
Cliente removerCliente(Caixa *caixa, int prioridade);
void imprimirCaixaComCliente(Caixa caixa, int numeroCaixa);
void imprimirCaixaSemCliente(Caixa caixa, int numeroCaixa);
void alterarEstado(Caixa *caixaAtual, Caixa *proximoCaixa);

#endif
