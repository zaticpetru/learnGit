#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n){
    if(n <= 0){
        printf("\n");
        return;
    }
    printArr(arr, n-1);
    printf("%d, ", arr[n-1]);
}


// printArr - main -  n = 6
    
//     printArr n = 5
    
//         printArr n = 4

//             printArr n = 3
//                 1, 2, 3
//                 printArr n = 2
//                     1, 2
//                     printArr n = 1 XXXX
//                         1,
//                         printArr n = 0 XXX
//                             return 


int main(){
    int n = 6;
    int arr[6] = { 1, 2, 3, 4, 5, 6 };

    printArr(arr,n);

    return 0;
}