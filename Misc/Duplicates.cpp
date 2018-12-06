#include<stdio.h>

int main()
{
	 int n;
	 printf("Enter the length of the array:");
	 scanf("%d",&n);
	 
	 int a[n],i;
	 
	 for(i=0;i<n;i++)
	 {
	 	printf("No=");
	 	scanf("%d",&a[i]);
	 }
	 
	 for(i=0;i<n-1;i++)
	 {
	 	if(a[i]==a[i+1])
	 	  printf("Found");
	 }
	 return 0;
}
