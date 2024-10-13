#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caixa.h"

Caixa inicializarCaixa(int numeroIndentificacaoCaixa) {
    Caixa novoCaixa;
    novoCaixa.numeroIdentificacao = numeroIndentificacaoCaixa;
    novoCaixa.estado = 1;
    novoCaixa.qtdClientes = 0;
    for(int i = 0;i <=2 ;i++){
        Fila* iniciaCaixa = malloc(sizeof(Fila));
        inicializarFila(iniciaCaixa);
        novoCaixa.filasDePrioridade[i] = iniciaCaixa;
    }
    return novoCaixa;
}

void inserirCliente(Caixa *caixa) {
    Cliente novoCliente = inicializarCliente();
    switch (novoCliente.prioridade){
        case 1:
            enfileirar(caixa->filasDePrioridade[0], novoCliente);
            break;
        case 2:
            enfileirar(caixa->filasDePrioridade[1], novoCliente);
            break;
        case 3:
            enfileirar(caixa->filasDePrioridade[2], novoCliente);
            break;
    }
    caixa->qtdClientes++;
}

void trocarCliente(Caixa *caixa, Cliente novoCliente) {
    if(novoCliente.prioridade == -1){
        printf("\nCliente inválido!\n");
    }
    switch (novoCliente.prioridade){
        case 1:
            enfileirar(caixa->filasDePrioridade[0], novoCliente);
            break;
        case 2:
            enfileirar(caixa->filasDePrioridade[1], novoCliente);
            break;
        case 3:
            enfileirar(caixa->filasDePrioridade[2], novoCliente);
            break;
    }
    caixa->qtdClientes++;
}

Cliente removerCliente(Caixa *caixa, int prioridade) {
    if(caixa->qtdClientes == 0){ // não tem cliente nesse caixa
        Cliente cliente_vazio;
        cliente_vazio.prioridade = -1;
        return cliente_vazio;
    }
    if(prioridade > 2){ // já passou em toda a fila
        Cliente cliente_vazio;
        cliente_vazio.prioridade = -1;
        return cliente_vazio;
    }
    if(caixa->filasDePrioridade[prioridade]->tamanho != 0){
        caixa->qtdClientes--;
        return desenfileirar(caixa->filasDePrioridade[prioridade]);
    }
    return removerCliente(caixa, prioridade + 1);
}

void imprimirCaixaComCliente(Caixa caixa, int numeroCaixa) {
    printf("\n------ Clientes em espera do %dº caixa -------\n", numeroCaixa);
    for(int i = 0;i <=2 ;i++){
        switch (i){
            case 0:
                printf("Fila de alta prioridade:");
                break;
            case 1:
                printf("Fila de prioridade média:");
                break;
            case 2:
                printf("Fila de baixa prioridade:");
                break;
        }
        imprimirFila((*caixa.filasDePrioridade[i]));
    }
    printf("-----------------------------------------------\n");
}

void imprimirCaixaSemCliente(Caixa caixa, int numeroCaixa) {
    printf("\n------------- Detalhes do %dº caixa -------------\n", numeroCaixa);
    printf("Número de identificação: %d\n", caixa.numeroIdentificacao);
    if(caixa.estado == 0){
        printf("Estado: FECHADO\n");
    } else {
        printf("Estado: ABERTO\n");
    }
    printf("Qtd. clientes em espera: %d\n", caixa.qtdClientes);
    printf("-----------------------------------------------\n");
}

void alterarEstado(Caixa *caixaAtual, Caixa *proximoCaixa) {
    if(caixaAtual->estado == 0){
        caixaAtual->estado = 1;
        return;
    }
    while (caixaAtual->qtdClientes != 0){
        trocarCliente(proximoCaixa, removerCliente(caixaAtual, 0));
    }
    caixaAtual->estado = 0;
    printf("\nEstado do caixa alterado com sucesso!\n");
}




