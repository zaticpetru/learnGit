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


/**
 *? function for displaying a menu with default header & footer 
 *  @param print_menu - function that will display menu items
 */
void print_default(void (*print_menu)())
{
    cout << "_______________________________\n";
    cout << "Sistem gestionare playlist\n";
    cout << "_______________________________\n\n";
    print_menu();
    cout << "[x] Inchide programul\n\n";
    cout << "Alegere [1,2,3 .. x]: ";
}


/**
 *? function for handling user input for current displayed menu 
 *  @param handle_menu - function that accepts a char as input
 *  and executes selected command from menu 
 */
void handle_default(void (*handle_menu)(char), char choice){
    handle_menu(choice);
}
