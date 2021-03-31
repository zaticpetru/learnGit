#include "menues.h"

void print_incidente_menu(){
    printf("Afisare incidente:\n\n");
    printf("Aici vor fi afisate incidentele\n\n");
    printf("[1] Mergi la meniu principal\n");
}

void handle_incidente_menu(char choice) {
    switch (choice)
    {
        case '1':
            printf("Mergi la meniu principal\n\n");
            current_menu = print_main_menu;
            current_handler = handle_main_menu;
            break;

        default:
            printf("caracter gresit, mai incearca\n\n");
            break;
    }
}
