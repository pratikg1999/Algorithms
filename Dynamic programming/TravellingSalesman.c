#include<stdio.h>
#include<stdlib.h>

int G(int h,int n,int **C,int *S,int *P)
{
	int i,d=0,count=0;
	S[h]=0;
	
	for(i=0;i<n;i++)
	if(S[i]==1)
	{
		count++;
		d=1;
	}
	
	if(d==0)
	{
		return C[h][0];
	}
	else
	{
		int min=1000,m_in;
		for(i=0;i<n;i++)
		{
			if(S[i]==1)
			{
				S[i]=0;
				if(min>(C[h][i]+G(i,n,C,S,P)))
				{
					min=(C[h][i]+G(i,n,C,S,P));
					m_in=i;
				}
				S[i]=1;
			}
		}
		S[m_in]=0;
		if(min==(C[h][m_in]+G(m_in,n,C,S,P)))
		P[n-count]=m_in;
		S[m_in]=1;
		return min;
	}
}

void main()
{
	int i,j,n;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	int** C;
	C=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	C[i]=(int*)malloc(n*sizeof(int));
	
	printf("Enter cost adj. matrix:\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&C[i][j]);
	
	int* S;
	S=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	S[i]=1;
	
	int* Path;
	Path=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	Path[i]=0;
	
	int res=G(0,n,C,S,Path);
	
	printf("\nOptimal Path will be:\n");
	for(i=0;i<n;i++)
	printf("%d-",(Path[i]+1));
	printf("1\nProfit of this tour:%d",res);
}
