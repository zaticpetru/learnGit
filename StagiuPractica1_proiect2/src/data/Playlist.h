#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include "Song.h"

using namespace std;

    class Playlist{
            string name;
            float rating;

            list<Song> songs;
        public:
            void set_name(string name);
            string get_name() const;

            void set_rating(float rating);
            float get_rating() const;

            void set_songs(list<Song> songs);
            list<Song> get_songs() const;

            bool AddSong(Song &);

            Playlist(string = "", float = 0);

            Playlist(const Playlist &);

            ~Playlist();

            Playlist &operator=(const Playlist &);

            friend istream &operator>>(istream &, Playlist &);

            friend ostream &operator<<(ostream &, const Playlist &);
    };
#endif  