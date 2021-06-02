#include "db.h"

string playlistsFileName = "playlist.csv";

list<Playlist> readPlaylists() {
    list<Playlist> playlists;

    ifstream playlist("db/" + playlistsFileName);
    string input;
    while(getline(playlist, input)){
        cout << input << "\n";
    }
    return playlists;
}
