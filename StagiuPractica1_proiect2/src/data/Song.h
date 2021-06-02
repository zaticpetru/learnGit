#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;
    class Song {
            string name;
            string genre;
            int secDuration;
        public:

            void set_name(string name);
            string get_name() const;
            
            void set_genre(string genre);
            string get_genre() const;
            
            void set_secDuration(int secDuration);
            int get_secDuration() const;

            Song(string = "", string = "", int = 0);

            Song(const Song &);

            ~Song();

            Song &operator=(const Song &);

            friend istream &operator>>(istream &, Song &);

            friend ostream &operator<<(ostream &, Song &);
    };
#endif  