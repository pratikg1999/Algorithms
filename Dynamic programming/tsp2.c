#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int **c;
int n;
int initSource;
void print(int* a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);

    }
    printf("\n");
}
int tsp(int source, int* toVisit, int size){
    //int size = sizeof(toVisit);
    if(size==1){
        return c[source][toVisit[0]] + c[toVisit[0]][initSource];
    }
    int i;
    int tempAns;
    int ans= INT_MAX;
    int* tempToVisit = (int*)malloc(sizeof(int)*(size-1));
    for(i=0;i<size;i++){
        int j,k=0;
        for(j=0; j<size-1;j++, k++){
            if(k==i){
                k++;
            }
            tempToVisit[j] = toVisit[k];
        }
        tempAns = c[source][toVisit[i]] + tsp(toVisit[i], tempToVisit, size-1);
        if(tempAns<ans){
            ans = tempAns;
        }
    }
    return ans;
}
main(int argc, char const *argv[])
{
    printf("Enter the no. of cities: ");
    int n, i, j;
    scanf("%d", &n);
    c = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        c[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("Enter the cost adjacency matrix-\n");
    for(i=0;i<n;i++){
        
        for( j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
        
    }
    printf("Enter the source: ");
    int source;
    scanf("%d", &source);
    source--;
    initSource = source;
    int* toVisit = (int*) malloc(sizeof(int) *(n-1));
    j=0;
    for(i=0;i<n-1;i++){
        if(j == source){
            j++;
        }
        toVisit[i] = j;
        j++;
    }
    /*
    printf("%d\n", sizeof(toVisit));
    print(toVisit, n-1);
    */
    printf("%d\n", tsp(source, toVisit, n-1));
    return 0;
}
