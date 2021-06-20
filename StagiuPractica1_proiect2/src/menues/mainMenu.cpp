#include "menues.h"
#include "../utils/input.h"

void create_playlist();

void print_main_menu()
{
    cout << "[1] Creaza playlist\n";
    cout << "[2] Afiseaza playlist-uri\n";
    cout << "[3] Informatie despre program\n";
}

void handle_main_menu(char choice)
{
    switch (choice)
    {
        case '1': {
            cout << "Creaza playlist\n\n";
            cout << "_______________________________\n";
            create_playlist();
            break;
        }

        /**
         *? Example of navigation
        *  -- Here we can see that for navigating to
        *  playlist menu, we just need to change
        *  current_menu & current_handler to desired one
        */
        case '2': {
            cout << "Afiseaza playlist-uri\n\n";
            current_menu = print_playlist_menu;
            current_handler = handle_playlist_menu;
            break;
        }

        default: {
            printf("caracter gresit, mai incearca\n\n");
            break;
        }
    }
}

void create_playlist() {
        Playlist* newPlaylist = new Playlist();

        string name;
        float rating;
        int songNumber;

        cout << "Playlist name: ";
        name = getUserInput();
        newPlaylist->set_name(name);

        cout << "Playlist rating (0-5): ";
        rating = getUserInput<float>();
        newPlaylist->set_rating(rating);

        cout << "Number of songs in playlist: ";
        songNumber = getUserInput<int>();
        
        for(int i = 0; i < songNumber; i++){
            cout << "Introduce [" << i << "] song\n";
            string name;
            string genre;
            int secDuration;
            Song* newSong = new Song();

            cout << "\t[" << i << "] name: ";
            name = getUserInput();
            newSong->set_name(name);

            cout << "\t[" << i << "] genre: ";
            genre = getUserInput();
            newSong->set_genre(genre);

            cout << "\t[" << i << "] seconds duration: ";
            secDuration = getUserInput<int>();
            newSong->set_secDuration(secDuration);

            newPlaylist->AddSong(*newSong);
        }
        
        gPlaylists.push_front(*newPlaylist);

        savePlaylists(gPlaylists);
        savePlaylistSongs(newPlaylist->get_name(), newPlaylist->get_songs());
        gPlaylists = readPlaylists();
}