#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void printarr(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	printf("\n");
}