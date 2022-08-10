#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void genarr(int *arr,int n,int max)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=rand()%max;
}
void sortgenarr(int *arr,int n)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=i;
}
