#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include "Song.h"

using namespace std;

    class Playlist{
        public:
            string name;
            float rating;

            list<Song> songs;

            bool AddSong(Song &);

            Playlist(string = "", float = 0);

            Playlist(const Playlist &);

            ~Playlist();

            Playlist &operator=(const Playlist &);

            friend istream &operator>>(istream &, Playlist &);

            friend ostream &operator<<(ostream &, Playlist &);
    };
#endif  