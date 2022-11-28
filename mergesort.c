#include"lib.c"
//merging of two sorted arrays
void merge(int *arr,int low,int high,int mid)
{
	int i=0,j=0,k=0;
	int n1=(mid-low)+1;
	int n2=high-mid;
	int *arr1=malloc(sizeof(int)*n1);
	int *arr2=malloc(sizeof(int)*n2);
	for(;i<n1;i++)arr1[i]=arr[i+low];
	for(;j<n2;j++)arr2[j]=arr[j+mid+1];
	i=0,j=0;
	while(i<n1&&j<n2)
	{
		if(arr1[i]<arr2[j])arr[low+k]=arr1[i++];
		else arr[low+k]=arr2[j++];
		k++;
	}
	for(;i<n1;i++,k++)arr[low+k]=arr1[i];
	for(;j<n2;j++,k++)arr[low+k]=arr2[j];
	free(arr1);
	free(arr2);
}
//recursively half the array and apply sort
void mergesort(int *arr,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,high,mid);
	}
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	printarr(arr,n);
	mergesort(arr,0,n-1);
	printarr(arr,n);
	return 0;
}