#include <stdio.h>
#include <stdlib.h>
int ** intmat(int nl, int nc){
    int i;
    int **p=(int**)malloc(nl*sizeof(int*));
    if (p!=NULL)
        for(i=0;i<nl;i++)
            p[i]=(int*)calloc(nc,sizeof(int));
    return p;
}

int ** eliminare(int ** a,int nl,int nc,int *lungimiLinii){
    int i,j,k=0,nr,ok;
    int **mat=(int**)malloc(nl*sizeof(int*));
    if(mat!=NULL)
        for (i=0;i<nl;i++){
            mat[i]=(int*)malloc(nl*sizeof(int*));
            nr=0;
            for(j=0;j<nc;j++){
                ok=1;
                for(k=0;k<nr;k++){
                    if(mat[i][k]==a[i][j])
                        ok=0;}
                if(ok==1){
                    mat[i][nr]=a[i][j];
                    nr=nr+1;}
            }
            lungimiLinii[i]=nr;
            realloc(mat[i],nr);
        }
    return mat;
}

void printmat(int **a,int nl,int nc){
    int i,j;
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++)
            printf("%d",a[i][j]);
        printf("\n");}
}

void printmat2(int **a,int nl,int *lungimiLinii){
    int i,j;
    for(i=0;i<nl;i++){
        for(j=0;j<lungimiLinii[i]-1;j++)
            printf("%d ",a[i][j]);
        printf("%d\n", a[i][j]);}
}

int main()
{
    int ** a,nl,nc,i,j,val;
    //printf("Intoduceti nr de linii si de coloane:\n");
    scanf("%d%d",&nl,&nc);
    a=intmat(nl,nc);
    for (i=0;i<nl;i++)
        for(j=0;j<nc;j++){
            //printf("a[%d][%d]=",i,j);
            scanf("%d",&val);
            a[i][j]=val;
        }
    //printmat(a,nl,nc);
    int *lungimiLinii=(int*)malloc(nl*sizeof(int));
    a=eliminare(a,nl,nc,lungimiLinii);
    printmat2(a,nl,lungimiLinii);
    return 0;
}
