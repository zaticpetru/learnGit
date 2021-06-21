#include "menues.h"
#include "../data/Playlist.h"
#include "../data/Song.h"
#include "../fileDb/db.h"

void print_playlist_menu()
{
    for(auto &it : gPlaylists) {
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
        cout << "Alege dupa nume:\n\n";
        string searchString;

        getline(cin, searchString);
        if(searchString.empty()) {
            getline(cin,searchString);
        }

        Playlist result = getPlaylistByName(searchString);
        if(!result.get_name().empty()) {
            cout << "A fost gasit playlist-ul:\n";
            cout << result << "\n";
        } else {
            cout << "NU AU FOST GASITE PLAYLISTURI\n";
        }
        cout << "\n\nContinue ? ...";
        cin >> searchString;

        break;
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