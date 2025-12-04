#include "../include/validators.h"
#include <string.h>
#include <ctype.h> // Necessário para isalpha() e isdigit()

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