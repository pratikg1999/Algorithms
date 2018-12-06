#include<stdio.h>
#include "bs.c"
int main(){
    printf("Enter the length of the array: ");
    int i, n, index, result, key, flag=0;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*n);
    
    printf("enter the array: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("enter the key to search: ");
    scanf("%d", &key);
    for(i=0;i<n;i++){
        index = bSearch(a, n, key-a[i], &result, a[i]);
        if(result==1){
            printf("The elements are %d and %d\n", a[i], a[index]);
            flag=1;
            break;
        }
    }
    if(flag!=1){
        printf("No such combination of elements are present\n"); 
    }
}
