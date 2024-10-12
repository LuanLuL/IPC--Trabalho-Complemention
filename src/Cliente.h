#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    char nome[101], cpf[12];
    int prioridade, numeroDeItensCarrinho;
} Cliente;

Cliente inicializarCliente();
void imprimirCliente(Cliente cliente, int posicao);
void limparBuffer();

#endif
