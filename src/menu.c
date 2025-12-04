#include "../include/menu.h"
#include <stdio.h>
#include <stdlib.h>

// Função que mostra o menu e retorna a opção escolhida pelo usuário
int show_Menu()
{
    char temp[10]; // Buffer de texto
    int opc;

    printf("=========================================\n");
    printf("         AGENDA  DE  CONTATO             \n");
    printf("=========================================\n");
    printf("   [1]  Listar contatos\n");
    printf("   [2]  Pesquisar contato\n");
    printf("   [3]  Adicionar contato\n");
    printf("   [4]  Excluir contato\n");
    printf("   [5]  Sair\n");
    printf("-----------------------------------------\n");
    printf("   Escolha uma opção: ");

    fgets(temp, 10, stdin);
    opc = atoi(temp);

    return opc;
}