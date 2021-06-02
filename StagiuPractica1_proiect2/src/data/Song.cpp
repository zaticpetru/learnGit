#include <iostream>
#include <cstring>
#include <string>
#include "Song.h"

using namespace std;

void Song::set_name(string name)
{
    if(name.length() == 0) {
        cout << "Error, no name provided";
        return;
    }
    this->name = name;
}

string Song::get_name() const {
    return this->name;
}

void Song::set_genre(string genre) {
    this->genre = genre;
}

string Song::get_genre() const {
    return this->genre;
}

void Song::set_secDuration(int secDuration) {
    this->secDuration = secDuration;
}

int Song::get_secDuration() const {
    return secDuration;
}

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