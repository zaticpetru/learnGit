#include "./src/data/Song.h"
#include "./src/data/Playlist.h"
#include "./src/menues/menues.h"
#include "./src/fileDb/db.h"

#include <iostream>

using namespace std;

void (*current_menu)();
void (*current_handler)(char);

list<Playlist> gPlaylists;
int gN;

int main()
{  
    current_menu = print_main_menu;
    current_handler = handle_main_menu;

    clear_screen();
    char choice;

    gPlaylists = readPlaylists();
    gN = gPlaylists.size();

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


