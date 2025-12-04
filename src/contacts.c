#include "../include/contacts.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int used = 1;

// Mostrar lista de Contatos
void show_Contacts(Contato *c)
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
void add_Contact(char name[], char phone[], Contato *c)
{

    strcpy(c[used].name, name);
    strcpy(c[used].phone, phone);

    used++;
    printf("Contato '%s' adicionado a lista de contatos!!\n", name);

    sleep(2); // No Linux é segundos, Windows: milisegundos

    show_Contacts(c);
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
            show_Contacts(c);
        }
    }
}