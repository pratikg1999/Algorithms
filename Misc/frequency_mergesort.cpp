#include<stdio.h>
 
int mergesort(int *,int,int *,int,int);
int *separate(int *a,int n)
{
    int i,j;
    if(n<=1)
    {
        return a;
    }
    else
    {
    i=n/2;
    j=n-(n/2);
    separate(a,i);
    separate((a+i),j);
    mergesort(a,i,(a+i),j,n);
    }
   
    return 0;
}
int mergesort(int *a,int i,int *m,int j,int n)
{
    int x=0,y=0,s;
     int z=0,c[n];
    while(x<i&&y<j)
    {
        
            if(a[x]>=m[y])
            {
            c[z]=m[y];
            z=z+1;
            y=y+1;
            }
            else
            {
                c[z]=a[x];
                z=z+1;
                x=x+1;
            }
    }
    if(x==i)
    {
        while(y<j)
        {
        c[z]=m[y];
        z=z+1;
        y=y+1;
        }
    }
    else
    {
    if(y==j)
    {
        while(x<i)
        {
        c[z]=a[x];
        z=z+1;
        x=x+1;
        }
    }
    }
    for(s=0;s<i+j;s++)
    {
        a[s]=c[s];
    }
 return 0;   
}
int main()
{
    int n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    int a[n],i;
    
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
 
    separate(a,n);
 
    printf("\nSorted array is \n");
    for (i=0; i < n; i++)
        printf("%d ", a[i]);
        
    int f,count,largest=1,index;
   
    for(i=0;i<n;i++)
    {
        f= a[i];
    	count=1;
    	if(i!=n-1)
    	{
	     	while(f==a[++i])
    		{
    			count++;
			}
	    	if(count>largest)
		   { largest=count;		
              index=i-1;
			 }
	    }
	}   
    printf("\n%d occured maximum times i.e. %d times",a[index],largest);
        
        
    return 0;
}

