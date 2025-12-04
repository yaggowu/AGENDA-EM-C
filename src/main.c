#include "../include/main.h"
#include "../include/menu.h"
#include "../include/contacts.h"
#include "../include/validators.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> // #include <windows.h> //No windows

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
            show_Contacts(contatos);
            break;

        case 3:
            // Repete até o usuário digitar um contato que não existe
            do
            {
                do // Repete até ele digitar um nome válido
                {
                    printf("----Inclusão de contatos-----\n");
                    printf("Nome do novo contato: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // remove o \n

                    if (validate_Name(name))

                        ok = true;
                    else if (!validate_Name(name))
                    {
                        printf("Nome inválido!\n");
                        ok = false;
                    }

                } while (ok != true);

                // Quando valida nome reseta a varivel ok
                if (ok)
                    ok = false;

                exist = contact_Exists(name, contatos);
                if (exist)
                {
                    printf("Erro: Contato ja existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist != 0); // Enquanto oque ele digitar ja estiver no array

            while (ok != true) // Repete até ele digitar um numero válido
            {
                printf("Digite o Telefone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0'; // remove o \n

                if (validate_Phone(phone))
                    ok = true;
                else if (!validate_Phone(phone))
                {
                    system("clear"); // cls no windows
                    printf("Número de telefone inválido!!\n");
                    printf("Número tem que ter mais de 8 digitos!!\n");
                    ok = false;
                }
            }

            // Adiciona no array
            add_Contact(name, phone, contatos);
            break;

        case 4:
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
                    // system("clear"); // cls para windows
                }

            } while (exist == 0);

            // Deleta no array
            delete_Contact(name, contatos);
            break;

        case 5:
            printf("Até logo!\n");
            return;

        default:
            printf("Opção inválida!\n");
        }
    }
}

int main()
{
    runApp();
    return 0;
}
