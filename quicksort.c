#include"lib.c"
//pivot:high
int partition1(int *arr,int low,int high)
{
	int pi=low-1;
	for(int i=low;i<high;i++)
	{
		if(arr[i]<arr[high])
		{
			pi++;
			swap(arr+i,arr+pi);
		}
	}
	swap(arr+pi+1,arr+high);
	return pi+1;
}
//pivot:low
int partition2(int *arr,int low,int high)
{
	int pi=high+1;
	for(int i=high;i>low;i--)
	{
		if(arr[i]>arr[low])
		{
			pi--;
			swap(arr+pi,arr+i);
		}
	}
	swap(arr+pi-1,arr+low);
	return pi-1;
}
void quicksort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pi=partition2(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	printarr(arr,n);
	quicksort(arr,0,n-1);
	printarr(arr,n);
	return 0;
}