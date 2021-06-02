#include "menues.h"

void clear_screen()
{
    system("@cls||clear");
}

char getUserChoice()
{
    char choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void print_default(void (*print_menu)())
{
    cout << "_______________________________\n";
    cout << "Sistem gestionare playlist\n";
    cout << "_______________________________\n\n";
    print_menu();
    cout << "[x] Inchide programul\n\n";
    cout << "Alegere [1,2,3 .. x]: ";
}

void handle_default(void (*handle_menu)(char), char choice){
    handle_menu(choice);
}
