#include <stdio.h>
#include <windows.h> // Linux. No Windows usar Sleep()

void blink_loading()
{
    for (int i = 0; i < 6; i++)
    {
        printf("...\r");
        fflush(stdout);
        Sleep(3);

        printf("             \r"); // limpa a linha
        fflush(stdout);
        Sleep(3);
    }
}
