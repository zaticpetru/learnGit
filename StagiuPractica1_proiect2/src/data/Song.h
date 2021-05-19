#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

    class Song{
        public:
            string name;
            string genre;
            int secDuration;
            Song(string = "", string = "", int = 0);

            Song(const Song &);

            ~Song();

            Song &operator=(const Song &);

            friend istream &operator>>(istream &, Song &);

            friend ostream &operator<<(ostream &, Song &);
    };
#endif  