#include <stdio.h>
#include <stdlib.h>

int transformare(int n)
{
    char rs[32] = "00000000000000000000000000000000";
    int i = 31;
    while(n){
        rs[i] = (n % 2) ? '1' : '0';
        i--;
        n /= 2;
    }
    return atoi(rs);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", transformare(n));
    return 0;
}