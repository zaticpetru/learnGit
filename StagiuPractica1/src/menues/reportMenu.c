#include "menues.h"
#include "../data/db_raport.h"
#include "../util/util.h"

void print_raport_menu()
{
    printf("Meniu de raportare\n");
    printf("[1] Introdu datele pentru un nou caz\n");
    printf("[2] Sterge caz raportat (id) \n");
    printf("[3] Mergi la meniu principal\n");
}

void handle_raport_menu(char choice)
{
    switch (choice)
    {
    case '1':
        printf("Introdu datele pentru un nou caz:\n\n");
        printf("_______________________________\n");

        char title[80];
        char location[80];
        char description[150];

        getLine("Title: ", title, 80);
        getLine("Location: ", location, 80);
        getLine("Description: ", description, 150);


        raport newRaport = CrateRaport(title, location, description);
        if(AddRaport(newRaport) == -1){
            printf("Error in saving raport");
        } else {
            printf("\nRaport adaugat cu succes\n");
        }

        break;

    case '2':

        printf("Sterge caz raportat (id)\n\n");
        char id[10];
        getLine("ID TO DELETE: ", id, sizeof(id));

        if(DeleteRaport(atoi(id)) == -1) {
            printf("Error in deleting raport");
        } else {
            printf("\nRaport sters cu succes id = %s\n", id);
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