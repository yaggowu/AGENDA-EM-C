// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>  //Lib Padrão
#include <stdlib.h> //Lib Padrão
#include <unistd.h> // #include <windows.h> //No windows
#include <string.h> //Biblioteca de string
#include "main.h"   //Incluo o struct Contato que criei em outro arquivo

#include <ctype.h> // Necessário para isalpha() e isdigit()

#define QTY 10 // Quantidade de contatos possíveis
int used = 1;  // Defino uma variavél global para saber a quantidade de posicoes do meu array Contatos

// Função que mostra o menu e retorna a opção escolhida pelo usuário
int show_Menu()
{
    char temp[10]; // Buffer de texto
    int opc;

    // printf(" ____________________MENU___________________ \n");
    // printf("|                                             |\n");
    // printf("|1 - CONSULTAR CONTATOS");
    // printf(" |3 - EXCLUIR CONTATOS |\n");
    // printf("|2 - INCLUIR CONTATOS");
    // printf("\t|4 - SAIR\t      |\n");

    printf("|-----------------------------------------------------|\n");
    printf("|                  AGENDA DE CONTATO                  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 1 |                   LISTAR                        |\n");
    printf("| 2 |                  PESQUISAR                      |\n");
    printf("| 3 |                  ADICIONAR                      |\n");
    printf("| 4 |                   EXCLUIR                       |\n");
    printf("| 5 |                    SAIR                         |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|              DIGITE O NUMERO DESEJADO               |\n");
    printf("|-----------------------------------------------------|\n");

    printf("\nOpcao: ");
    fgets(temp, 10, stdin);
    opc = atoi(temp);

    return opc;
}
// Mostrar lista de Contatos
void show_Contats(Contato *c)
{
    system("clear"); // cls para windows

    printf("----Lista de Contatos----\n\n");
    for (int i = 0; i < used; i++)
    {
        printf("---CONTATO %i---\n", i + 1);
        printf("Nome: %s\n", c[i].name);
        printf("Telefone: %s\n", c[i].phone);
    }
}
// Função que verifica se contato ja existe no array
int contact_Exists(char name[], Contato *c)
{
    // Verifica se já existe no array
    for (int i = 0; i < used; i++)
    {
        if (strcmp(c[i].name, name) == 0)

            return 1; // True
    }
    return 0; // False
}
// Adiciona no array
void add_Contacts(char name[], char phone[], Contato *c)
{

    strcpy(c[used].name, name);
    strcpy(c[used].phone, phone);

    used++;
    printf("Contato '%s' adicionado a lista de contatos!!\n", name);

    sleep(2); // No Linux é segundos, Windows: milisegundos

    show_Contats(c);
};
// Deleta no array e organiza
void delete_Contact(char name[], Contato *c)
{
    // Procura no array
    for (int i = 0; i < used; i++)
    {
        if (strcmp(c[i].name, name) == 0)
        {

            // Reorganizar array
            for (int j = i + 1; j < used; j++)
            {
                c[j - 1] = c[j];
            }

            used--;
            system("clear"); // cls para windows
            printf("'%s' foi excluido(a) da sua lista de contatos!!\n", name);
            sleep(2); // No Linux é segundos, Windows: milisegundos
            show_Contats(c);
        }
    }
}
// Valida digitos do nome
int validate_Name(char *name)
{
    if (strlen(name) == 0 || strlen(name) >= 50)
        return 0;

    size_t len = strlen(name);

    for (size_t i = 0; i < len; i++)
    {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}
// Valida digitos do telefone
int validate_Phone(char *phone)
{
    if (strlen(phone) < 8 || strlen(phone) >= 15)
        return 0;

    size_t len = strlen(phone);

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit((unsigned char)phone[i]))
            return 0;
    }
    return 1;
}

// FUNÇÃO PRINCIPAL
int main(void)
{
    int opc = 0, exist;
    int ok = 0;
    char name[50];
    char phone[15];
    Contato c[QTY] = {{"Ana Clara", "19"}};

    while (opc != 5)
    {
        do
        {
            opc = show_Menu();

            if (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5)
            {
                system("clear");
                printf("Opcao invalida!!\n");
            }

        } while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5);

        // Case para opções
        switch (opc)
        {
        case 1:
            // Printa os contatos
            show_Contats(c);
            break;
        case 2:
            break;
        case 3:
            // Repete até o usuário digitar um contato que não existe
            do
            {
                printf("----Inclusão de contatos-----\n");
                printf("Nome do novo contato: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(name, c);
                if (exist)
                {
                    printf("Erro: Contato ja existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist == 1);

            while (ok != 1)
            {

                printf("Digite o Telefone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0'; // remove o \n

                if (validate_Phone(phone))
                {
                    ok = 1;
                }
                printf("Número de telefone inválido!!\n");
            }

            // Adiciona no array
            add_Contacts(name, phone, c);
            break;
        case 4:
            // Deletar
            do
            {
                printf("----Exclusão de contatos-----\n");
                printf("Nome do contato: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(name, c);

                if (!exist)
                {
                    printf("Erro: Contato não existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist == 0);

            // Deleta no array
            delete_Contact(name, c);
            break;
        default:
            break;
        }

        if (opc == 5)
        {
            system("clear");
            return printf("Até mais!\n");
        }
    }

    return 0;
}
