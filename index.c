// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// BIBLIOTECAS UTILIZADAS
#include <unistd.h>
// #include <windows.h> //No windows

#include <stdio.h>
#include <stdlib.h>
#include "contato.h" //Incluo o struct Contato que criei em outro arquivo
#include <string.h>  //Biblioteca de string

#define QTD 10  // Quantidade de contatos possíveis
int usados = 1; // Defino uma variavél global para saber a quantidade de posicoes do meu array Contatos

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
    for (int i = 0; i < usados; i++)
    {
        printf("---CONTATO %i---\n", i + 1);
        printf("Nome: %s\n", c[i].nome);
        printf("Idade: %i\n", c[i].idade);
    }
}

// FUNCÃO ADICIONAR CONTATO

int contact_Exists(char nome[], Contato *c)
{
    // Verifica se já existe no array
    for (int i = 0; i < usados; i++)
    {
        if (strcmp(c[i].nome, nome) == 0)

            return 1; // True
    }
    return 0; // False
}

void add_contato(char nome[], int idade, Contato *c)
{

    strcpy(c[usados].nome, nome);
    c[usados].idade = idade;

    usados++;
    printf("Contato '%s' adicionado a lista de contatos!!\n", nome);

    sleep(2); // No Linux é segundos, Windows: milisegundos

    show_Contats(c);
};

void delete_Contact(char nome[], Contato *c)
{
    // Procura no array
    for (int i = 0; i < usados; i++)
    {
        if (strcmp(c[i].nome, nome) == 0)
        {

            // Reorganizar array
            for (int j = i + 1; j < usados; j++)
            {
                c[j - 1] = c[j];
            }

            usados--;
            printf("'%s' foi excluido(a) da sua lista de contatos!!\n", nome);
            sleep(2); // No Linux é segundos, Windows: milisegundos
            show_Contats(c);
        }
    }
}

// FUNÇÃO PRINCIPAL
int main(void)
{
    int opc = 0, idade = 0, exist;
    char temp[10], nome[50];
    Contato c[QTD] = {{"Ana Clara", 19}};

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
            // Repete até o usuário digitar um contato que não existe
            do
            {
                printf("----Inclusão de contatos-----\n");
                printf("Nome do novo contato: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(nome, c);

                if (exist)
                {
                    printf("Erro: Contato ja existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist == 1);

            printf("Digite a idade: ");
            fgets(temp, 10, stdin);
            idade = atoi(temp);

            // Adiciona no array
            add_contato(nome, idade, c);
            break;
        case 3:
            // Deletar
            do
            {
                printf("----Exclusão de contatos-----\n");
                printf("Nome do contato: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(nome, c);

                if (!exist)
                {
                    printf("Erro: Contato não existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist == 0);

            // Adiciona no array
            delete_Contact(nome, c);
            break;
            break;
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
