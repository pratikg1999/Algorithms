#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int M, int *w, int *p, int n){
    int k[n+1][M+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=M;j++){
            if(i==0 || j==0){
                k[i][j]=0;
            }
            else if(w[i-1]<=j){
                k[i][j] = max(p[i-1] + k[i-1][j-w[i-1]], k[i-1][j]);
            }
            else{
                k[i][j] = k[i-1][j];
            }
        }
    }
    return k[n][M];
}
int main(int argc, char const *argv[])
{
    printf("Enter the knapsack capacity: ");
    int M, n;
    scanf("%d", &M);
    printf("Enter the number of weights: ");
    scanf("%d", &n);
    printf("Enter the weights: ");
    int *w =(int*)malloc(sizeof(int)*n);
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d", &w[i]);

    }
    printf("Enter the profits: ");
    int *p = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d", &p[i]);
    }
    printf("%d", knapsack(M, w, p ,n));
    return 0;
}
