#include"lib.c"
//searches the middle element within a sorted list.
int iter_search(int *arr,int s,int e,int sv)
{
	while(s<=e)
	{
		int m=(s+e)/2;
		if(sv==arr[m])return m;
		else if(sv>arr[m])s=m+1;
		else e=m-1;
	}
	return -1;
}
int recur_search(int *arr,int s,int e,int sv){return -1;}
int main()
{
	int n=6;
	int arr[6]={3,5,6,7,8,9};
	printarr(arr,n);
	int i=iter_search(arr,0,n-1,3);
	if(i==-1)printf("searching failed!\n");
	else printf("search value index:%d\n",i);
	return 0;
}