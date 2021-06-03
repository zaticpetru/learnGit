#ifndef DB_HEADER
#define DB_HEADER

#include "../data/Playlist.h"
#include "../data/Song.h"

#include <fstream>
#include <iostream>

list<Playlist> readPlaylists();
list<Song> readPlaylistSongs(string playlistName);

extern list<Playlist> gPlaylists;
extern int gN;

#endif