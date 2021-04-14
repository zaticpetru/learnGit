#ifndef RAPORTS_HEADER
#define RAPORTS_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct raport
{
    int ID;
    char Title[80];
    char Location[80];
    char Description[150];
} raport;

raport StrToRaport(char *str);
char* RaportToStr(raport r);
char* RaportToStrNoSpaces(raport r);
char* RaportToStrBeautified(raport r);


// RETURNS - 0 if read/save was successful
// RETURNS - -1 if error
int ReadRaports();
int SaveRaports();

void PrintRaports();

// RETURNS - 0 if add/delete was successful
// RETURNS - -1 if error
int AddRaport(raport newRaport);
int DeleteRaport(int id);
raport CrateRaport(char* title, char* location, char* description);

#endif