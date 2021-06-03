#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void Playlist::set_name(string name){
    this->name = name;
}
string Playlist::get_name() const{
    return this->name;
}

void Playlist::set_rating(float rating){
    this->rating = rating;
}
float Playlist::get_rating() const{
    return this->rating;
}

void Playlist::set_songs(list<Song> songs) {
    this->songs = songs;
}
list<Song> Playlist::get_songs() const{
    return this->songs;
}

Playlist::Playlist(string name, float rating)
{
    if (name.empty())
    {
        this->name = name;
    }

    this->rating = rating;
    this->songs = list<Song>();
}

Playlist::Playlist(const Playlist &playlist)
{
    if (name.empty())
    {
        this->name = playlist.name;
    }
    this->rating = playlist.rating;
    this->songs = list<Song>();
}

Playlist::~Playlist()
{
    // deconstructor
}

bool Playlist::AddSong(Song &song) {
    const Song toPush = song;
    this->songs.push_back(toPush);
    return true;
}

Playlist &Playlist::operator=(const Playlist &playlist)
{
    if (this == &playlist)
        return *this;

    if (name.empty())
    {
        this->name = playlist.name;
    }
    this->rating = playlist.rating;

    return *this;
}

istream &operator>>(istream &in, Playlist &playlist)
{
    playlist.songs = list<Song>();
    getline(in, playlist.name);
    in >> playlist.rating;
    in.ignore();

    return in;
}

ostream &operator<<(ostream &out, const Playlist &playlist)
{
    out << "Name: " << playlist.name << "\n"
        << "Rating: " << playlist.rating << "\n";

    int counter = 1;

    out << "Number of songs in playlist " << playlist.songs.size() << "\n";

    for(const auto &it : playlist.songs) {
        int secDuration = it.get_secDuration();

        out << counter << ") " << secDuration/60 << ":" << secDuration%60 << " name: " << it.get_name() << " genre: " << it.get_genre() << "\n";
        counter++;
    }

    return out;
}