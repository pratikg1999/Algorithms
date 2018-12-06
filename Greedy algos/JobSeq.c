#include<stdio.h>
#include<stdlib.h>

//Helper function to print an array
void print(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void main(){
    int i=0,j=0;
    int profit=0;
    printf("Enter the no. of jobs: ");
    int n;
    scanf("%d", &n);
    int *p = (int*)malloc(sizeof(int)*n);   //array to store the profits of jobs
    int* d = (int*)malloc(sizeof(int)*n);   //array to store the deadlines of respective jobs
    int* pr = (int*)malloc(sizeof(int)*n);  //array to store the index of jobs in order of priorities
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
    //Array to store the position of the job in the solution set
    int*sq=(int*)calloc(maxDeadline+1, sizeof(int));
    int prevMax = 1000000000;

    //Giving priorites to jobs according to their profit
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
    printf("Arrangement of jobs in order of decreasing priority:\n");
    print(pr, n);

    //Greedy method to check the job can be part of solution set
    for(i=0;i<n;i++){
        for(j=d[pr[i]];j>0;j--){
            if(sq[j]==0){
                sq[j] = pr[i]+1;
                profit+=p[pr[i]];
                break;
            }
        }
    }

    //Print the solution
    printf("The solution set is:\n");
    //print(sq, maxDeadline+1);
    for(i=1;i<maxDeadline+1;i++){
        printf("%d\t", sq[i]);
    }
    printf("\n");

    //Print the max-possible-profit
    printf("Max profit: %d\n", profit);
}