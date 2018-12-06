#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
void print(int* a, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", a[i]); 
	}
	printf("\n");
	
}
int* findOrder(int** a, int start, int end){
	//int ans[2];
	int* toReturn = (int*)malloc(sizeof(int)*2);
	toReturn[0] = a[start][0];
	toReturn[1] = a[end][1];
	return toReturn;
}

int findScalarMuls(int **a, int start, int end, int* k){
	int i,j;
	if(end<=start){
		*k=-1;
		return 0;
	
	}
	//int n=end-start;
	int ans=INT_MAX;
	for(i=start;i<end;i++){
		int tempKLeft=-1;
		int tempKRight = -1;
		printf("%d %d %d\n", start, end ,i);
		int left = findScalarMuls(a, start, i, &tempKLeft);
		int right = findScalarMuls(a, i+1, end, &tempKRight);
		int* orderLeft = findOrder(a, start, i);
		int* orderRight = findOrder(a, i+1, end);
		print(orderLeft, 2);
		print(orderRight,2);
		int tempAns = left+right+orderLeft[0] * (orderLeft[1] * (orderRight[1]));
		printf("%d %d %d %d\n\n", start, end, i, tempAns);
		if(tempAns<ans){
			ans = tempAns;
			*k = i;
		}
	}
	return ans;
}
void main(){
	int n,i,j;
	printf("Enter the no., of matrixes: ");
	scanf("%d", &n);
	int** a = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		a[i] = (int*)malloc(sizeof(int)*2);
	}
	printf("enter the order of matrixes-\n");
	for(i=0;i<n;i++){
			scanf("%d %d", &a[i][0], &a[i][1]);
	}
	
	int k=-1;
	int ans = findScalarMuls(a, 0,n-1, &k);
	printf("%d %d\n", ans, k);
	printf("\n");
	/*
	for(i=1;i<n;i++){
			print(findOrder(a, 1,i), 2);
	}
	*/
}
