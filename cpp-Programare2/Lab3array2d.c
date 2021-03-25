#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 2, m = 4;
    int a[100][100] = {
        {10, 11, 11, 13},
        {14, 15, 16, 17}
    };
    char isEaven;
    int rs = 0;

    for (int j = 0; j < m; j++)
    {
        isEaven = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i][j] % 2 == 0) {
                isEaven = 1;
            }
        }
        rs += isEaven;
    }
    

    printf("\n%d\n", rs);

    return 0;
}