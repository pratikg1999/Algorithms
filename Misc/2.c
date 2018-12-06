#include<stdio.h>
#include "bs.c"
void print(int *a, int n){
    int i=0;
    for (i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
}
int main(){
    printf("Enter the size of the array: ");
    int n,i, *a, result, index, flag=0;
    scanf("%d", &n);
    printf("Enter the array: ");
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    print(a, n);
    for(i=0;i<n;i++){
        index = rbSearch(a, n, 0, n-1, a[i], &result);
        if(index==a[i]){
            printf("In the array a[%d] = %d\n", index, a[i]);
            flag=1;
            break;
        }
    }
    if(flag!=1){
        printf("No such element is present in the array such that a[i]==i\n");
    }
    return 0;
}
