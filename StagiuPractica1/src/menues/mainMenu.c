#include <stdio.h>
#include "menues.h"

void print_main_menu()
{
    printf("[1] Raporteaza/sterge incident\n");
    printf("[2] Incidente raportate\n");
    printf("[3] Informatie despre sistem\n");
}

void handle_main_menu(char choice)
{
    switch (choice)
    {
    case '1':
        printf("Raporteaza/sterge incident\n\n");
        current_menu = print_raport_menu;
        current_handler = handle_raport_menu;
        break;

    case '2':
        printf("Incidente raportate\n\n");
        current_menu = print_incidente_menu;
        current_handler = handle_incidente_menu;
        break;

    case '3':
        printf("Informatie despre sistem\n\n");
        current_menu = print_info_menu;
        current_handler = handle_info_menu;
        break;

    default:
        printf("caracter gresit, mai incearca\n\n");
        break;
    }
}