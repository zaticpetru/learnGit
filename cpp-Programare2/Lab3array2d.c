#include <string.h>
#include <stdio.h>

int findStr(char *big, char *small) {
    int n = strlen(big);
    int m = strlen(small);
    int find = 0;
    
    if(n < m) {
        return 0;
    }
    
    for(int i = 0; i < n - m; i++){
        find = 1;
        for(int j = 0; j < m; j++){
            if(big[i+j] != small[j]){
                find = 0;
            }
        }
        if(find == 1){
            return find;
        }
    }
    
    return find;
}

int main() {
    int n;
    int i = 0;
    scanf("%d", &n);
    
    char inpt[100][100];
    char *str;
    
    while(i < n) {
        scanf("%s", inpt[i]);
        i++;
    }
    
    scanf("%s", str);
    
    for(i = 0; i < n; i++) {
        printf("%s\n", inpt[i]);
        printf("%d\n", findStr(inpt[i], str));
    }
    
    return 0;
}

