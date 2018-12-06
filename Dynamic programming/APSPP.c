/**program to calculate the shortest path between all pairs of vertices
 *
 */

//The standard libraries
#include<stdio.h>
#include<stdlib.h>

int** c;        //cost adjacency matrix
int** path;     //matrix to store the path
int n;          //Number of vertices

/** 
 * Helper method to print a matrix
 */
void print(int** a, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]); 

        }
        printf("\n");
	}
	printf("\n");
	
}

/** 
 * Method to find the path from vertex i to j
 */
void findPath(int i, int j){
    if(path[i][j]==-1){
        //printf("%d", j);
        return;
    }
    
    else{
        findPath(i, path[i][j]);
        printf("%d -> ", path[i][j]);
        findPath(path[i][j], j);
    }
    
}

/**
 * Prints the path for all vertices
 */
void printPath(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d -> ", i);
            findPath(i,j);
            printf("%d\n", j);
        }
        //printf("\n");
    }
}

/* Finds the shortest path from all vertices to all vertices */
void findMinPath(){
    int i,j,k;
    for(i=0;i<n;i++){                   // i represents the intermediate vertex
        
        for( j = 0; j < n; j++)         // j represents the souce vertex
        {
            
            for( k = 0; k < n; k++)     // k represents the destination vertex
            {
                if(c[j][k]>c[j][i] + c[i][k]){
                    c[j][k] = c[j][i]+ c[i][k];
                    path[j][k] = i;
                }
            }
            
        }
        
    }
}

/* main() method to test the algorithm*/
void main(){
    printf("Enter the no. of vertices: ");
    int i,j;
    scanf("%d", &n);
    c = (int**)malloc(sizeof(int*)*n);
    path = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        c[i] = (int*)malloc(sizeof(int)*n);
        path[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            path[i][j] = -1;
        }
    }
    printf("Enter the cost adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &c[i][j]);
        }
    }
    print(c, n, n);
    findMinPath();
    print(c, n, n);
    print(path, n ,n);
    printPath();
    printf("\n");
}