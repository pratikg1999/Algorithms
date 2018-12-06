#include<stdio.h>
#include<stdlib.h>

int bSearch(int* a, int n, int key, int* result, int except){//result will contain a boolean variable representing true or false. Except is the element not icluded in the search
    int l=0;
    int h = n-1;
    int mid;
    *result=0;
    while(l<=h){
        mid = (l+h)/2;
        if(key == a[mid]){
            if(a[mid]==except){     //if the element 'except' is present..we return false
                return -1;
            }
            *result = 1;
            return mid;
        }
        else if (key < a[mid]){ //since key<A[mid], x is present in the first half of the sorted array
            h=mid-1;
        }
        else{       //since key>A[mid], x is present in the second half of the sorted array
            l=mid+1;
        }
    }
    return -1;
}

int rbSearch(int* a, int n,int start, int end,  int key, int* result){
    int mid = (start+end)/2;
    *result = 0;
    if(start>end){
        return -1;
    }
    if(key==a[mid]){
        *result = 1;
        return mid;
    }
    else if (key<a[mid]){
        return rbSearch(a, n , start, end-1, key, result);
    }
    else{
        return rbSearch(a, n, mid+1, end, key, result);
    }
}

int main(){
    printf("Enter the length of the array: ");
    int i,n;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*n);
    
    printf("enter the array: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("enter the key to search: ");
    int key, index, result;
    scanf("%d" , &key);
    index = rbSearch(a, n,0, n-1, key, &result);
    printf("The key is at index %d in the array\n", index);
    return 0;
}

