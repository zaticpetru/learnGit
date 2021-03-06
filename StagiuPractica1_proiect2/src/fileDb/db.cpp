#include "db.h"

string playlistsFileName = "playlist.txt";
int N = 0;

bool sortPlaylistsByRating(Playlist first, Playlist second) {
    return first.get_rating() > second.get_rating();
}

list<Playlist> readPlaylists() {
    list<Playlist> playlists;
    string path = "db/" + playlistsFileName;

    ifstream playlist(path);
    string input;
    string buffer[256];
    int count = 0;
    while(getline(playlist, input)){
        // cout << input << "\n";
        buffer[count] = input;
        count++;
    }
    playlist.close();

    if(count <= 1) {
        cout << "nu sunt date in fisier: " << path;
    } else {
        N = atoi(buffer[0].c_str());
        for(int i = 1; i < count; i += 2) {
            Playlist *playlist = new Playlist();
            playlist->set_name(buffer[i]);
            playlist->set_rating(atof(buffer[i + 1].c_str()));
            playlists.push_back(*playlist);
        }

        for(auto &it : playlists) {
            string filename = it.get_name();
            auto songs = readPlaylistSongs(filename);
            it.set_songs(songs);
        }
    }

    playlists.sort(sortPlaylistsByRating);
    return playlists;
}

list<Song> readPlaylistSongs(string playlistName) {
    list<Song> songs;
    string path = "db/" + playlistName + ".txt";

    ifstream songInput(path);
    string input;
    string buffer[256];
    int count = 0;
    while(getline(songInput, input)){
        buffer[count] = input;
        count++;
    }
    if(count <= 1) {
        cout << "nu sunt date in fisier: " << path;
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
        string path = "db/" + playlistsFileName;
        ofstream playlistOut(path);

        playlistOut << playlists.size() << "\n";

        for(auto &it : playlists) {
            // string filename = it.get_name();
            // list<Song> songs = it.get_songs();

            // for(auto &it : songs) {
            //     cout << it.get_name() << "\n"
            //     << it.get_genre() << "\n"
            //     << it.get_secDuration() << "\n";
            // }

            // savePlaylistSongs(filename, songs);

            playlistOut << it.get_name() << "\n"
                << it.get_rating() << "\n";
        }

        playlistOut.close();
    }  
}

void savePlaylistSongs(string playlistName, const list<Song> songs){
    // cout << "\nENTERED SAVING SONGS\n";
    // cout << "\n SONGS SIZE" << songs.size() << "\n";
    // cout << "\n PlaylistName" << playlistName << "\n";
    
    if(songs.size() > 0) {
        string path = "db/" + playlistName + ".txt";
        ofstream songOut;
        songOut.open(path, ios::out);

        songOut << songs.size() << "\n";
        for(auto &it : songs) {
            songOut << it.get_name() << "\n"
                << it.get_genre() << "\n"
                << it.get_secDuration() << "\n";
        }

        songOut.close();
    }

}

Playlist getPlaylistByName(string searchString) {
    Playlist result;
    list<Playlist>::iterator it;

    for(it = gPlaylists.begin(); it != gPlaylists.end(); it++) {
        size_t found = it->get_name().find(searchString);
        if(found != string::npos) {
            break;
        }
    }

    if(it != gPlaylists.end()){
        result =  *it;
        result.set_songs(it->get_songs());
    }
    return result;
}