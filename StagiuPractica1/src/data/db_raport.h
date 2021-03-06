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
char* RaportToStrFormatted(raport r, int format);

// RETURNS - 0 if read/save was successful
// RETURNS - -1 if error
int ReadRaports();
int SaveRaports();

void PrintRaports(int format);

// RETURNS - 0 if add/delete was successful
// RETURNS - -1 if error
int AddRaport(raport newRaport);
int DeleteRaport(int id);
raport CrateRaport(char* title, char* location, char* description);

void FilterProductsByLocation(char* filter, int format);
void FilterProductsByTitle(char* filter, int format);


#endif