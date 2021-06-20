#ifndef DB_HEADER
#define DB_HEADER

#include "../data/Playlist.h"
#include "../data/Song.h"

#include <fstream>
#include <iostream>

list<Playlist> readPlaylists();
list<Song> readPlaylistSongs(string playlistName);

void savePlaylists(list<Playlist> playlists);
void savePlaylistSongs(string playlistName, list<Song> songs);

Playlist getPlaylistByName(string searchString);

extern list<Playlist> gPlaylists;
extern int gN;

#endif