#include <iostream>
#include <cstring>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(string name, string genre, int secDuration)
{
    this->name = name;
    this->genre = genre;
    this->secDuration = secDuration;
}

Song::Song(const Song &song)
{
    this->name = song.name;
    this->genre = song.genre;
    this->secDuration = song.secDuration;
}

Song::~Song()
{
    // deconstructor
}

Song &Song::operator=(const Song &song)
{
    if (this == &song)
        return *this;

    this->name = song.name;
    this->genre = song.genre;
    this->secDuration = song.secDuration;

    return *this;
}

istream &operator>>(istream &in, Song &song)
{
    getline(in, song.name);
    getline(in, song.genre);

    in >> song.secDuration;
    in.ignore();

    return in;
}

ostream &operator<<(ostream &out, Song &song)
{
    out << "Name: " << song.name << "\n"
        << "Genre: " << song.genre << "\n"
        << "Duration: " << song.secDuration / 60 << ":" << song.secDuration % 60 << "\n";
    return out;
}