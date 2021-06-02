#ifndef MENUES_HEADER
#define MENUES_HEADER

#include <stdlib.h>
#include <iostream>

using namespace::std;

extern void (*current_menu)();
extern void (*current_handler)(char);

void clear_screen();
char getUserChoice();

void print_default(void (*print_menu)());
void handle_default(void (*handle_menu)(char), char choice);

void print_main_menu();
void handle_main_menu(char choice);

void print_playlist_menu();
void handle_playlist_menu(char choice);

#endif