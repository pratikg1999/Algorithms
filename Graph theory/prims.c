#include<stdio.h>
#include<stdlib.h>

void main(){
    int i=0,j=0;
    printf("enter the no. of vertices in the graph: ");
    int n;
    scanf("%d", &n);
    int maxnoEdges = n-1;
    int curEdges=0;
    int **g = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        *g = (int*)malloc(sizeof(int)*n);
    }
    printf("enter the cost adjacency matrix-\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &g[i][j]);
        }
    }
}