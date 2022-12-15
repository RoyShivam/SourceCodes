#include<stdio.h>
int findnum(int *arr,int n)
{
	int tsum=n*(n+1)/2,rsum=0;
	for(int i=0;i<n-1;i++)
	rsum+=arr[i];
	return tsum-rsum;
}
int main()
{
	int n=10;
	int arr[9]={6,1,2,8,3,4,7,10,5};
	printf("%d\n",findnum(arr,n));
}
