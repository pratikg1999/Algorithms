#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void main(){
    int i=0,j=0;
    printf("Enter the no. of jobs: ");
    int n;
    scanf("%d", &n);
    int *p = (int*)malloc(sizeof(int)*n);
    int* d = (int*)malloc(sizeof(int)*n);
    int* pr = (int*)malloc(sizeof(int)*n);
    printf("Enter the profits: ");//Note all profits should be differnet to calccorrect profits
    for(i=0;i<n;i++){
        scanf("%d", &p[i]);
    }
    printf("Enter the deadlines: ");
    for(i=0;i<n;i++){
        scanf("%d", &d[i]);
    }

    int maxDeadline = 0;
    for(i=0;i<n;i++){
        if(d[i]>maxDeadline){
            maxDeadline = d[i];
        }
    }
    int*sq=(int*)calloc(maxDeadline+1, sizeof(int));
    int prevMax = 1000000000;
    for(j=0;j<n;j++){
        int key=0;
        int max=0;
        for(i=0;i<n;i++){
            if(p[i]>max && p[i]<prevMax){
                max = p[i];
                key = i;
            }
        }
        pr[j] = key;
        prevMax = max;
    }
    print(pr, n);

    for(i=0;i<n;i++){
        for(j=d[pr[i]];j>0;j--){
            if(sq[j]==0){
                sq[j] = pr[i]+1;
                break;
            }
        }
    }

    print(sq, maxDeadline+1);
}