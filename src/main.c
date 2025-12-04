// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// CABEÇALHOS
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/contacts.h"
#include "../include/validators.h"
#include "../include/add_Contact_Logic.h"
#include "../include/delete_Contact_Logic.h"

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Biblioteca de string
#include <stdbool.h> //Permite tipos booleano
#include <unistd.h>  // #include <windows.h> //No windows

void runApp()
{
    Contato contatos[QTY] = {
        {"Ana Clara", "47996235"},
        {"Carlos Eduardo", "47996235"},
        {"Alexandre", "47996235"},
        {"Ana Clara", "47996235"},
        {"Ana Clara", "47996235"},
        {"Ana Clara", "47996235"},
        {"Ana Clara", "47996235"},
        {"Ana Clara", "47996235"},
        {"Ana Clara", "47996235"},
        {"Clara Ana", "47996235"},

    };
    char name[50], phone[15];
    int opc;
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
            // Adicionar Lógica de pesquisar
            break;
        case 3:
            system("clear");
            add_Contact_Logic(contatos);
            break;
        case 4:
            system("clear");
            delete_Contact_Logic(contatos);
            break;

        case 5:
            system("clear");
            printf("|===================|\n");
            printf("|ATÉ LOGO!!         |\n");
            printf("|===================|\n");
            return;

        default:
            system("clear");

            printf("|=============================================|\n");
            printf("|               OPÇÃO INVÁLIDA!!              |\n");
            printf("|=============================================|\n\n");
        }
    }
}

int main()
{
    runApp();
    return 0;
}
