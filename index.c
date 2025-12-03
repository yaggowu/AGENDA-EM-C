// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include "contato.h" //Incluo o struct Contato que criei em outro arquivo
#include <string.h>  //Biblioteca de string

#define QTD 3

// Função que mostra o menu e retorna a opção escolhida pelo usuário
int show_Menu()
{
    char temp[10]; // Buffer de texto
    int opc;

    printf(" ____________________MENU___________________ \n");
    printf("|                                           |\n");
    printf("|1 - CONSULTAR CONTATO");
    printf("\t|3 - EXCLUIR CONTATO|\n");
    printf("|2 - INCLUIR CONTATO");
    printf("\t|4 - SAIR\t    |\n");

    printf("Opcao: ");
    fgets(temp, 10, stdin);
    opc = atoi(temp);

    return opc;
}

// Mostrar lista de Contatos
void show_Contats(Contato *c)
{
    system("clear"); // Clear para Linux

    printf("---Dados---\n");
    for (int i = 0; i < QTD; i++)
    {
        printf("---CONTATO %i---\n", i + 1);
        printf("Nome: %s\n", c[i].nome);
        printf("Idade: %i\n", c[i].idade);
    }
}

// FUNCÃO ADICIONAR CONTATO
// Critérios
// Checar duplicados
// Verificar se há espaço
void add_contato(char nome[], int idade, Contato *c)
{
    show_Contats(c);
    printf("Nome: '%s'\nIdade: '%i'\n", nome, idade);
};

// FUNÇÃO PRINCIPAL
int main(void)
{
    int opc = 0, idade = 0;
    char temp[10], nome[50];
    Contato c[QTD] = {
        {"Ana", 19},
        {"Bruno", 23},
        {"Clara", 25},
    };

    while (opc != 4)
    {
        do
        {
            opc = show_Menu();

            if (opc != 1 && opc != 2 && opc != 3 && opc != 4)
            {
                system("clear");
                printf("Opcao invalida!!\n");
            }

        } while (opc != 1 && opc != 2 && opc != 3 && opc != 4);

        // Case para opções
        switch (opc)
        {
        case 1:
            // Printa os contatos
            show_Contats(c);
            break;
        case 2:
            system("clear"); // cls para windows
            printf("----Inclusão de contatos-----\n");
            printf("Nome do novo contato: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // remove o \n

            printf("Digite a idade: ");
            fgets(temp, 10, stdin);
            idade = atoi(temp);

            add_contato(nome, idade, c);
        default:
            break;
        }

        if (opc == 4)
        {
            system("clear");
            return printf("Até mais!\n");
        }
    }

    return 0;
}
