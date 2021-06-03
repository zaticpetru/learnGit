#include "menues.h"
#include "../data/Playlist.h"
#include "../data/Song.h"
#include "../fileDb/db.h"

void print_playlist_menu()
{
    list<Playlist> playlists = readPlaylists();

    for(auto &it : playlists) {
        cout << it << "\n";
    }

    cout << "[1] Alege playlist:\n";
    cout << "[2] Mergi la meniu principal\n";
}

void handle_playlist_menu(char choice)
{
    switch (choice)
    {
    case '1': {
        cout << "Alege playlist:\n\n";

        int id;
        cin >> id;
    } 

    case '2': {
        cout << "Mergi la meniu principal\n\n";
        current_menu = print_main_menu;
        current_handler = handle_main_menu;
        break;
    }

    default:
        printf("caracter gresit, mai incearca\n\n");
        break;
    }
}