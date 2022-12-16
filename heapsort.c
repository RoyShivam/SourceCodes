#include"lib.c"
void maxheapify(int *arr,int n,int i)
{
	int li=2*i+1,ri=li+1,si=i;
	if(li<n&&arr[li]>arr[si])si=li;
	if(ri<n&&arr[ri]>arr[si])si=ri;
	if(si!=i)
	{
		swap(arr+i,arr+si);
		maxheapify(arr,n,si);
	}
}
void minheapify(int *arr,int n,int i)
{
	int li=2*i+1,ri=li+1,si=i;
	if(li<n&&arr[li]<arr[si])si=li;
	if(ri<n&&arr[ri]<arr[si])si=ri;
	if(si!=i)
	{
		swap(arr+i,arr+si);
		minheapify(arr,n,si);
	}	
}
void heapsort(int *arr,int n)
{
	for(int i=n/2;i>=0;i--)maxheapify(arr,n,i);
	for(int i=n-1;i>0;i--)
	{
		swap(arr+0,arr+i);
		maxheapify(arr,i,0);
	}
}
int main()
{
	int arr[]={5,7,3,9,6,8},n=6;
	heapsort(arr,n);
	printarr(arr,n);
	return 0;
}