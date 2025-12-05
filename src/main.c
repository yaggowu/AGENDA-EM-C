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
    Contato contatos[QTY];
    char name[50], phone[15];
    int opc;
    bool ok;

    while (1)
    {
        opc = show_Menu();

        switch (opc)
        {
        case 1:
            system("cls"); // cls para windows
            show_Contacts(contatos);
            break;
        case 2:
            system("cls");
            printf("|=============================================|\n");
            printf("|               DIGITE O CONTATO              |\n");
            printf("|=============================================|\n\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // remove o \n

            procurar_contato(name, contatos);

            break;
        case 3:
            system("cls");
            add_Contact_Logic(contatos);
            break;
        case 4:
            system("cls");
            delete_Contact_Logic(contatos);
            break;

        case 5:
            system("cls");
            printf("|==========================|\n");
            printf("|         ATE LOGO!!       |\n");
            printf("|==========================|\n");
            return;

        default:
            system("cls");

            printf("|=============================================|\n");
            printf("|               OPCAO INVALIDA!!              |\n");
            printf("|=============================================|\n\n");
        }
    }
}

int main()
{
    runApp();
    return 0;
}
