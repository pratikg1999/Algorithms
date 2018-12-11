#include<stdio.h>
#include<stdlib.h>
// method to print the order of nodes in depth first traversal
void dfs(int **c, int n, int vertex, int *isVisited){
    printf("%d\n", vertex); //print the node(source) to traverse
    isVisited[vertex]=1;    //mark the node as visited
    int i=0;
    for(i=0;i<n;i++){
        if(c[vertex][i]==1 && isVisited[i]==0){ //finds the first non-visited adjacent node and traverses it
            dfs(c, n, i, isVisited);
        }
    }
}

void main(){
    printf("Enter the no. of vertices: ");
    int n,i,j;
    scanf("%d", &n);
    int **c = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        c[i] = (int*)malloc(sizeof(int)*n);

    }
    printf("Enter the adjacency matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &c[i][j]);
        }
    }
    int *isVisited = (int*)calloc(sizeof(int), n);
    dfs(c, n, 0, isVisited);
}