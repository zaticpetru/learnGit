#include "db.h"

string playlistsFileName = "playlist.txt";
int N = 0;


list<Playlist> readPlaylists() {
    list<Playlist> playlists;
    string fileName = "db/" + playlistsFileName;

    ifstream playlist(fileName);
    string input;
    string buffer[256];
    int count = 0;
    while(getline(playlist, input)){
        // cout << input << "\n";
        buffer[count] = input;
        count++;
    }

    if(count <= 1) {
        cout << "nu sunt date in fisier: " << fileName;
    } else {
        N = atoi(buffer[0].c_str());
        for(int i = 1; i < count; i += 2) {
            Playlist *playlist = new Playlist();
            playlist->set_name(buffer[i]);
            playlist->set_rating(atof(buffer[i + 1].c_str()));
            playlists.push_front(*playlist);
        }

        for(auto &it : playlists) {
            string filename = it.get_name();
            auto songs = readPlaylistSongs(filename);
            it.set_songs(songs);
        }
    }

    
    return playlists;
}

list<Song> readPlaylistSongs(string playlistName) {
    list<Song> songs;
    string fileName = "db/" + playlistName + ".txt";

    ifstream songInput(fileName);
    string input;
    string buffer[256];
    int count = 0;
    while(getline(songInput, input)){
        buffer[count] = input;
        count++;
    }
    if(count <= 1) {
        cout << "nu sunt date in fisier: " << fileName;
    } else {
        int n = atoi(buffer[0].c_str());
        for(int i = 1; i < count; i += 3) {
            Song *song = new Song();
            song->set_name(buffer[i]);
            song->set_genre(buffer[i + 1]);
            song->set_secDuration(atoi(buffer[i + 2].c_str()));

            songs.push_front(*song);
        }
    }

    return songs;
}


void savePlaylists(list<Playlist> playlists) {
    if(playlists.size() > 0) {
        string fileName = "db/" + playlistsFileName;
        ofstream playlistOut(fileName);

        playlistOut << playlists.size() << "\n";

        for(auto &it : playlists) {
            string filename = it.get_name();
            list<Song> songs = it.get_songs();

            for(auto &it : songs) {
                cout << it.get_name() << "\n"
                << it.get_genre() << "\n"
                << it.get_secDuration() << "\n";
            }

            savePlaylistSongs(filename, songs);

            playlistOut << it.get_name() << "\n" << it.get_rating() << "\n";
        }

        playlistOut.close();
    }  
}

void savePlaylistSongs(string playlistName, const list<Song> songs){
    cout << "\nENTERED SAVING SONGS\n";
    cout << "\n SONGS SIZE" << songs.size() << "\n";
    cout << "\n PlaylistName" << playlistName << "\n";
    
    if(songs.size() > 0) {
        string fileName = "db/" + playlistName + ".txt";
        ofstream songOut;
        songOut.open(fileName, ios::out);

        songOut << songs.size() << "\n";
        for(auto &it : songs) {
            songOut << it.get_name() << "\n"
                << it.get_genre() << "\n"
                << it.get_secDuration() << "\n";
        }

        songOut.close();
    }

}