#include "menues.h"

void print_info_menu(){
    printf("Despre aplicatie:\n\n");
    printf("Aplicatia permite raportarea incidentelor dintr-o localitate.\n");
    printf("Utilizatorul poate construi o noua raportare.\n");
    printf("Acesta introduce zona in care incidentul are loc si tipul incidentului\n");
    printf("Utilizatorul poate vizualiza o lista cu toate incidentele raportate.\n");
    printf("De asemenea, aplicația oferă posibilitatea filtrarii raportarilor in funcție de zona\n");
    printf("sau in functie de tipul incidentului.");
    printf("Un exemplu de element: Strada Vasile Alecsandri - Lampa stradala nefunctionala.\n");

    printf("\n[1] Mergi la meniu principal\n");
}

void handle_info_menu(char choice){
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