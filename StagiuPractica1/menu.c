#include <stdio.h>
#include <stdlib.h>

void print_main_menu();
void handle_main_menu(char choice);

void print_raport_menu();
void handle_raport_menu(char choice);

void print_incidente_menu();
void handle_incidente_menu(char choice);

void print_info_menu();
void handle_info_menu(char choice);

void (*current_menu)();
void (*current_handler)(char choice);

typedef struct MenuItem
{
    char code;
    char *title;
} MenuItem;

void clrscr()
{
    system("@cls||clear");
}

char getUserChoice()
{
    char choice = getc(stdin);
    getc(stdin);
    return choice;
}

void print_main_menu()
{
    printf("[1] Raporta incident\n");
    printf("[2] Incidente raportate\n");
    printf("[3] Informatie despre sistem\n");
}

void handle_main_menu(char choice)
{
    switch (choice)
    {
    case '1':
        printf("Raporta incident\n\n");
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

int main()
{
    current_menu = print_main_menu;
    current_handler = handle_main_menu;
    clrscr();
    char choice;

    do
    {
        print_default(current_menu);
        choice = getUserChoice();
        clrscr();

        if (choice != 'x')
        {
            handle_default(current_handler, choice);
        }

    } while (choice != 'x');

    return 0;
}