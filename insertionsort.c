#include"lib.c"
void insertionsort(int *arr,int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			swap(arr+j,arr+j-1);
			else break;
		}
	}
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	printarr(arr,n);
	insertionsort(arr,n);
	printarr(arr,n);
}