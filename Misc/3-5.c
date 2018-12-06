#include<stdio.h>
#include<stdlib.h>
#include "MergeSort.c"
/*
void print(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
*/
void main(){
    printf("Enter the size of the array: ");
    int n,i, *a, result, index, flag=0;
    scanf("%d", &n);
    printf("Enter the array: ");
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("The arraty entered is: ");
    print(a, n);
    
    mSort(a, 0, n-1, n);
    printf("The sorted array is :");
    print(a, n);
    int freq=0, max=0, maxElement = -1;
    int cur =-1;
    for(i=0;i<n;i++){
        if(a[i]==cur){
            freq++;
        }
        else{
            if(freq>max){
                max = freq;
                maxElement = a[i-1];
            }
            cur=a[i];
            freq=1;
        }
    }
    if(freq>max){
        max = freq;
        maxElement = a[n-1];
    }
    printf("The element %d repeats maximum with %d repetitions\n", maxElement, max);
    
}
