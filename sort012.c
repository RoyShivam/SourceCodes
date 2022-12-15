#include"lib.c"
void sort012(int *arr,int n)
{
	int i=0,l=0,m=0,h=n-1;
	while(m<=h)
	{
		if(arr[m]==0)
		{
			swap(arr+l,arr+m);
			l++;m++;
		}
		else if(arr[m]==1)m++;
		else
		{
			swap(arr+h,arr+m);
			h--;
		}
	}
}
int main()
{
	int arr[5]={0,2,2,1,0},n=5;
	sort012(arr,n);
	printarr(arr,n);
	return 0;
}