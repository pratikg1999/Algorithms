#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int l, int mid, int r, int n){
    int i=l, k=0,j=mid+1;
    int*c = (int*)malloc(sizeof(int)*(r-l+1));
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            c[k] = a[i];
            i++;
            k++;
        }
        else{
            c[k] = a[j];
            j++;
            k++;
        }
    
    }
    while(i<=mid){
        c[k] = a[i];
        i++;
        k++;
    }
    while(j<=r){
        c[k] = a[j];
        j++;
        k++;
    }
    for(k=0;k<r-l+1;k++){
        a[l+k] = c[k];
    }
    print(a,n);
}

void mSort(int* a, int l, int r, int n){
    if(r-l>=1){
        int mid = (l+r)/2;
        mSort(a, l, mid, n);
        mSort(a, mid+1, r, n);
        merge(a, l, mid, r, n);
    }
    
}

/*
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
    
}
*/
