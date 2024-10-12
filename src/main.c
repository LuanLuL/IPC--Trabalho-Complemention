#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaCliente.h"
#include "Cliente.h"
#include "Caixa.h"
#define NUMCAIXAS 5




// ********************** TESTES PARA VERIFICAR FUNCIONAMENTO DO CLIENTE **********************

// int main() {
//     setlocale(LC_ALL, "Portuguese");
//     Cliente cliente;
//     int opcao, inicializou = 0;
//     printf("\n********** Sistema de Gestão do Cliente **********\n");
//     do {
//         printf("\n\t1 - Criar cliente\n\t2 - Imprimir cliente\n\t0 - Sair\n\n");
//         printf("Escolha uma opção: ");
//         scanf("%d", &opcao);
//         limparBuffer();
//         switch (opcao) {
//             case 1:
//                 cliente = inicializarCliente();
//                 printf("\nCliente %s criado com sucesso!\n", cliente.nome);
//                 inicializou = 1;
//                 break;
//             case 2:
//                 if (inicializou != 0) {
//                     imprimirCliente(cliente, 0);
//                 } else {
//                     printf("\nNenhum cliente foi criado ainda.\n");
//                 }
//                 break;
//             case 0:
//                 printf("\nSaindo...\n");
//                 break;
//             default:
//                 printf("\nERRO...ERRO...Opção inválida...ERRO...ERRO\n");
//                 break;
//         }
//         printf("\n****************************************************************\n");
//     } while (opcao != 0);
//     return 0;
// }




// ********************** TESTES PARA VERIFICAR FUNCIONAMENTO DA FILA DE CLIENTES **********************

// int main() {
//     setlocale(LC_ALL, "Portuguese");
//     Fila fila;
//     inicializarFila(&fila);
//     int opcao, temCliente = 0;
//     printf("\n********** Sistema de Gestão da Fila de Clientea **********\n");
//     do {
//         printf("\n\t1 - Enfileirar\n\t2 - Desenfileirar\n\t3 - Imprimir fila\n\t4 - Tamanho da fila\n\t0 - Sair\n\n");
//         printf("Escolha uma opção: ");
//         scanf("%d", &opcao);
//         limparBuffer();
//         switch (opcao) {
//             case 1:
//                 enfileirar(&fila, inicializarCliente());
//                 temCliente = 1;
//                 printf("\nCliente adcionado na fila com sucesso!\n");
//                 break;
//             case 2:
//                 desenfileirar(&fila);
//                 if(temCliente != 0){
//                     printf("\nCliente removido da fila com sucesso!\n");
//                 }
//                 if(fila.tamanho == 0){
//                     temCliente = 0;
//                 }
//                 break;
//             case 3:
//                 if (filaVazia(fila)) {
//                     printf("\nA fila está vazia\n");
//                 } else {
//                     imprimirFila(fila);
//                 }
//                 break;
//             case 4:
//                 if (filaVazia(fila)) {
//                     printf("\nTamanho da fila: 0 (está vazia)\n");
//                 } else {
//                     printf("\nTamanho da fila: %d\n", fila.tamanho);
//                 }
//                 break;
//             case 0:
//                 printf("\nSaindo...\n");
//                 break;
//             default:
//                 printf("\nERRO...ERRO...Opção inválida...ERRO...ERRO");
//                 break;
//         }
//         printf("\n****************************************************************\n");
//     } while (opcao != 0);

//     return 0;
// }




//********************** TESTES PARA VERIFICAR FUNCIONAMENTO DO PROGRAMA **********************

int main() {
    setlocale(LC_ALL, "Portuguese");
    Caixa supermercado[NUMCAIXAS];
    for(int i = 0; i < NUMCAIXAS; i++){
        supermercado[i] = inicializarCaixa((i+1)*43); // ID do caixa aleatorio
    }
    int opcao, caixaSelecionado = 0;
    printf("\n********** Sistema de Gestão de Filas em Supermercado **********\n");
    do {
        printf("\n\t1 - Cadastrar um Cliente\n\t2 - Atender um Cliente\n\t3 - Abrir ou Fechar um Caixa\n\t4 - Imprimir a Lista de Clientes em Espera\n\t5 - Imprimir o Status dos Caixas\n\t0 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        switch (opcao) {
            case 1:
                printf("\nEscolha um caixa (1 a 5): ");
                scanf("%d", &caixaSelecionado);
                limparBuffer();
                if(caixaSelecionado < 1 || caixaSelecionado > 5){
                    printf("\nERRO...ERRO...Opção inválida...ERRO...ERRO\n");
                    break;
                }
                inserirCliente(&supermercado[--caixaSelecionado]);
                printf("\nCliente adicionado com sucesso!\n");
                break;
            case 2:
                printf("\nEscolha um caixa (1 a 5): ");
                scanf("%d", &caixaSelecionado);
                limparBuffer();
                if(caixaSelecionado < 1 || caixaSelecionado > 5){
                    printf("\nERRO...ERRO...Opção inválida...ERRO...ERRO\n");
                    break;
                }
                if(supermercado[--caixaSelecionado].qtdClientes == 0){
                    printf("\nCaixa está vazio\n");
                    break;
                }
                removerCliente(&supermercado[--caixaSelecionado], 0);
                printf("\nCliente atendido com sucesso!\n");
                break;
            case 3:
                break;
            case 4:
                for(int i = 0; i < NUMCAIXAS; i++){
                   imprimirCaixaComCliente(supermercado[i], i+1);
                }
                break;
            case 5:
                for(int i = 0; i < NUMCAIXAS; i++){
                   imprimirCaixaSemCliente(supermercado[i], i+1);
                }
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nERRO...ERRO...Opção inválida...ERRO...ERRO\n");
                break;
        }
        printf("\n****************************************************************\n");
    } while (opcao != 0);

    return 0;
}