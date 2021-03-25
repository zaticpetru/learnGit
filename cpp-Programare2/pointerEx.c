#include <stdio.h>
#include <stdlib.h>


void change(int *k) {
    (*k) = 5; 
}

int main(){
    int *n = (int*)malloc(sizeof(int) * 20);
    

    change(n+1);
    printf("\n%d\n", *(n + 1));
    return 0;
}