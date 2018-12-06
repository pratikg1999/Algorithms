
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void print(int** a, int m, int n){
    int i=0,j=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** add(int**a, int**b, int n){
     int i=0,j=0;
     int **ans =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        ans[i] = (int*)malloc(sizeof(int)*n);
        
    }
     //int ans[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}

int** sub(int**a, int**b, int n){
     int i=0,j=0;

     int **ans =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        ans[i] = (int*)malloc(sizeof(int)*n);
        
    } 
     //int ans[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    return ans;
}

int** formMat(int** a, int r, int c, int n){
    int i,j,k=0;
     int **ans =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        ans[i] = (int*)malloc(sizeof(int)*n);
        
    }
    //int ans[size][size];
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[i][j] = a[r+i][c+j];
        }
    }
    return ans;        
} 

int** add2(int** a, int r1, int c1, int r2, int c2, int n){
    int i,j,k=0;
     int **ans =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        ans[i] = (int*)malloc(sizeof(int)*n);
        
    }
    //int ans[size][size];
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[i][j] = a[r1+i][c1+i] + a[r2+i][c2+i];
        }
    }
    return ans;
}
int** formMatBig(int** a1, int** a2, int** a3, int** a4, int n){
    int i,j,k=0;
     int **ans =(int**)malloc(sizeof(int*)*2*n);
    for(i=0;i<2*n;i++){
        ans[i] = (int*)malloc(sizeof(int)*2*n);
        
    }
    //int ans[2*n][2*n];
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[i][j] = a1[i][j];
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[0+i][n+j] = a2[i][j];
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[n + i][0+j] = a3[i][j];
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans[n+i][n+j] = a4[i][j];
        }
    }
    return ans;
    
}
int** mult(int**a, int**b, int n){
    //printf("In the mult\n");
    int i,j,k; 
     /*int **ans =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        ans[i] = (int*)malloc(sizeof(int)*n);
        
    }*/
    
    //int ans[n][n];
    int **ans;
    if(n==2){
        ans =(int**)malloc(sizeof(int*)*n);
        for(i=0;i<n;i++){
            ans[i] = (int*)malloc(sizeof(int)*n);
        
        }
        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ans[i][j]=0;
                for(k=0;k<n;k++){
                    ans[i][j]+=a[i][k]*b[k][j];
                }
            }
        }*/

        int m1,m2,m3,m4,m5,m6,m7;
        m1 = (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
        m2 = (a[1][0] + a[1][1])*b[0][0];
        m3 = (a[0][0])*(b[0][1] - b[1][1]);
        m4 = a[1][1]*(b[1][0] - b[0][0]);
        m5 = (a[0][0] + a[0][1]) * b[1][1];
        m6 = (a[1][0]-a[0][0])*(b[0][0] + b[0][1]);
        m7 = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);
        /*printf("done calculating ms\n");
        printf("%d\n", m1);
        printf("%d\n", m2);
        printf("%d\n", m3);
        printf("%d\n", m4);
        printf("%d\n", m5);
        printf("%d\n", m6);
        printf("%d\n", m7);*/
        ans[0][0] = m1+m4-m5+m7;
        ans[0][1] = m3+m5;
        ans[1][0] = m2 + m4;
        ans[1][1] = m1+m3-m2+m6;

        return ans;
    }
    //int m1[n/2][n/2],m2[n/2][n/2],m3[n/2][n/2],m4[n/2][n/2],m5[n/2][n/2],m6[n/2][n/2],m7[n/2][n/2];
    int **m1,**m2,**m3,**m4,**m5,**m6,**m7;
    int **a1, **a2, **a3, **a4, **b1, **b2, **b3, **b4;
    printf("Starting to calculate as and bs\n");
    a1 = formMat(a, 0,0,n/2);
    a2 = formMat(a,0,n/2,n/2);
    a3 = formMat(a,n/2 ,0,n/2);
    a4 = formMat(a,n/2,n/2,n/2);
    
    b1 = formMat(b, 0,0,n/2);
    b2 = formMat(b,0,n/2,n/2);
    b3 = formMat(b,n/2 ,0,n/2);
    b4 = formMat(b,n/2,n/2,n/2);
    
    printf("Done calculating as and bs\n");
    
    print(a1, n/2, n/2);
    print(a2, n/2, n/2);
    print(a3, n/2, n/2);
    print(a4, n/2, n/2);

    print(b1, n/2, n/2);
    print(b2, n/2, n/2);
    print(b3, n/2, n/2);
    print(b4, n/2, n/2);
    //m1  = mult(add2(a, 0,0,n/2,n/2,n/2), add(b, 0,0,n/2,n/2,n/2) ,n/2);
    m1 = mult(add(a1,a4,n/2),add(b1,b4,n/2),n/2);
    m2 = mult(add(a3,a4, n/2) , b1, n/2);
    m3 = mult(a1, sub(b2,b4,n/2), n/2);
    m4 = mult(a4, sub(b3,b1,n/2), n/2);
    m5 = mult(add(a1,a2,n/2),b4,n/2);
    m6 = mult(sub(a3,a1,n/2),add(b1,b2,n/2),n/2);
    m7 = mult(sub(a2,a4, n/2),add(b3,b4,n/2),n/2);

    
    
    printf("Done calculating Ms\n");
    print(m1, n/2, n/2);
    print(m2, n/2, n/2);
    print(m3, n/2, n/2);
    print(m4, n/2, n/2);

    print(m5, n/2, n/2);
    print(m6, n/2, n/2);
    print(m7, n/2, n/2);

    
    int **c1,**c2,**c3,**c4;
    c1 = sub(add(m1,add(m4,m7,n/2),n/2),m5,n/2);
    c2 = add(m3,m5,n/2);
    c3 = add(m2,m4,n/2);
    c4 = sub(add(m1,add(m3,m6,n/2),n/2),m2,n/2);
    printf("Done calculating Cs\n");
    print(c1, n/2, n/2);
    print(c2, n/2, n/2);
    print(c3, n/2, n/2);
    print(c4, n/2, n/2);
    ans = formMatBig(c1,c2,c3,c4, n/2);

    return ans;
}
void main(){
    printf("Enter the order of the matrix: ");
    int m,n,i=0, j=0;
    scanf("%d", &m);
    n=m;
    if(log2(m) != (int)log2(m)){
        n = (int)pow(2, (int) log2(m) + 1);
        printf("The order of matrix is changed to %d\n", n);
    }
    printf("Enter the first matrix:\n");
    int **a =(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        a[i] = (int*)malloc(sizeof(int)*n);
        
    }
    int **b = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        b[i] = (int*)malloc(sizeof(int*)*n);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=0;
            if(i<m && j< m)
                scanf("%d", &a[i][j]);
        }   
    }
    printf("Enter the second matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            b[i][j]=0;
            if(i<m && j<m)
                scanf("%d", &b[i][j]);
        }   
    }
    
    print(a,n,n);
    printf("\n");
    print(b,n,n);
    printf("\n");
    int **c = mult(a,b,n);
    print(c,n,n);
    printf("\n");
}
