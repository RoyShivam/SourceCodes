#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500
void genarr(int *arr,int n,int max)
{
	srand(time(0));
	int i=0;for(i=0;i<n;i++)
	arr[i]=rand()%max;
}
void sortgenarr(int *arr,int n)
{
	srand(time(0));
	int i=0;for(i=0;i<n;i++)
	arr[i]=i;
}
void printarr(int *arr,int n)
{
	int i=0;for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
}
