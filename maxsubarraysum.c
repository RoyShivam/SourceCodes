#include<stdio.h>
int findmaxsum(int *arr,int n)
{
	int sum=0,rsum=-300000;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<arr[i])sum=arr[i];
		if(sum>rsum)rsum=sum;
	}
	return rsum;
}
int main()
{
	int n=4,arr[4]={-1,-2,-3,-4};
	printf("%d\n",findmaxsum(arr,n));
	return 0;
}