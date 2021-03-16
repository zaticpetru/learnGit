#include "menues.h"

void clear_screen()
{
    system("@cls||clear");
}

char getUserChoice()
{
    char choice = getc(stdin);
    getc(stdin);
    return choice;
}

void print_default(void (*print_menu)())
{
    printf("_______________________________\n");
    printf("Sistem raportare incidente\n");
    printf("_______________________________\n\n");
    print_menu();
    printf("[x] Inchide programul\n\n");
    printf("Alegere [1,2,3 .. x]: ");
}

void handle_default(void (*handle_menu)(char), char choice){
    handle_menu(choice);
}
