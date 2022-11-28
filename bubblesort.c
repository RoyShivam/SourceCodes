#include"lib.c"
void bubblesort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			swap(arr+j,arr+j+1);
		}
	}
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	printarr(arr,n);
	bubblesort(arr,n);
	printarr(arr,n);
}