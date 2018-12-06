#include<stdio.h>
#include<stdlib.h>
/* Helper method to print a matrix*/
void print(int** a, int n){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}
int **c;

main(int argc, char const *argv[])
{
    int n,i,j;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    int *p = (int*)malloc(sizeof(int)*n);
    int *q = (int*)malloc(sizeof(int)*(n+1));
    printf("Enter the frequency of respective nodes: ");
    for(i=0;i<n;i++){
        scanf("%d", &p[i]);
    }
    printf("Enter the frequency of %d external nodes: ", n+1);
    for(i=0;i<n+1;i++){
        scanf("%d", &q[i]);
    }
    int **w=(int**)malloc(sizeof(int*)*(n+1));
    for(i=0;i<n+1;i++){
        w[i] = (int*)malloc(sizeof(int)*(n+1));
        w[i][i]=q[i];
        for(j=i+1;j<(n+1);j++){
            w[i][j] = w[i][j-1] + q[j] + p[j-1];
        }
    }

    c = (int**)malloc(sizeof(int*)*(n+1));          //Cost matrix stores the cost of all the bst
    for(i=0;i<n+1;i++){
        c[i] = (int*)calloc(sizeof(int),(n+1));
    }
    int **r = (int**)malloc(sizeof(int*)*(n+1));    //Stores the node of the bst
    for(i=0;i<n+1;i++){
        r[i] = (int*)calloc(sizeof(int),(n+1));
    }
    int length=0;
    int k=0;
    for(length=1;length<n+1;length++){
        for(i=0;i<n+1-length;i++){
            j= i+length;
            for(k=i+1;k<=j;k++){
                if(c[i][j]==0 || c[i][k-1] + c[k][j]< c[i][j]){
                    c[i][j] = c[i][k-1] + c[k][j];
                    r[i][j] = k;
                }
            }
            c[i][j]+=w[i][j];
        }
    }
    printf("%d", c[0][n]);
    printf("\n");
    return 0;
}
