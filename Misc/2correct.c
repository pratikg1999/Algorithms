#include<stdio.h>
#include<stdlib.h>

/*void print(int *a, int n){
    printf("Printing--\n");
    int i=0;
    for (i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}*/
void main(){
    printf("Enter the size of the array: ");
    int n,i, *a;
    scanf("%d", &n);
    a =(int*)malloc(sizeof(int)*n);
    printf("Enter the array: ");
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    //print(a, n);
    int mid = (n-1)/2;
    int l=0, h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid]==mid){
            printf("a[%d] = %d\n", mid,mid);
            return;
        }
        else if(mid<a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("No such element in the array\n");
}