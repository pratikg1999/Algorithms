#include<stdio.h>
void selectionSort(int a[], int n)
{
    int i, j, min_idx,t;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
 
       t=a[min_idx];
       a[min_idx]=a[i];
       a[i]=t;
    }
}
int main()
{
	 int n;
	 printf("Enter the length of the array :");
	 scanf("%d",&n);
	 
	 int a[n],i,j=n-1,k,key;
	 for(i=0;i<n;i++)
	 {
	 	 printf("No= ");
	 	 scanf("%d",&a[i]);
	 }
	 selectionSort(a,n);
	 printf("Enter the key: ");
	 scanf("%d",&key);
	 
	 for(k=0;k<=n-2;k++)
	 {
	 	for(i=k+1,j=n-1;i<=j;)
	 	{
	 		if(a[k]+a[i]+a[j] == key)
	 		  {
	 		  	printf("Found ");
	 		  	return 1;
				  }  
	 		     
	 	    else if(a[k]+a[i]+a[j] < key)
	 	          i+=1;
	 	    else
	 	        j-=1;
		 }
	 }
	return 0;
}
