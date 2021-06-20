#ifndef MENUES_HEADER
#define MENUES_HEADER

#include <stdlib.h>
#include <string>
#include <iostream>
#include <list>
#include "../data/Playlist.h"
#include "../data/Song.h"
#include "../fileDb/db.h"

using namespace::std;

extern void (*current_menu)();
extern void (*current_handler)(char);

extern list<Playlist> gPlaylists;
extern int gN;

void clear_screen();
char getUserChoice();

void print_default(void (*print_menu)());
void handle_default(void (*handle_menu)(char), char choice);

/**
 *? list of currently aviable menus 
 *? In pair with a handler
 */

void print_main_menu();
void handle_main_menu(char choice);

void print_playlist_menu();
void handle_playlist_menu(char choice);

void print_manage_playlist_menu();
void handle_manage_playlist_menu(char choice);

#endif