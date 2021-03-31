#include <stdio.h>
#include <stdlib.h>

void clear_screen();
char getUserChoice();
void print_default(void (*print_menu)());
void handle_default(void (*handle_menu)(char), char choice);

void print_main_menu();
void handle_main_menu(char choice);

void print_raport_menu();
void handle_raport_menu(char choice);

void print_incidente_menu();
void handle_incidente_menu(char choice);

void print_info_menu();
void handle_info_menu(char choice);

void (*current_menu)();
void (*current_handler)(char choice);