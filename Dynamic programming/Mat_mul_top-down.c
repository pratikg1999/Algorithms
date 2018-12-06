/**program to calculate the minimum number of scalar multiplications needed
 * to calcualate matrix multiplications of matrices of given order
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/**table to store the result of subproblems
 * upper right triangle to store the results
 * lower right triangle to store the position of parenthesis
 */
int** table; 

void print(int** a, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]); 

        }
        printf("\n");
	}
	printf("\n");
	
}
/**method to find the minimum numbers of scalar multiplications needed 
 * for matrix multiplication
 */
int findMinOrder(int* orders, int start, int end){
    if(end<=start){
        return 0;
    }
    if(table[start][end]!=0){
        return table[start][end];
    }
    else{
        int i;
        int ans = INT_MAX;
        int tempAns;
        for(i=start;i<end;i++){
            tempAns = findMinOrder(orders, start, i) + findMinOrder(orders, i+1, end) + orders[start] * orders[i+1] * orders[end+1];
            if(tempAns<ans){
                ans = tempAns;
                table[end][start] = i;
            }
        }
        table[start][end] = ans;
        return table[start][end];
    }
}
void main(){
    printf("Enter the number of matrices: ");
    int n,i,j;
    scanf("%d", &n);
    printf("Enter the order of the matrices: ");
    int orders[n+1];
    for(i=0;i<n+1;i++){
        scanf("%d", &orders[i]);
    }
    table = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        table[i] = (int*)calloc(sizeof(int),n);
    }

    printf("minimum no. of multiplications needed is %d with position of parenthesis at %d\n", findMinOrder(orders, 0, n-1), table[n-1][0]);
    print(table, n,n);
    printf("position of k: %d\n", table[n-1][0]);
    printf("\n");
}
