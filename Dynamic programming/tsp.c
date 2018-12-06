#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int comb(int** table, int n, int k){
    if(table[n][k]!= 0)
        return table[n][k];
    if(k==0 or k==n){
        table[n][k] = 1
        return 1
    }
    table[n][k] = comb(table,n-1,k-1)  + comb(table, n-1,k);
    return table[n][k];
}

int findComb(int n, int k){
    int **table = (int**)malloc(sizeof(int*)*(n+1));
    int i;
    for(i=0;i<n+1;i++){
        table[i] = (int*)calloc(sizeof(int), n);
    }
    return comb(table, n, k);
}

void main(){
    printf("Enter the no. of cities: ");
    int n, i,j,k,l;
    scanf("%d", &n);
    int **c = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        c[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("Enter the cost adjacency matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &c[i][j]);
        }
    }
    int source;
    printf("Enter the source city: ");
    scanf("%d", &source);
    source--;
    int* sizes = (int*)malloc(sizeof(int)*n-2);

    //The memory required to store the subproblems
    int*** result = (int***)malloc(sizeof(int**)*(n-2));
    for(i=0;i<n-2;i++){
        result[i] = (int**)malloc(sizeof(int*)*(n));
        int size = findComb(n-2, i+1);
        sizes[i] = size;
        for(j=0;j<n;j++){
            result[i][j] = (int*)malloc(sizeof(int)*size);
        }
    }
    
    for(i=0;i<n;i++){
        if(i!=source){
            for(j=0;j<n-1;j++){
                if(j!=source){
                    result[0][i][j] = c[i][j] + c[j][source];
                }
            }
        }
    }
    for(i=1;i<n-2;i++){
        for(j=0;j<n;j++){
            if(j!=source){
                for(k=0;k<sizes[i];k++){
                    int tempAns= INT_MAX;
                    for(l=0;l<)
                }
            }
        }
    }

}