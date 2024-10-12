#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

Cliente inicializarCliente() {
    Cliente novoCliente;
    size_t lengthString;
    printf("\n--- Digite o nome do cliente (até 100 caracteres) ---\n\n");
    scanf("%101[^\n]", novoCliente.nome);
    limparBuffer();
    lengthString = strlen(novoCliente.nome);
    if (lengthString > 0 && novoCliente.nome[lengthString - 1] == '\n') {
        novoCliente.nome[lengthString - 1] = '\0';
    }
    printf("\n--- Digite o CPF do cliente (11 dígitos) ---\n\n");
    while (1) {
        scanf("%12[^\n]", novoCliente.cpf);
        limparBuffer();
        lengthString = strlen(novoCliente.cpf);
        if (lengthString > 0 && novoCliente.cpf[lengthString - 1] == '\n') {
            novoCliente.cpf[lengthString - 1] = '\0';
        }
        if (!(strlen(novoCliente.cpf) == 11)) {
            printf("\nCliente() => CPF inválido, tente novamente:\n\n");
        } else {
            break; 
        }
    }
    printf("\n--- Digite a prioridade do cliente [1, alta], [2, média], [3, baixa] ---\n\n");
    while (1) {
        scanf("%d", &novoCliente.prioridade);
        limparBuffer();
        if (novoCliente.prioridade != 1 && novoCliente.prioridade != 2 && novoCliente.prioridade != 3) {
            printf("\nCliente() => Prioridade inválida, tente novamente:\n\n");
        } else {
            break; 
        }
    }
    printf("\n--- Digite o número de itens no carrinho do cliente (mínimo de 1) ---\n\n");
    while (1) {
        scanf("%d", &novoCliente.numeroDeItensCarrinho);
        limparBuffer();
        if (novoCliente.numeroDeItensCarrinho < 1) {
            printf("\nCliente() => Número de itens no carrinho inválido, tente novamente:\n\n");
        } else {
            break; 
        }
    }
    printf("\n---------------------------\n");
    return novoCliente;
}

void imprimirCliente(Cliente cliente, int posicao) {
    printf("\n\t--- Detalhes do %dº Cliente ---\n", posicao + 1);
    printf("\tNome: %s\n", cliente.nome);
    printf("\tCPF: %s\n", cliente.cpf);
    printf("\tPrioridade: %d\n", cliente.prioridade);
    printf("\tNúmero de Itens no Carrinho: %d\n", cliente.numeroDeItensCarrinho);
    printf("\t---------------------------");
}
