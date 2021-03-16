#include "menues.h"

void print_raport_menu()
{
    printf("Meniu de raportare\n");
    printf("[1] Introdu datele pentru un nou caz\n");
    printf("[2] Transmite caz\n");
    printf("[3] Mergi la meniu principal\n");
}

void handle_raport_menu(char choice)
{
    switch (choice)
    {
    case '1':
        printf("Introdu datele pentru un nou caz\n\n");
        break;

    case '2':
        printf("Transmite caz\n\n");
        break;

    case '3':
        printf("Mergi la meniu principal\n\n");
        current_menu = print_main_menu;
        current_handler = handle_main_menu;
        break;

    default:
        printf("caracter gresit, mai incearca\n\n");
        break;
    }
}
