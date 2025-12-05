// Arquivo criado para apenas declarações
#ifndef CONTACTS_H
#define CONTACTS_H

#include <stdbool.h>

typedef struct
{
    char name[50];  // Máx 49 caracteres + '\0'
    char phone[15]; // Máx 14 caracteres + '\0'
} Contato;

#define QTY 10 // Quantidade de contatos possíveis

void show_Contacts(Contato *c);
int contact_Exists(char name[], Contato *c);
void add_Contact(char name[], char phone[], Contato *c);
void delete_Contact(char name[], Contato *c);
void procurar_contato(char name[], Contato *c);

#endif