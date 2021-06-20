#include "menues.h"

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
        printf("Creaza playlist\n\n");
        printf("_______________________________\n");

        Playlist* newPlaylist = new Playlist();

        string name;
        float rating;
        int songNumber;

        cout << "Playlist name: ";
        getline(cin, name);
        newPlaylist->set_name(name);

        cout << "Playlist rating (0-5): ";
        cin >> rating;
        newPlaylist->set_rating(rating);

        cout << "Number of songs in playlist: ";
        cin >> songNumber;

        for(int i = 0; i < songNumber; i++){
            cout << "Introduce [" << i << "] song\n";
            string name;
            string genre;
            int secDuration;
            Song* newSong = new Song();

            cout << "\t[" << i << "] name: ";
            cin.ignore();
            getline(cin, name);
            newSong->set_name(name);

            cout << "\t[" << i << "] genre: ";
            // cin.ignore(); was erasing first letter of genre
            getline(cin, genre);
            newSong->set_genre(genre);

            cout << "\t[" << i << "] seconds duration: ";
            cin >> secDuration;
            newSong->set_secDuration(secDuration);

            newPlaylist->AddSong(*newSong);
        }
        

        gPlaylists.push_front(*newPlaylist);

        savePlaylists(gPlaylists);
        savePlaylistSongs(newPlaylist->get_name(), newPlaylist->get_songs());
        gPlaylists = readPlaylists();

        break;
    }

    case '2': {
        cout << "Afiseaza playlist-uri\n\n";
        current_menu = print_playlist_menu;
        current_handler = handle_playlist_menu;
        break;

    }

    default:
        printf("caracter gresit, mai incearca\n\n");
        break;
    }
}