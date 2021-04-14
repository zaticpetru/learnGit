#include "menues.h"
#include "../data/db_raport.h"

void print_incidente_menu(){
    printf("Afisare incidente:\n\n");

    ReadRaports();
    PrintRaports();

    printf("\n\n[1] Mergi la meniu principal\n");
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
