#include "./src/data/Song.h"
#include "./src/data/Playlist.h"

#include <iostream>

using namespace std;

int main()
{  
    Song s1;
    Song s2;
    Song s3;

    cin >> s1;
    cin >> s2;
    cin >> s3;

    Playlist playlist;

    cin >> playlist;

    playlist.AddSong(s1);
    playlist.AddSong(s2);
    playlist.AddSong(s3);


    cout << "Playlist creat:\n" << playlist;

    return 0;
}


