// // PROJETO AGENDA EM C
// // ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// // BIBLIOTECAS UTILIZADAS
// #include <stdio.h>  //Lib Padrão
// #include <stdlib.h> //Lib Padrão
// #include <unistd.h> // #include <windows.h> //No windows
// #include <string.h> //Biblioteca de string
// #include "main.h"   //Incluo o struct Contato que criei em outro arquivo

// #include <ctype.h>   // Necessário para isalpha() e isdigit()
// #include <stdbool.h> //Permite tipos booleano

// // FUNÇÃO PRINCIPAL
// int main(void)
// {
//     Contato c[QTY] = {{"Ana Clara", "47996235"}};
//     char name[50];
//     char phone[15];
//     int opc = 0, exist;
//     bool ok = false;

//     // Looping principal
//     while (opc != 5)
//     {
//         do
//         {
//             opc = show_Menu();

//             if (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5)
//             {
//                 system("clear");
//                 printf("Opcao invalida!!\n");
//             }

//         } while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5);

//         // Case para opções
//         switch (opc)
//         {
//         case 1:
//             // Printa os contatos
//             show_Contacts(c);
//             break;
//         case 2:
//             break; // Adicionar funcionalidade de busca
//         case 3:

//         case 4:

//         default:
//             break;
//         }

//         if (opc == 5)
//         {
//             system("clear");
//             return printf("Até logo!\n");
//         }
//     }

//     return 0;
// }

// int main()
// {
//     runApp(); // Função principal
//     return 0;
// }