// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// CABEÇALHOS
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/contacts.h"
#include "../include/validators.h"
#include "../include/add_Contact_Logic.h"

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Biblioteca de string
#include <stdbool.h> //Permite tipos booleano
#include <unistd.h>  // #include <windows.h> //No windows

void runApp()
{
    Contato contatos[QTY] = {{"Ana Clara", "47996235"}};
    char name[50], phone[15];
    int opc, exist;
    bool ok;

    while (1)
    {
        opc = show_Menu();

        switch (opc)
        {
        case 1:
            system("clear"); // cls para windows
            show_Contacts(contatos);
            break;
        case 2:
            system("clear");
            // Lógica de pesquisar
            break;
        case 3:
            system("clear");
            add_Contact_Logic(contatos);
            break;
        case 4:
            system("clear");
            // Deletar
            do
            {
                printf("----Exclusão de contatos-----\n");
                printf("Nome do contato: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(name, contatos);

                if (!exist)
                {
                    printf("Erro: Contato não existe!!\n");
                    // system("clear");
                }

            } while (exist == 0);

            // Deleta no array
            delete_Contact(name, contatos);
            break;

        case 5:
            system("clear");
            printf("Até logo!\n");
            return;

        default:
            system("clear");
            printf("Opção inválida!\n");
        }
    }
}

int main()
{
    runApp();
    return 0;
}
