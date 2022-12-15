#include"lib.c"
void sort012_1(int *arr,int n)
{
	int l=0,m=0,h=n-1;
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
void sort012_2(int *arr,int n)
{
	int l=0,h=n-1,i=0;
	while(i<=h)
	{
		if(arr[i]==0)
		{
			swap(arr+l,arr+i);
			l++;
			i++;
		}
		else if(arr[i]==2)
		{
			swap(arr+h,arr+i);
			h--;
		}
		else i++;
	}
}
int main()
{
	int arr[5]={0,2,2,1,0},n=5;
	sort012_2(arr,n);
	printarr(arr,n);
	return 0;
}