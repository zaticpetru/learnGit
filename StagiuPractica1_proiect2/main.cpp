#include "./src/data/Song.h"
#include "./src/data/Playlist.h"
#include "./src/menues/menues.h"
#include "./src/fileDb/db.h"

#include <iostream>

using namespace std;

/**
 *? Global variables current_menu and current handler
 ** current_menu
 *  -- for displaying menu items
 ** current_handler 
 *  -- for handling user commands in a menu
 */
void (*current_menu)();
void (*current_handler)(char);

/**
 *? Global variables for storage
 ** gPlaylists
 *  -- contains a copy of data stored in fileDB
 ** gN
 *  -- current number of playlists
 */
list<Playlist> gPlaylists;
int gN;

int main()
{  
    // set to main_menu on program start-up
    // -> mainMenu.cpp
    current_menu = print_main_menu;
    current_handler = handle_main_menu;

    clear_screen();
    char choice;

    // initialising storage variables
    gPlaylists = readPlaylists();
    gN = gPlaylists.size();

    do
    {
        print_default(current_menu);
        cin >> choice;
        clear_screen();


        // checking for "close" command
        if (choice != 'x')
        {
            handle_default(current_handler, choice);
        }

    } while (choice != 'x');
    // program will run until "close" command was chosen

    return 0;
}


