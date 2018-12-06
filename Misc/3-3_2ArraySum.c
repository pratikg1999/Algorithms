#include<stdio.h>
#include "bs.c"
#include<stdlib.h>

void main(){
    int i,m,n;
    printf("Enter the length of the first array: ");
    scanf("%d", &m);
    int* a = (int*)malloc(sizeof(int)*m);
    
    printf("enter the first array: ");
    for(i=0;i<m;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the length of the second array: ");
    scanf("%d", &n);
    int* b = (int*)malloc(sizeof(int)*n);
    
    printf("enter the second array: ");
    for(i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    printf("Enter the key to search: ");
    int key, result;
    scanf("%d", &key);
    int small,big;
    int *first, *second;
    if(m>n){
        small=n;
        big=m;
        first = b;
        second = a;

    }
    else{
        small=m;
        big=n;
        first = a;
        second = b;
    }
    for(i=0;i<small;i++){
        int k = key-first[i];
        int j = rbSearch(second, big, 0, big-1, k, &result);
        if(j!=-1){
            printf("The elements are %d of 1st and %d of second\n", first[i], second[j]);
            return;
        }
    }
    printf("No such elements\n");
    

    
}