// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
} Contato;

// FUNÇÃO PRINCIPAL
int main(void)
{
    Contato array[3];

    printf("--------MENU-------");


    strcpy(array[0].nome, "Henrique");
    array[0].idade = 18;
    printf("Hellor World!");
    return 0;
}