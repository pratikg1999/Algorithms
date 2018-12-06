#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print(int* a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int **c;

int min(int a, int b){
    return a<b?a:b;
}
void main(int argc, char const *argv[])
{
    int n,i,j;
    int source;
    int visited = 0;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    c=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        c[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("Enter the cost adcanceny matrix:\n");
    for(i=0;i<n;i++){
        
        for( j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
        
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    source--;
    int* result = (int*)malloc(sizeof(int)*(n+1));
    
    for( i = 0; i < n; i++)
    {
        result[i] = c[source][i];
    }
    result[n]= INT_MAX;
    int* isVisited = (int*)malloc(sizeof(int)*(n));
    isVisited[source]=1;

    while(visited<n-1){
        int cur=n;
        for(i=0;i<n;i++){
            if(isVisited[i]!=1 && result[i]<result[cur]){
                cur = i;
            }
        }
        isVisited[cur] = 1;
        visited++;
        for(i=0;i<n;i++){
            result[i] = min(result[i], result[cur] + c[cur][i]);
        }

    }
    print(result, n);
    printf("\n");
}
