#include <stdio.h>
#include <stdlib.h>

// %s – pentru citirea unei variabile de tip șir de caractere
// %d – pentru citirea unei variabile de tip întreg (zecimale)
// %f – pentru citirea unei variabile de tip float
// %lf – pentru citirea unei variabile de tip double 
// %c – pentru citirea unei variabile de tip caracter

#define perimetru(n,m) ((n*2) + (m*2))

int aria(int n, int m) {
    return n * m;
}

void deseneazaLinie(int m) {
    while(m--){
        printf("#");
    }
    printf("\n");
}

void deseneazaLinieSpatii(int m) {
    printf("#");
    int i = 2;
    while(i < m){
        printf(" ");
        i++;
    }
    if(m > 1){
        printf("#");
    }
    printf("\n");
}

void deseneazaDreptunghi(int n, int m){
    deseneazaLinie(m);
    for(int i=1; i < n-1; i++) {
        deseneazaLinieSpatii(m);
    }
    if(n > 1){
        deseneazaLinie(m);
    }
}

void deseneazaDreptunghiPlin(int n, int m){
    for(int i=0; i < n; i++) {
        deseneazaLinie(m);
    }
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    printf("dreptunghiul cu laturile %d si %d\n", n, m);
    printf("are aria = %d\n", aria(n,m));
    printf("are perimetru = %d\n", perimetru(n,m));
    deseneazaDreptunghiPlin(n,m);

    return 0;
}
