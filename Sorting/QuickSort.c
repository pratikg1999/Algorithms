#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int i1, int i2){
    int temp = a[i1];
    a[i1] = a[i2];
    a[i2] = temp;
}
void qSort(int *a, int low, int high, int n){
    
    if(high>low){
    printf("low: %d\t high: %d\n", low,high);
    printf("for a[%d] i.e. %d: ", low, a[low]);
    int loc, l, r;
    l=loc = low;
    r=high;
    while(r>l){
        while(a[r]>a[loc] && r>l){
            r--;
        }
        swap(a, loc, r);
        if(r!=loc){
           l++;
        }
        loc=r;

        print(a,n);
        while(a[l]<a[loc] && l<r){
            l++;
        }
        swap(a, l, loc);
       if(l!=loc){
        r--;
        }
        
         loc = l;
        print(a,n);
    }
    print(a, n);
    qSort(a, low, loc-1, n);
    qSort(a, loc+1, high, n);
    
    }
}

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
    
    qSort(a, 0, n-1, n);
    printf("The sorted array is :");
    print(a, n);
}
