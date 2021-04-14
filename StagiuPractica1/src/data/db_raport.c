#include "db_raport.h"

raport Data[100];
int N = 0;
char *INCIDENT_FILE_NAME = "incidente.csv";
int ID_TO_DELETE = -1;

raport StrToRaport(char *str) { // TESTED - WORKING
    raport result;

    char strC[310];
    char *delim = ",";
    char parts[5][150];

    strcpy(strC,str);

    char *ptr = strtok(strC,delim);

    int i = 0;
    while(ptr != NULL){
        strcpy(parts[i],ptr);
        ptr = strtok(NULL, delim);
        i++;
    }

    result.ID = atoi(parts[0]);

    strcpy(result.Title,parts[1]);

    strcpy(result.Location,parts[2]);

    strcpy(result.Description,parts[3]);

    return result;
}

char* RaportToStr(raport r){ // TESTED - WORKING
    char *buffer;
    buffer = (char*)malloc((310)*sizeof(char));
    snprintf(buffer, 310, "%d, %s, %s, %s, \n", r.ID, r.Title, r.Location, r.Description);
    return buffer;
}

char* RaportToStrNoSpaces(raport r){ // TESTED - WORKING
    char *buffer;
    buffer = (char*)malloc((310)*sizeof(char));
    snprintf(buffer, 310, "%d,%s,%s,%s,\n", r.ID, r.Title, r.Location, r.Description);
    return buffer;
}

// RETURNS - 0 if read was successful
// RETURNS - -1 if error
int ReadRaports() { // TESTED - WORKING
    FILE *fpt;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fpt = fopen(INCIDENT_FILE_NAME, "r");
    if(fpt == NULL){
        printf("\nFile NOT opened!\n");
        return -1;
    }

    N = 0;
    while ((read = getline(&line, &len, fpt)) != -1){
        // line - retrived string
        // read - length of retrived string

        Data[N] = StrToRaport(line);
        N++;
    }
    fclose(fpt);

    if (line)
        free(line);

    return 0;
}

void PrintRaports(){
    for(int i = 0; i < N; i++){
            printf("%s", RaportToStr(Data[i]));
        }
}

int SaveRaports() {
    FILE *out;
    out = fopen(INCIDENT_FILE_NAME, "w");
    if(out == NULL)
        return -1;

    for(int i = 0; i < N; i++){
        if(Data[i].ID != ID_TO_DELETE){
            fprintf(out, "%s", RaportToStrNoSpaces(Data[i]));
        }
    }

    fclose(out);
}

int AddRaport(raport newRaport) {
    Data[N] = newRaport;
    N++;
    return SaveRaports();
}

int DeleteRaport(int id) {
    ID_TO_DELETE = id;

    int result = SaveRaports();

    ID_TO_DELETE = -1;
    ReadRaports();

    return result;
}

raport CrateRaport(int id, char* title, char* location, char* description) {
    raport newRaport;
    newRaport.ID = id;
    strcpy(newRaport.Title, title);
    strcpy(newRaport.Location, location);
    strcpy(newRaport.Description, description);
    return newRaport;
}

// int main() {
    

//     ReadRaports();
//     AddRaport(CrateRaport(4,"new title", "new location", "new description"));
//     PrintRaports();
//     DeleteRaport(4);
//     printf("\n\n");
//     PrintRaports();
//     return 0;
// }