#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"conio.h"
#include<math.h>
#define MAX 500
void setmatval(int *arr,int i,int j,int c,int v)
{
	*(arr+(i*c+j))=v;
}
int getmatval(int *arr,int i,int j,int c)
{
	return *(arr+(i*c+j));
}
void genarr(int *arr,int n,int max)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=rand()%max;
}
void gennegarr(int *arr,int n,int max)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	arr[i]=(rand()%max)*(rand()%2==0?-1:1);
}
void genmatarr(int *arr,int r,int c,int max)
{
	srand(time(0));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		*(arr+(c*i+j))=rand()%max;
	}
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
void printmatarr(int *arr,int r,int c)
{
	printf("\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		printf("%d  ",*(arr+(c*i+j)));
		printf("\n");
	}
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
    printf("%d:%d\n",arr[i],i);
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void swapc(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
int len(char* c)
{
	int len=-1;
	while(c[++len]!='\0');
	return len;
}
void revstr(char *c,int n)
{
	n=n-1;
	for(int i=0;i<n/2;i++)
	swapc(c+i,c+(n-i-1));
}