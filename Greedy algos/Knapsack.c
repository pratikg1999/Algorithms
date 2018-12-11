#include<stdio.h>
#include<stdlib.h>
//Helper method to print a float array
void print(float *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%f ", a[i]);
    }
    printf("\n");
}

//Helper method to print int array
void printInt(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n,M, i,j;       //n = no. of weights, M = knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &M);
    printf("Enter the number of weights: ");
    scanf("%d", &n);
    printf("Enter the weights: ");
    int *p = (int*)malloc(sizeof(int)*n);   //store the profit of the weights
    int *w = (int*)malloc(sizeof(int)*n);   //stores the weights
    for(i=0;i<n;i++){
        scanf("%d", &w[i]);
    }
    printf("Enter the profits: ");
    for(i=0;i<n;i++){
        scanf("%d", &p[i]);
    }

    float *p_per_w = (float*)malloc(sizeof(float)*n); //store the profit per unit weight
    for(i=0;i<n;i++){
        p_per_w[i] = (float)p[i]/w[i];  //calculation of profit per unit weight
    }
    
    printf("Profit per unit weight of the respective weights are:\n");
    print(p_per_w, n);

    //Array to store the priorities of weights
    int *pr = (int*)malloc(sizeof(int)*n); //stores the priority of weights
    for(i=0;i<n;i++){
        float max = 0;
        int index=0; 

        for(j=0;j<n;j++){
            if(p_per_w[j]>max){
                max = p_per_w[j];
                index = j;
            }
        }
        pr[i] = index;
        p_per_w[index] = 0;
    }
    printInt(pr, n);

    int remCapacity = M;    //stores the remaining capciy of the knapsack after inserting weights
    float maxProfit=0;      //maximum profit that can be earned
    float *x = (float*)malloc(sizeof(float)*n); //solution array
    for(i=0;i<n;i++){
        x[i] = 0;   //initialising the the solution with 0
    }

    //Greedy method to solve the problem
    for(i=0;i<n;i++){
        if(w[pr[i]]>remCapacity){   //if the full weight cant be inserted
            x[pr[i]] = ((float)remCapacity)/w[pr[i]]; // a fraction of it is inserted
            maxProfit+=x[pr[i]]*p[pr[i]];
            remCapacity=0;
            break;  //no more weight can be inserted
        }
        x[pr[i]] = 1;   //complete weight is inserted
        remCapacity-=w[pr[i]];
        maxProfit+=p[pr[i]];
        
    }

    print(x, n);
    printf("Max profit: %d\n", maxProfit);

    
    return 0;
}
