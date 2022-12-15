#include<stdio.h>
int minjumps(int *arr,int n)
{
	int jl=0,jc=0;
	while(jl<n-1)
	{
		jl+=arr[jl];
		jc++;
	}
	return jc; 
}
int main()
{
	int arr[6]={1, 4, 3, 2, 6, 7},n=6;
	printf("min jumps:%d\n",minjumps(arr,n));
	return 0;
}