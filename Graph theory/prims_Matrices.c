#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print(int** a, int n){
    int i=0, j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}

void print1D(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void main(){
    int i=0,j=0;
    printf("enter the no. of vertices in the graph: ");
    int n;
    scanf("%d", &n);
    int maxnoEdges = n-1;
    int curEdges=0;
    int **g = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        g[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("enter the cost adjacency matrix-\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &g[i][j]);
        }
    }
    print(g,n);
    int **t  = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        t[i] = (int*)calloc(sizeof(int),n);
    }
    int min=INT_MAX , minI=0, minJ=0;
    int *isVisited = (int*)calloc(sizeof(int), n);
    int noEdges=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j]<min && i!=j){
                min = g[i][j];
                minI = i;
                minJ = j;
            }
        }
    }
    isVisited[minI]=1;
    isVisited[minJ]=1;
    t[minI][minJ] = min;
    noEdges++;
    print(t,n);
    while(noEdges<n-1){
        min=INT_MAX;
        minI=minJ=0;
        for(i=0;i<n;i++){
            if(isVisited[i]==1){
                for(j=0;j<n;j++){
                    if(isVisited[j]==0){
                        if(g[i][j]<min){
                            min = g[i][j];
                            minI=i;
                            minJ=j;
                        }
                    }
                }

            }
        }
        t[minI][minJ] = min;
        isVisited[minJ]=1;
        noEdges++;
        print1D(isVisited, n);
    }
    print(t, n);
    printf("\n");
}