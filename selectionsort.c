#include"lib.c"
void selectionsort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
		if(min!=i)swap(arr+i,arr+min);
	}
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	printarr(arr,n);
	selectionsort(arr,n);
	printarr(arr,n);
}