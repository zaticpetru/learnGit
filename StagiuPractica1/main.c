#include "./src/menues/menues.h"
#include "./src/data/db_raport.h"
#include "./src/util/util.h"

int main()
{
    current_menu = print_main_menu;
    current_handler = handle_main_menu;

    clear_screen();
    char choice;

    ReadRaports();

    do
    {
        print_default(current_menu);
        choice = getUserChoice();
        clear_screen();

        if (choice != 'x')
        {
            handle_default(current_handler, choice);
        }

    } while (choice != 'x');

    return 0;
}