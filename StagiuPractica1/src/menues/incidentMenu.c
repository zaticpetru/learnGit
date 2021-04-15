#include "menues.h"
#include "../data/db_raport.h"
#include "../util/util.h"

int INCIDENT_FORMAT = 1;

void print_incidente_menu(){
    printf("Afisare incidente:\n\n");

    ReadRaports();
    PrintRaports(INCIDENT_FORMAT);

    printf("\n\n[1] Filtreaza dupa titlu/locatie\n");
    printf("[2] Schimba afisarea (lung / scurt)\n");
    printf("[3] Mergi la meniu principal\n");
    
}

void handle_incidente_menu(char choice) {
    switch (choice)
    {
        case '1':
            handle_filter();
            break;

        case '2':
            printf("Schimba afisarea (lung / scurt)\n");
            if(INCIDENT_FORMAT == 1) {
                printf("lung -> scurt\n\n");
                INCIDENT_FORMAT = 2;
            } else {
                printf("scurt -> lung\n\n");
                INCIDENT_FORMAT = 1;
            }
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

void handle_filter(){

    printf("Filtreaza dupa titlu/locatie\n");
    printf("Alege-> (L)Locatie , (T)Titlu: ");

    char choice = getUserChoice();

    char filter[80];


    switch(choice) {
        case 'l':
        case 'L':
            getLine("Location: ", filter, 80);
            printf("\n");
            FilterProductsByLocation(filter, INCIDENT_FORMAT);
            break;

        case 't':
        case 'T':
            getLine("Title: ", filter, 80);
            printf("\n");
            FilterProductsByTitle(filter, INCIDENT_FORMAT);
            break;
        
        default:
            printf("Input gresit");
    }
}
