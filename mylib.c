#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"conio.h"
#define MAX 500
void genarr(int *arr,int n,int max)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=rand()%max;
}
void gensortarr(int *arr,int n)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=i;
}
void printarr(int *arr,int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	printf("%d\n",arr[i]);
}
void printarrfromindex(int *arr,int si,int ei)
{
	printf("\n");
	for(int i=si;i<=ei;i++)
	printf("%d\n",arr[i]);
}
void printarrwithindex(int *arr,int n)
{
	printf("\n");
    for(int i=0;i<n;i++)
    printf("%d at %d\n",arr[i],i);
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
