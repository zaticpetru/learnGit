#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

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

ostream &operator<<(ostream &out, Playlist &playlist)
{
    out << "Name: " << playlist.name << "\n"
        << "Rating: " << playlist.rating << "\n";
    int counter = 1;
    // for (list<Song>::iterator it = playlist.songs.begin(); it != playlist.songs.end(); ++it){
    //     out << counter << ") " << it->name << "\n";
    // }

    out << "Number of songs in playlist " << playlist.songs.size() << "\n";

    Song output;
    for(list<Song>::iterator it = playlist.songs.begin(); it != playlist.songs.end(); it++){
        int secDuration = it->secDuration;

        out << counter << ") " << secDuration  << " name: " << it->name << "\n";
        counter++;
    }


    return out;
}