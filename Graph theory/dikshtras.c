#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// 
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

void printPath(int source, int dest, int* path){
    if(path[dest]==dest)
        printf("%d -> ", source+1);
    if(path[dest]!=dest){
        printPath(source, path[dest], path);
        printf(" -> ");
    }
    printf("%d", dest+1);
    /*
    if(path[dest]==dest){
        print(dest);
    } 
    */
}
void main(int argc, char const *argv[])
{
    int n,i,j;
    int source;
    int visited = 0;
    printf("Enter the no. of vertices ");
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
    int* result = (int*)malloc(sizeof(int)*(n+1));  //array to store the min distance from source
    
    for( i = 0; i < n; i++)
    {
        result[i] = c[source][i];   //initial distance is the immediate distance
    }
    result[n]= INT_MAX;    //last element is just used for ease in algorithm
    int* isVisited = (int*)malloc(sizeof(int)*(n));
    isVisited[source]=1;

    int* path=(int*)malloc(sizeof(int)*(n));
    for(i=0;i<n;i++){
        path[i] = i;
    }

    printf("");
    while(visited<n-1){
        //find the closest non-visited element from source 
        int cur=n;
        for(i=0;i<n;i++){
            if(isVisited[i]!=1 && result[i]<result[cur]){
                cur = i;
            }
        }
        isVisited[cur] = 1; 
        visited++;
        for(i=0;i<n;i++){
            if(isVisited[i]!=1){
            //result[i] = min(result[i], result[cur] + c[cur][i]);
            //if the distance through the cur elemnt is less than current min distance
            if(result[i]>result[cur] + c[cur][i]){  
                result[i] = result[cur] + c[cur][i];
                path[i] = cur;
            }
            }
        }

    }
    print(result, n);
    for(i=0;i<n;i++){
        if(i==source){
            continue;
        }
        printPath(source,i,path);
        printf("\n");
    }
    printf("\n");
}
